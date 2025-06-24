#include "verilated.h"
#include "verilated_cov.h"
#include <svdpi.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
    extern void write_cov(const char* fname) {
        Verilated::threadContextp()->coveragep()->write("something.dat");
        printf("something.dat");
    }
#ifdef __cplusplus
}
#endif
