// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_ALU);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(31);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_ALU.configure(this, name(), "ALU", "ALU", -12, VerilatedScope::SCOPE_MODULE);
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_ALU);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_ALU.varInsert(__Vfinal,"ACT", &(TOP.ALU__DOT__ACT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"CLK", &(TOP.ALU__DOT__CLK), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"DATA", &(TOP.ALU__DOT__DATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"IMM", &(TOP.ALU__DOT__IMM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"MEM", &(TOP.ALU__DOT__MEM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"MOVI", &(TOP.ALU__DOT__MOVI), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_ALU.varInsert(__Vfinal,"OP", &(TOP.ALU__DOT__OP), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_ALU.varInsert(__Vfinal,"RDY", &(TOP.ALU__DOT__RDY), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"REG_A", &(TOP.ALU__DOT__REG_A), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"REG_B", &(TOP.ALU__DOT__REG_B), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"RST", &(TOP.ALU__DOT__RST), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"VLD", &(TOP.ALU__DOT__VLD), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"mult_req", &(TOP.ALU__DOT__mult_req), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ALU.varInsert(__Vfinal,"mult_res", &(TOP.ALU__DOT__mult_res), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_ALU.varInsert(__Vfinal,"norm_res", &(TOP.ALU__DOT__norm_res), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"operand_A", &(TOP.ALU__DOT__operand_A), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"operand_B", &(TOP.ALU__DOT__operand_B), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ALU.varInsert(__Vfinal,"state_curr", &(TOP.ALU__DOT__state_curr), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_ALU.varInsert(__Vfinal,"state_next", &(TOP.ALU__DOT__state_next), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"ACT", &(TOP.ACT), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"CLK", &(TOP.CLK), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"DATA", &(TOP.DATA), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"IMM", &(TOP.IMM), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM", &(TOP.MEM), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MOVI", &(TOP.MOVI), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,1,0);
        __Vscope_TOP.varInsert(__Vfinal,"OP", &(TOP.OP), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,3,0);
        __Vscope_TOP.varInsert(__Vfinal,"RDY", &(TOP.RDY), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"REG_A", &(TOP.REG_A), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"REG_B", &(TOP.REG_B), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"RST", &(TOP.RST), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"VLD", &(TOP.VLD), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
    }
}
