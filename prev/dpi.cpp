#include "verilated.h"
#include "verilated_cov.h"
#include <svdpi.h>

#ifdef __cplusplus
extern "C" {
#endif
    extern void write_cov() {
        Verilated::threadContextp()->coveragep()->write("coverage.dat");
    }
#ifdef __cplusplus
}
#endif
