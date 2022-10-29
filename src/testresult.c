#include "testresult.h"

void testresult_add_error(testresult_t* testresult, char* error) {
    if(testresult->errors_size <= testresult->num_errors) {
        // double errors size if we are out of space
        testresult->errors = realloc(testresult->errors, 2 * testresult->errors_size * sizeof(testresult->errors[0]));
        testresult->errors_size *= 2;
    }

    int i = testresult->num_errors++;
    testresult->errors[i] = malloc(strlen(error) + 1);
    strcpy(testresult->errors[i], error);
}

void testresult_summarize(testresult_t* testresult) {
    
    if(testresult->num_errors == 0) {
        printf("All assertions passed\n\n");
        return;
    }

    printf("Failed assertions:\n");
    for(int i = 0; i < testresult->num_errors; i++) {
        fputs(testresult->errors[i], stderr);
    }

    fputs("\n", stderr);
}