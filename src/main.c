#include "assertions.h"
#include "testgroup.h"

#include <stdio.h>
#include <stdlib.h>

#define NUM_TESTS 3

int add(int x, int y) {
    return x + y;
}

void testTwoPlusTwo(testresult_t* testresult) {
    assertEqualsInt(add(2, 2), 4, testresult);
}

void testNegative(testresult_t* testresult) {
    assertEqualsInt(add(-3, 6), 3, testresult);
}

void testFail(testresult_t* testresult) {
    assertEqualsInt(add(2, 3), 4, testresult);
}

int main(void) {
    testgroup_t testgroup;
    testgroup.tests = malloc(NUM_TESTS * sizeof(testcase_t *));
    testgroup.num_tests = NUM_TESTS;
    testgroup.tests_size = NUM_TESTS;

    testresult_t test_one_result;
    test_one_result.num_errors = 0;
    test_one_result.errors_size = 0;

    testresult_t test_two_result;
    test_two_result.num_errors = 0;
    test_two_result.errors_size = 0;

    testresult_t test_three_result;
    test_three_result.num_errors = 0;
    test_three_result.errors_size = 0;

    testcase_t test_one;
    test_one.name = "Test Two Plus Two";
    test_one.test_func = testTwoPlusTwo;
    test_one.testresult = &test_one_result;

    testcase_t test_two;
    test_two.name = "Test Negative";
    test_two.test_func = testNegative;
    test_two.testresult = &test_two_result;

    testcase_t test_three;
    test_three.name = "Test Fail";
    test_three.test_func = testFail;
    test_three.testresult = &test_three_result;

    testgroup.tests[0] = &test_one;
    testgroup.tests[1] = &test_two;
    testgroup.tests[2] = &test_three;

    testgroup_run(&testgroup);

    testgroup_summarize(&testgroup);

    return 0;
}