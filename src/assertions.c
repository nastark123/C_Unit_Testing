#include "assertions.h"

int assertEqualsChar(char actual, char expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual char \"%c\" does not match expected char \"%c\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsShort(short actual, short expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual short \"%hd\" does not match expected short \"%hd\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsInt(int actual, int expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual int \"%d\" does not match expected int \"%d\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsLong(long actual, long expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual long \"%ld\" does not match expected long \"%ld\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsFloat(float actual, float expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual float \"%f\" does not match expected float \"%f\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsDouble(double actual, double expected, testresult_t* testresult) {
    char str[256];

    if(actual != expected) {
        sprintf(str, "actual double \"%lf\" does not match expected double \"%lf\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsStr(char* actual, char* expected, testresult_t* testresult) {
    char str[256];

    if(strcmp(actual, expected) != 0) {
        // TODO make this memory safe
        sprintf(str, "actual double \"%s\" does not match expected double \"%s\"\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;
}

int assertEqualsMem(void* actual, int actual_size, void* expected, int expected_size, testresult_t* testresult) {
    char str[256];

    if(actual_size != expected_size) {
        sprintf(str, "size of actual memory block starting at %p does not match size of expected memory block starting at %p\n", actual, expected);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    int i;
    for(i = 0; i < actual_size; i++) {
        if(((char *) actual)[i] != ((char *) expected)[i]) break;
    }

    if(i != actual_size) {
        sprintf(str, "contents of actual memory block starting at %p does not match expected memory block at %p (first mismatch at 0x%X)\n", actual, expected, i);
        testresult_add_error(testresult, str);
        fputs(str, stderr);
        return -1;
    }

    return 0;

}