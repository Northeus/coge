// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_arithmetic_unit);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(29);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_arithmetic_unit.configure(this, name(), "arithmetic_unit", "arithmetic_unit", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_arithmetic_unit);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"ACT", &(TOP.ACT), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"CLK", &(TOP.CLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"DATA", &(TOP.DATA), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"DATA_VALID", &(TOP.DATA_VALID), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"IMM", &(TOP.IMM), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM", &(TOP.MEM), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MOVI", &(TOP.MOVI), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"OP_CODE", &(TOP.OP_CODE), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"REG_A", &(TOP.REG_A), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"REG_B", &(TOP.REG_B), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"RST", &(TOP.RST), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"ACT", &(TOP.arithmetic_unit__DOT__ACT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"CLK", &(TOP.arithmetic_unit__DOT__CLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"DATA", &(TOP.arithmetic_unit__DOT__DATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"DATA_VALID", &(TOP.arithmetic_unit__DOT__DATA_VALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"IMM", &(TOP.arithmetic_unit__DOT__IMM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"MEM", &(TOP.arithmetic_unit__DOT__MEM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"MOVI", &(TOP.arithmetic_unit__DOT__MOVI), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"OP_CODE", &(TOP.arithmetic_unit__DOT__OP_CODE), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"REG_A", &(TOP.arithmetic_unit__DOT__REG_A), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"REG_B", &(TOP.arithmetic_unit__DOT__REG_B), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"RST", &(TOP.arithmetic_unit__DOT__RST), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"mul_busy", &(TOP.arithmetic_unit__DOT__mul_busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"mul_counter", &(TOP.arithmetic_unit__DOT__mul_counter), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"operand_a", &(TOP.arithmetic_unit__DOT__operand_a), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_arithmetic_unit.varInsert(__Vfinal,"operand_b", &(TOP.arithmetic_unit__DOT__operand_b), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
    }
}
