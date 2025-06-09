// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(CLK,0,0);
    VL_IN8(RST,0,0);
    VL_IN8(ACT,0,0);
    VL_IN8(OP_CODE,1,0);
    VL_IN8(MOVI,1,0);
    VL_OUT8(DATA_VALID,0,0);
    CData/*0:0*/ arithmetic_unit__DOT__CLK;
    CData/*0:0*/ arithmetic_unit__DOT__RST;
    CData/*0:0*/ arithmetic_unit__DOT__ACT;
    CData/*1:0*/ arithmetic_unit__DOT__OP_CODE;
    CData/*1:0*/ arithmetic_unit__DOT__MOVI;
    CData/*0:0*/ arithmetic_unit__DOT__DATA_VALID;
    CData/*1:0*/ arithmetic_unit__DOT__mul_counter;
    CData/*0:0*/ arithmetic_unit__DOT__mul_busy;
    CData/*0:0*/ arithmetic_unit__DOT____Vtogcov__CLK;
    CData/*0:0*/ arithmetic_unit__DOT____Vtogcov__RST;
    CData/*0:0*/ arithmetic_unit__DOT____Vtogcov__ACT;
    CData/*1:0*/ arithmetic_unit__DOT____Vtogcov__OP_CODE;
    CData/*1:0*/ arithmetic_unit__DOT____Vtogcov__MOVI;
    CData/*0:0*/ arithmetic_unit__DOT____Vtogcov__DATA_VALID;
    CData/*1:0*/ arithmetic_unit__DOT____Vtogcov__mul_counter;
    CData/*0:0*/ arithmetic_unit__DOT____Vtogcov__mul_busy;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__RST__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(REG_A,31,0);
    VL_IN(REG_B,31,0);
    VL_IN(MEM,31,0);
    VL_IN(IMM,31,0);
    VL_OUT(DATA,31,0);
    IData/*31:0*/ arithmetic_unit__DOT__REG_A;
    IData/*31:0*/ arithmetic_unit__DOT__REG_B;
    IData/*31:0*/ arithmetic_unit__DOT__MEM;
    IData/*31:0*/ arithmetic_unit__DOT__IMM;
    IData/*31:0*/ arithmetic_unit__DOT__DATA;
    IData/*31:0*/ arithmetic_unit__DOT__operand_a;
    IData/*31:0*/ arithmetic_unit__DOT__operand_b;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__REG_A;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__REG_B;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__MEM;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__IMM;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__DATA;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__operand_a;
    IData/*31:0*/ arithmetic_unit__DOT____Vtogcov__operand_b;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
