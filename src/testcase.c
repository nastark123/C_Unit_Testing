#include "testcase.h"

void testcase_execute(testcase_t* testcase) {
    testcase->test_func(testcase->testresult);
}

void testcase_summarize(testcase_t* testcase) {
    fprintf(stderr, "Summary for test \"%s\":\n", testcase->name);
    testresult_summarize(testcase->testresult);
}