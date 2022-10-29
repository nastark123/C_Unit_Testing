#include "testgroup.h"

void testgroup_run(testgroup_t* testgroup) {
    fputs("================================================================================\n\n", stderr);
    fputs("Beginning testgroup execution...\n", stderr);
    for(int i = 0; i < testgroup->num_tests; i++) {
        testcase_execute(testgroup->tests[i]);
    }
    fputs("testgroup execution finished\n\n", stderr);
    fputs("================================================================================\n\n", stderr);
}

void testgroup_add(testgroup_t* testgroup, testcase_t* testcase) {
    if(testgroup->tests_size <= testgroup->num_tests) {
        testgroup->tests = realloc(testgroup->tests, 2 * testgroup->tests_size * sizeof(testgroup->tests[0]));
        testgroup->tests_size *= 2;
    }

    int i = testgroup->num_tests++;
    testgroup->tests[i] = testcase;
}

void testgroup_summarize(testgroup_t* testgroup) {
    fputs("================================================================================\n\n", stderr);
    fputs("Summary of testgroup:\n", stderr);
    for(int i = 0; i < testgroup->num_tests; i++) {
        testcase_summarize(testgroup->tests[i]);
    }
    fputs("================================================================================\n\n", stderr);
}