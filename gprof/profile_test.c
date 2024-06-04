#include "profile_test.h"

static void test1(void) {
    for(int i=0; i<50000; i++) {
        __asm("nop");
    }
}

static void test2(void) {
    for(int i=0; i<100000; i++) {
        __asm("nop");
    }
}

void gprof_test(void) {
    for(int i=0; i<50; i++) {
        test1();
        test2();
    }
}