#ifndef TESTGROUP_H
#define TESTGROUP_H

#include "testcase.h"

typedef struct {
    testcase_t** tests; // tests in the test group
    int tests_size; // size of tests array
    int num_tests; // number of tests in the group
} testgroup_t;

void testgroup_run(testgroup_t* testgroup);

void testgroup_add(testgroup_t* testgroup, testcase_t* testcase);

void testgroup_summarize(testgroup_t* testgroup);

#endif