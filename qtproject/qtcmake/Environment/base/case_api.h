#pragma once

#include "list"
#include "string"
#include "set"
#include "string.h"
#include "case_def.h"

using namespace std;

struct CASE_TASK {
    bool confirm_first;
    bool force_test;
    string case_report_file;
    list<string> case_list;
    set<string> unknown_case_list;
};

int parseArgument(int argc, char **argv, CASE_TASK &task);
int loadCaseReport(const char *strCaseReport);
int saveCaseReport(const char *strCaseReport);
int setCaseSucceed(const char *strCaseId);
int setCaseFailed(const char *strCaseId);
int clearCaseTask(CASE_TASK &task);
int runCaseTask(CASE_TASK &task);
