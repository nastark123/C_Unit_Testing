#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include "testresult.h"

#include <stdio.h>
#include <string.h>

int assertEqualsChar(char actual, char expected, testresult_t* testresult);

int assertEqualsShort(short actual, short expected, testresult_t* testresult);

int assertEqualsInt(int actual, int expected, testresult_t* testresult);

int assertEqualsLong(long actual, long expected, testresult_t* testresult);

int assertEqualsFloat(float actual, float expected, testresult_t* testresult);

int assertEqualsDouble(double actual, double expected, testresult_t* testresult);

int assertEqualsStr(char* actual, char* expected, testresult_t* testresult);

int assertEqualsMem(void* actual, int actual_size, void* expected, int expected_size, testresult_t* testresult);

#endif