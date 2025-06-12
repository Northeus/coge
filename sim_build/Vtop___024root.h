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
    VL_IN8(OP,3,0);
    VL_IN8(MOVI,1,0);
    VL_OUT8(RDY,0,0);
    VL_OUT8(VLD,0,0);
    CData/*0:0*/ ALU__DOT__CLK;
    CData/*0:0*/ ALU__DOT__RST;
    CData/*0:0*/ ALU__DOT__ACT;
    CData/*3:0*/ ALU__DOT__OP;
    CData/*1:0*/ ALU__DOT__MOVI;
    CData/*0:0*/ ALU__DOT__RDY;
    CData/*0:0*/ ALU__DOT__VLD;
    CData/*1:0*/ ALU__DOT__state_curr;
    CData/*1:0*/ ALU__DOT__state_next;
    CData/*0:0*/ ALU__DOT__mult_req;
    CData/*0:0*/ ALU__DOT____Vtogcov__CLK;
    CData/*0:0*/ ALU__DOT____Vtogcov__RST;
    CData/*0:0*/ ALU__DOT____Vtogcov__ACT;
    CData/*3:0*/ ALU__DOT____Vtogcov__OP;
    CData/*1:0*/ ALU__DOT____Vtogcov__MOVI;
    CData/*0:0*/ ALU__DOT____Vtogcov__RDY;
    CData/*0:0*/ ALU__DOT____Vtogcov__VLD;
    CData/*1:0*/ ALU__DOT____Vtogcov__state_curr;
    CData/*1:0*/ ALU__DOT____Vtogcov__state_next;
    CData/*0:0*/ ALU__DOT____Vtogcov__mult_req;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(REG_A,31,0);
    VL_IN(REG_B,31,0);
    VL_IN(MEM,31,0);
    VL_IN(IMM,31,0);
    VL_OUT(DATA,31,0);
    IData/*31:0*/ ALU__DOT__REG_A;
    IData/*31:0*/ ALU__DOT__REG_B;
    IData/*31:0*/ ALU__DOT__MEM;
    IData/*31:0*/ ALU__DOT__IMM;
    IData/*31:0*/ ALU__DOT__DATA;
    IData/*31:0*/ ALU__DOT__operand_A;
    IData/*31:0*/ ALU__DOT__operand_B;
    IData/*31:0*/ ALU__DOT__norm_res;
    IData/*31:0*/ ALU__DOT____Vtogcov__REG_A;
    IData/*31:0*/ ALU__DOT____Vtogcov__REG_B;
    IData/*31:0*/ ALU__DOT____Vtogcov__MEM;
    IData/*31:0*/ ALU__DOT____Vtogcov__IMM;
    IData/*31:0*/ ALU__DOT____Vtogcov__DATA;
    IData/*31:0*/ ALU__DOT____Vtogcov__operand_A;
    IData/*31:0*/ ALU__DOT____Vtogcov__operand_B;
    IData/*31:0*/ ALU__DOT____Vtogcov__norm_res;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ ALU__DOT__mult_res;
    QData/*63:0*/ ALU__DOT____Vtogcov__mult_res;
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
