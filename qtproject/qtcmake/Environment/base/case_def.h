#pragma once

#include "string.h"
#include "map"
#include "string"

#define TEST_CASE_API

enum CASE_RESULT {
    CASE_INITED = 0,
    CASE_SUCCEED = 1,
    CASE_FAILED = 2,
};

typedef void (*SHOW_CASE_INFORMATION_FUNC)();
typedef void (*RUN_CASE_FUNC)();

struct CASE_FUNCTION_ITEM {
    const char *m_caseFuncName;
    RUN_CASE_FUNC m_mainFunc;
    CASE_FUNCTION_ITEM *m_pNextCaseFunction;
    static CASE_FUNCTION_ITEM *m_pHeadCaseFunction;
    static CASE_FUNCTION_ITEM *findFunctionItem(const char *m_strFuncName) {
        CASE_FUNCTION_ITEM *pCurCaseFunction = CASE_FUNCTION_ITEM::m_pHeadCaseFunction;
        while (pCurCaseFunction != nullptr) {
            if (strcmp(m_strFuncName, pCurCaseFunction->m_caseFuncName) == 0) {
                return pCurCaseFunction;
            } else {
                pCurCaseFunction = pCurCaseFunction->m_pNextCaseFunction;
            }
        }
        return pCurCaseFunction;
    }
};

struct CONNECT_FUNCTION {
    CONNECT_FUNCTION(CASE_FUNCTION_ITEM *pItem) {
        pItem->m_pNextCaseFunction = CASE_FUNCTION_ITEM::m_pHeadCaseFunction;
        CASE_FUNCTION_ITEM::m_pHeadCaseFunction = pItem;
    }
};

struct CASE_ITEM {
    const char *m_strCaseId;
    int m_intCaseResult;
    const char *m_caseFuncName;
    SHOW_CASE_INFORMATION_FUNC m_infoFunc;
    CASE_ITEM *m_pNextCase;
    static CASE_ITEM *m_pHeadCase;
    static CASE_ITEM *findCaseItem(const char *strCaseId) {
        CASE_ITEM *pCurCase = CASE_ITEM::m_pHeadCase;
        while (pCurCase != nullptr) {
            if (strcmp(strCaseId, pCurCase->m_strCaseId) == 0) {
                return pCurCase;
            } else {
                pCurCase = pCurCase->m_pNextCase;
            }
        }
        return pCurCase;
    }
};

struct CONNECT_CASE {
    CONNECT_CASE(CASE_ITEM *pItem) {
        pItem->m_pNextCase = CASE_ITEM::m_pHeadCase;
        CASE_ITEM::m_pHeadCase = pItem;
    }
};

#define REGIST_CASE_FUNCTION(main_func)                                    \
    CASE_FUNCTION_ITEM main_func##item = {#main_func, main_func, nullptr}; \
    CONNECT_FUNCTION main_func##connect(&main_func##item);

#define REGIST_CASE(case_id, main_func, info_func)                       \
    CASE_ITEM case_id##item = {#case_id, CASE_INITED, #main_func, info_func, nullptr}; \
    CONNECT_CASE case_id##connect(&case_id##item);
