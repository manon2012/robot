#include "case_api.h"
#include "test_base.h"
#include "stdio.h"
#include "fstream"

CASE_FUNCTION_ITEM *CASE_FUNCTION_ITEM::m_pHeadCaseFunction = nullptr;
CASE_ITEM *CASE_ITEM::m_pHeadCase = nullptr;

int parseArgument(int argc, char **argv, CASE_TASK &task) {
    int case_type = 0;  // 0: 单个测试用例, 1:  连续测试列表
    task.case_list.clear();
    task.case_report_file = "./report.cr";
    task.force_test = false;
    task.confirm_first = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-case") == 0 && i < argc - 1) {
            if (case_type == 0) {
                task.case_list.clear();
                task.case_list.push_back(argv[i + 1]);
            }
            i++;
            continue;
        }
        if (strcmp(argv[i], "-casefile") == 0 && i < argc - 1) {
            list<string> caseList;
            std::ifstream casefile(argv[i + 1]);
            if (casefile.is_open()) {
                std::string line;
                while (std::getline(casefile, line)) {
                    if (line.size() >= 1 && line[0] != '!') {
                        caseList.push_back(line);
                    }
                }
                casefile.close();
            }
            if (caseList.empty() == false) {
                if (case_type == 0) {
                    case_type = 1;
                    task.case_list = caseList;
                } else {
                    task.case_list = caseList;
                }
            }
            i++;
            continue;
        }
        if (strcmp(argv[i], "-report") == 0 && i < argc - 1) {
            task.case_report_file = argv[i + 1];
            i++;
            continue;
        }
        if (strcmp(argv[i], "-force") == 0) {
            task.force_test = true;
            continue;
        }
        if (strcmp(argv[i], "-confirm") == 0) {
            task.confirm_first = true;
            continue;
        }
    }
    return 0;
}

int loadCaseReport(const char *strCaseReport) {
    std::ifstream casefile(strCaseReport);
    if (casefile.is_open()) {
        std::string line;
        while (std::getline(casefile, line)) {
            size_t pos = line.find('=');
            if (pos != line.npos) {
                string case_name = line.substr(0, pos);
                string case_result = line.substr(pos + 1);
                CASE_ITEM *pCaseItem = CASE_ITEM::findCaseItem(case_name.c_str());
                if (pCaseItem != nullptr) {
                    if (case_result == "CASE_SUCCEED")
                        pCaseItem->m_intCaseResult = CASE_SUCCEED;
                    else if (case_result == "CASE_FAILED")
                        pCaseItem->m_intCaseResult = CASE_FAILED;
                    else
                        pCaseItem->m_intCaseResult = CASE_INITED;
                }
            }
        }
        casefile.close();
    }
    return 0;
}

int saveCaseReport(const char *strCaseReport) {
    ofstream of(strCaseReport);
    if (of.is_open()) {
        CASE_ITEM *pCaseItem = CASE_ITEM::m_pHeadCase;
        while (pCaseItem != nullptr) {
            string strCaseResult;
            if (pCaseItem->m_intCaseResult == CASE_SUCCEED) {
                strCaseResult = "CASE_SUCCEED";
            } else if (pCaseItem->m_intCaseResult == CASE_FAILED) {
                strCaseResult = "CASE_FAILED";
            } else {
                strCaseResult = "CASE_INITED";
            }
            of << pCaseItem->m_strCaseId << "=" << strCaseResult << endl;
            pCaseItem = pCaseItem->m_pNextCase;
        }
        of.close();
    }
    return 0;
}

int setCaseSucceed(const char *strCaseId) {
    CASE_ITEM *pCaseItem = CASE_ITEM::findCaseItem(strCaseId);
    if (pCaseItem != nullptr) {
        pCaseItem->m_intCaseResult = CASE_SUCCEED;
    }
    return 0;
}

int setCaseFailed(const char *strCaseId) {
    CASE_ITEM *pCaseItem = CASE_ITEM::findCaseItem(strCaseId);
    if (pCaseItem != nullptr) {
        pCaseItem->m_intCaseResult = CASE_FAILED;
    }
    return 0;
}

int clearCaseTask(CASE_TASK &task) {
    list<string>::iterator name_it = task.case_list.begin();
    while (name_it != task.case_list.end()) {
        CASE_ITEM *pCaseItem = CASE_ITEM::findCaseItem(name_it->c_str());
        if (pCaseItem != nullptr) {
            pCaseItem->m_intCaseResult = CASE_INITED;
        }
        name_it++;
    }
    saveCaseReport(task.case_report_file.c_str());
    return 0;
}

int runCaseTask(CASE_TASK &task) {
    list<string>::iterator name_it = task.case_list.begin();
    while (name_it != task.case_list.end()) {
        CASE_ITEM *pCaseItem = CASE_ITEM::findCaseItem(name_it->c_str());
        if (pCaseItem == nullptr) {
            task.unknown_case_list.insert(*name_it);
        } else {
            if (pCaseItem->m_intCaseResult == CASE_SUCCEED) {
                printf("测试用例%s已具备测试结果[CASE_SUCCEED], 将被跳过.\n", name_it->c_str());
            } else if (pCaseItem->m_intCaseResult == CASE_FAILED) {
                printf("测试用例%s已具备测试结果[CASE_FAILED], 将被跳过.\n", name_it->c_str());
            } else {
                CASE_FUNCTION_ITEM *pFunctionItem = CASE_FUNCTION_ITEM::findFunctionItem(pCaseItem->m_caseFuncName);
                if (pFunctionItem == nullptr || pFunctionItem->m_mainFunc == nullptr) {
                    printf("没有为测试用例%s实现测试方法, 用例无法执行:\n", name_it->c_str());
                } else {
                    bool should_execute_case = true;
                    if (task.confirm_first == true) {
                        if (pCaseItem->m_infoFunc == nullptr) {
                            printf("是否希望执行测试用例%s, 测试信息:\n空", name_it->c_str());
                        } else {
                            printf("是否希望执行测试用例%s, 测试信息:\n", name_it->c_str());
                            (*pCaseItem->m_infoFunc)();
                        }
                        if (pCaseItem->m_caseFuncName) printf("\n[是-y, 否-n]:");
                        if (read_input(nullptr) == 'n') {
                            should_execute_case = false;
                        }
                    }
                    if (should_execute_case == false) {
                        printf("用户选择跳过测试用例%s.\n", name_it->c_str());
                    } else {
                        (*pFunctionItem->m_mainFunc)();
                        if (pCaseItem->m_intCaseResult == CASE_SUCCEED) {
                            printf("测试用例%s执行成功.\n", name_it->c_str());
                            saveCaseReport(task.case_report_file.c_str());
                        } else if (pCaseItem->m_intCaseResult == CASE_FAILED) {
                            printf("测试用例%s执行失败.\n", name_it->c_str());
                            saveCaseReport(task.case_report_file.c_str());
                        } else {
                            printf("测试用例%s执行结果未上报, 测试终止.\n", name_it->c_str());
                            return 0;
                        }
                    }
                }
            }
        }
        name_it++;
    }
    set<string>::iterator unknown_it = task.unknown_case_list.begin();
    while (unknown_it != task.unknown_case_list.end()) {
        printf("测试用例%s不识别.\n", unknown_it->c_str());
        unknown_it++;
    }
    return 0;
}
