#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** errors;
    int errors_size;
    int num_errors;
} testresult_t;

void testresult_add_error(testresult_t* testresult, char* error);

void testresult_summarize(testresult_t* testresult);

#endif