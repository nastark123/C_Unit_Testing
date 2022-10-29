#ifndef TESTCASE_H
#define TESTCASE_H

#include "testresult.h"

typedef struct {
    char* name;
    void (*test_func)(testresult_t*);
    testresult_t* testresult;
} testcase_t;

void testcase_execute(testcase_t* testcase);

void testcase_summarize(testcase_t* testcase);

#endif