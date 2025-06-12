// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*1:0*/, 16> Vtop__ConstPool__TABLE_h09c48e33_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.ALU__DOT__CLK = vlSelfRef.CLK;
    vlSelfRef.ALU__DOT__RST = vlSelfRef.RST;
    vlSelfRef.ALU__DOT__ACT = vlSelfRef.ACT;
    vlSelfRef.ALU__DOT__OP = vlSelfRef.OP;
    vlSelfRef.ALU__DOT__MOVI = vlSelfRef.MOVI;
    vlSelfRef.ALU__DOT__REG_A = vlSelfRef.REG_A;
    vlSelfRef.ALU__DOT__REG_B = vlSelfRef.REG_B;
    vlSelfRef.ALU__DOT__MEM = vlSelfRef.MEM;
    vlSelfRef.ALU__DOT__IMM = vlSelfRef.IMM;
    if (((IData)(vlSelfRef.CLK) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__CLK))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.ALU__DOT____Vtogcov__CLK = vlSelfRef.CLK;
    }
    if (((IData)(vlSelfRef.RST) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__RST))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.ALU__DOT____Vtogcov__RST = vlSelfRef.RST;
    }
    if (((IData)(vlSelfRef.ACT) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__ACT))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelfRef.ALU__DOT____Vtogcov__ACT = vlSelfRef.ACT;
    }
    if ((1U & ((IData)(vlSelfRef.MOVI) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__MOVI)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelfRef.ALU__DOT____Vtogcov__MOVI = ((2U 
                                                & (IData)(vlSelfRef.ALU__DOT____Vtogcov__MOVI)) 
                                               | (1U 
                                                  & (IData)(vlSelfRef.MOVI)));
    }
    if ((2U & ((IData)(vlSelfRef.MOVI) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__MOVI)))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelfRef.ALU__DOT____Vtogcov__MOVI = ((1U 
                                                & (IData)(vlSelfRef.ALU__DOT____Vtogcov__MOVI)) 
                                               | (2U 
                                                  & (IData)(vlSelfRef.MOVI)));
    }
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__state_curr) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlSelfRef.ALU__DOT____Vtogcov__state_curr = 
            ((2U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)) 
             | (1U & (IData)(vlSelfRef.ALU__DOT__state_curr)));
    }
    if ((2U & ((IData)(vlSelfRef.ALU__DOT__state_curr) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlSelfRef.ALU__DOT____Vtogcov__state_curr = 
            ((1U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)) 
             | (2U & (IData)(vlSelfRef.ALU__DOT__state_curr)));
    }
    if ((1U & ((IData)(vlSelfRef.OP) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelfRef.ALU__DOT____Vtogcov__OP = ((0xeU 
                                              & (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)) 
                                             | (1U 
                                                & (IData)(vlSelfRef.OP)));
    }
    if ((2U & ((IData)(vlSelfRef.OP) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelfRef.ALU__DOT____Vtogcov__OP = ((0xdU 
                                              & (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)) 
                                             | (2U 
                                                & (IData)(vlSelfRef.OP)));
    }
    if ((4U & ((IData)(vlSelfRef.OP) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelfRef.ALU__DOT____Vtogcov__OP = ((0xbU 
                                              & (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)) 
                                             | (4U 
                                                & (IData)(vlSelfRef.OP)));
    }
    if ((8U & ((IData)(vlSelfRef.OP) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelfRef.ALU__DOT____Vtogcov__OP = ((7U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__OP)) 
                                             | (8U 
                                                & (IData)(vlSelfRef.OP)));
    }
    vlSelfRef.ALU__DOT__mult_req = (2U == (IData)(vlSelfRef.OP));
    if ((1U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffffeU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (1U 
                                                   & vlSelfRef.REG_A));
    }
    if ((2U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffffdU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (2U 
                                                   & vlSelfRef.REG_A));
    }
    if ((4U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffffbU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (4U 
                                                   & vlSelfRef.REG_A));
    }
    if ((8U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffff7U 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (8U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x10U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffffefU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x10U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x20U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffffdfU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x20U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x40U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffffbfU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x40U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x80U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffff7fU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x80U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x100U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffeffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x100U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x200U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffdffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x200U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x400U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffffbffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x400U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x800U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffff7ffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x800U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x1000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffefffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x1000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x2000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffdfffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x2000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x4000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffffbfffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x4000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x8000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffff7fffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x8000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x10000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffeffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x10000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x20000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffdffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x20000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x40000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfffbffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x40000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x80000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfff7ffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x80000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x100000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffefffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x100000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x200000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffdfffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x200000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x400000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xffbfffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x400000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x800000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xff7fffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x800000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x1000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfeffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x1000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x2000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfdffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x2000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x4000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xfbffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x4000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x8000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xf7ffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x8000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x10000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xefffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x10000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x20000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[38]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xdfffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x20000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((0x40000000U & (vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0xbfffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x40000000U 
                                                   & vlSelfRef.REG_A));
    }
    if (((vlSelfRef.REG_A ^ vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[40]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_A = ((0x7fffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_A) 
                                                | (0x80000000U 
                                                   & vlSelfRef.REG_A));
    }
    if ((1U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffffeU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (1U 
                                                   & vlSelfRef.REG_B));
    }
    if ((2U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffffdU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (2U 
                                                   & vlSelfRef.REG_B));
    }
    if ((4U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffffbU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (4U 
                                                   & vlSelfRef.REG_B));
    }
    if ((8U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffff7U 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (8U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x10U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffffefU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x10U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x20U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffffdfU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x20U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x40U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffffbfU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x40U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x80U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffff7fU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x80U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x100U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffeffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x100U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x200U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffdffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x200U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x400U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffffbffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x400U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x800U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffff7ffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x800U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x1000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffefffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x1000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x2000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffdfffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x2000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x4000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffffbfffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x4000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x8000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffff7fffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x8000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x10000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffeffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x10000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x20000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffdffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x20000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x40000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfffbffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x40000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x80000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfff7ffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x80000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x100000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffefffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x100000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x200000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffdfffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x200000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x400000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xffbfffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x400000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x800000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xff7fffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x800000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x1000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfeffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x1000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x2000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfdffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x2000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x4000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xfbffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x4000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x8000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xf7ffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x8000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x10000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xefffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x10000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x20000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xdfffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x20000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((0x40000000U & (vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0xbfffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x40000000U 
                                                   & vlSelfRef.REG_B));
    }
    if (((vlSelfRef.REG_B ^ vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[72]);
        vlSelfRef.ALU__DOT____Vtogcov__REG_B = ((0x7fffffffU 
                                                 & vlSelfRef.ALU__DOT____Vtogcov__REG_B) 
                                                | (0x80000000U 
                                                   & vlSelfRef.REG_B));
    }
    if ((1U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffffeU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (1U 
                                                 & vlSelfRef.MEM));
    }
    if ((2U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffffdU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (2U 
                                                 & vlSelfRef.MEM));
    }
    if ((4U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffffbU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (4U 
                                                 & vlSelfRef.MEM));
    }
    if ((8U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffff7U 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (8U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x10U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffffefU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x10U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x20U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffffdfU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x20U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x40U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffffbfU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x40U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x80U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffff7fU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x80U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x100U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffeffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x100U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x200U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffdffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x200U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x400U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffffbffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x400U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x800U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffff7ffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x800U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x1000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffefffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x1000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x2000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffdfffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x2000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x4000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffffbfffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x4000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x8000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffff7fffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x8000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x10000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffeffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x10000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x20000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffdffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x20000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x40000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfffbffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x40000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x80000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfff7ffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x80000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x100000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffefffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x100000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x200000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffdfffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x200000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x400000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xffbfffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x400000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x800000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xff7fffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x800000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x1000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfeffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x1000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x2000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfdffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x2000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x4000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xfbffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x4000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x8000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xf7ffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x8000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x10000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xefffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x10000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x20000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[102]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xdfffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x20000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((0x40000000U & (vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0xbfffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x40000000U 
                                                 & vlSelfRef.MEM));
    }
    if (((vlSelfRef.MEM ^ vlSelfRef.ALU__DOT____Vtogcov__MEM) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[104]);
        vlSelfRef.ALU__DOT____Vtogcov__MEM = ((0x7fffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__MEM) 
                                              | (0x80000000U 
                                                 & vlSelfRef.MEM));
    }
    if ((1U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffffeU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (1U 
                                                 & vlSelfRef.IMM));
    }
    if ((2U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffffdU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (2U 
                                                 & vlSelfRef.IMM));
    }
    if ((4U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffffbU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (4U 
                                                 & vlSelfRef.IMM));
    }
    if ((8U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffff7U 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (8U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x10U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffffefU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x10U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x20U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffffdfU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x20U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x40U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffffbfU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x40U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x80U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffff7fU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x80U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x100U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffeffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x100U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x200U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffdffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x200U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x400U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffffbffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x400U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x800U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffff7ffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x800U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x1000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffefffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x1000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x2000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffdfffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x2000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x4000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffffbfffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x4000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x8000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffff7fffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x8000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x10000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffeffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x10000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x20000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffdffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x20000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x40000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfffbffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x40000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x80000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfff7ffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x80000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x100000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffefffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x100000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x200000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffdfffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x200000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x400000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xffbfffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x400000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x800000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xff7fffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x800000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x1000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfeffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x1000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x2000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfdffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x2000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x4000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xfbffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x4000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x8000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xf7ffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x8000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x10000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xefffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x10000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x20000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[134]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xdfffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x20000000U 
                                                 & vlSelfRef.IMM));
    }
    if ((0x40000000U & (vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0xbfffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x40000000U 
                                                 & vlSelfRef.IMM));
    }
    if (((vlSelfRef.IMM ^ vlSelfRef.ALU__DOT____Vtogcov__IMM) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[136]);
        vlSelfRef.ALU__DOT____Vtogcov__IMM = ((0x7fffffffU 
                                               & vlSelfRef.ALU__DOT____Vtogcov__IMM) 
                                              | (0x80000000U 
                                                 & vlSelfRef.IMM));
    }
    vlSelfRef.ALU__DOT__RDY = (0U == (IData)(vlSelfRef.ALU__DOT__state_curr));
    vlSelfRef.ALU__DOT__operand_A = vlSelfRef.REG_A;
    if ((0U == (IData)(vlSelfRef.MOVI))) {
        vlSelfRef.ALU__DOT__operand_B = vlSelfRef.REG_B;
        ++(vlSymsp->__Vcoverage[336]);
    } else if ((1U == (IData)(vlSelfRef.MOVI))) {
        ++(vlSymsp->__Vcoverage[337]);
        vlSelfRef.ALU__DOT__operand_B = vlSelfRef.MEM;
    } else if ((2U == (IData)(vlSelfRef.MOVI))) {
        ++(vlSymsp->__Vcoverage[338]);
        vlSelfRef.ALU__DOT__operand_B = vlSelfRef.IMM;
    } else {
        ++(vlSymsp->__Vcoverage[339]);
        vlSelfRef.ALU__DOT__operand_B = 0U;
    }
    ++(vlSymsp->__Vcoverage[340]);
    if (((IData)(vlSelfRef.ALU__DOT__mult_req) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__mult_req))) {
        ++(vlSymsp->__Vcoverage[335]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_req = vlSelfRef.ALU__DOT__mult_req;
    }
    __Vtableidx1 = (((IData)(vlSelfRef.ALU__DOT__mult_req) 
                     << 3U) | (((IData)(vlSelfRef.ACT) 
                                << 2U) | (IData)(vlSelfRef.ALU__DOT__state_curr)));
    vlSelfRef.ALU__DOT__state_next = Vtop__ConstPool__TABLE_h09c48e33_0
        [__Vtableidx1];
    if (((IData)(vlSelfRef.ALU__DOT__RDY) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__RDY))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlSelfRef.ALU__DOT____Vtogcov__RDY = vlSelfRef.ALU__DOT__RDY;
    }
    vlSelfRef.RDY = vlSelfRef.ALU__DOT__RDY;
    vlSelfRef.ALU__DOT__VLD = (1U & (~ ((IData)(vlSelfRef.RST) 
                                        | (IData)(vlSelfRef.ALU__DOT__RDY))));
    if ((1U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffffeU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (1U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((2U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffffdU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (2U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((4U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffffbU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (4U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((8U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffff7U & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (8U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffffefU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x10U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffffdfU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x20U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffffbfU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x40U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffff7fU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x80U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffeffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x100U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffdffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x200U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffffbffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x400U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffff7ffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x800U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffefffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x1000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffdfffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x2000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffffbfffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x4000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffff7fffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x8000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__operand_A 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffeffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x10000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__operand_A 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffdffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x20000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__operand_A 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfffbffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x40000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__operand_A 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfff7ffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x80000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__operand_A 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffefffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x100000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__operand_A 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffdfffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x200000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__operand_A 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xffbfffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x400000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__operand_A 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xff7fffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x800000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__operand_A 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[199]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfeffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x1000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__operand_A 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfdffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x2000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__operand_A 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xfbffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x4000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__operand_A 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xf7ffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x8000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__operand_A 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xefffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x10000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__operand_A 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xdfffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x20000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__operand_A 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0xbfffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x40000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if (((vlSelfRef.ALU__DOT__operand_A ^ vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[206]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_A = 
            ((0x7fffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_A) 
             | (0x80000000U & vlSelfRef.ALU__DOT__operand_A));
    }
    if ((1U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffffeU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (1U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((2U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffffdU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (2U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((4U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffffbU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (4U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((8U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffff7U & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (8U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffffefU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x10U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffffdfU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x20U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffffbfU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x40U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffff7fU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x80U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffeffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x100U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffdffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x200U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffffbffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x400U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffff7ffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x800U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffefffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x1000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffdfffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x2000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffffbfffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x4000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffff7fffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x8000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__operand_B 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffeffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x10000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__operand_B 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffdffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x20000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__operand_B 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfffbffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x40000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__operand_B 
                     ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfff7ffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x80000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__operand_B 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffefffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x100000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__operand_B 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffdfffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x200000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__operand_B 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xffbfffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x400000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__operand_B 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xff7fffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x800000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__operand_B 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[231]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfeffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x1000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__operand_B 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[232]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfdffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x2000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__operand_B 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xfbffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x4000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__operand_B 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[234]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xf7ffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x8000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__operand_B 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[235]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xefffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x10000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__operand_B 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[236]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xdfffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x20000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__operand_B 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0xbfffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x40000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    if (((vlSelfRef.ALU__DOT__operand_B ^ vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[238]);
        vlSelfRef.ALU__DOT____Vtogcov__operand_B = 
            ((0x7fffffffU & vlSelfRef.ALU__DOT____Vtogcov__operand_B) 
             | (0x80000000U & vlSelfRef.ALU__DOT__operand_B));
    }
    vlSelfRef.ALU__DOT__norm_res = 0U;
    vlSelfRef.ALU__DOT__mult_res = 0ULL;
    if (vlSelfRef.ALU__DOT__RDY) {
        if ((8U & (IData)(vlSelfRef.OP))) {
            if ((4U & (IData)(vlSelfRef.OP))) {
                if ((2U & (IData)(vlSelfRef.OP))) {
                    if ((1U & (IData)(vlSelfRef.OP))) {
                        vlSelfRef.ALU__DOT__norm_res 
                            = (vlSelfRef.ALU__DOT__operand_B 
                               - (IData)(1U));
                        ++(vlSymsp->__Vcoverage[356]);
                    } else {
                        ++(vlSymsp->__Vcoverage[355]);
                        vlSelfRef.ALU__DOT__norm_res 
                            = ((IData)(1U) + vlSelfRef.ALU__DOT__operand_B);
                    }
                } else if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[354]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            ^ vlSelfRef.ALU__DOT__operand_B));
                } else {
                    ++(vlSymsp->__Vcoverage[353]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            | vlSelfRef.ALU__DOT__operand_B));
                }
            } else if ((2U & (IData)(vlSelfRef.OP))) {
                if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[352]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            & vlSelfRef.ALU__DOT__operand_B));
                } else {
                    ++(vlSymsp->__Vcoverage[351]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (vlSelfRef.ALU__DOT__operand_A 
                         ^ vlSelfRef.ALU__DOT__operand_B);
                }
            } else if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[350]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                                | vlSelfRef.ALU__DOT__operand_B);
            } else {
                ++(vlSymsp->__Vcoverage[349]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                                & vlSelfRef.ALU__DOT__operand_B);
            }
        } else if ((4U & (IData)(vlSelfRef.OP))) {
            if ((2U & (IData)(vlSelfRef.OP))) {
                if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[348]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ vlSelfRef.ALU__DOT__operand_B);
                } else {
                    ++(vlSymsp->__Vcoverage[347]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        ((vlSelfRef.ALU__DOT__operand_B 
                          << 1U) | (vlSelfRef.ALU__DOT__operand_B 
                                    >> 0x1fU));
                }
            } else if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[346]);
                vlSelfRef.ALU__DOT__norm_res = ((vlSelfRef.ALU__DOT__operand_B 
                                                 << 0x1fU) 
                                                | (vlSelfRef.ALU__DOT__operand_B 
                                                   >> 1U));
            } else {
                ++(vlSymsp->__Vcoverage[345]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_B 
                                                << 1U);
            }
        } else if ((2U & (IData)(vlSelfRef.OP))) {
            if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[344]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_B 
                                                >> 1U);
            } else {
                ++(vlSymsp->__Vcoverage[343]);
                vlSelfRef.ALU__DOT__mult_res = ((QData)((IData)(vlSelfRef.ALU__DOT__operand_A)) 
                                                * (QData)((IData)(vlSelfRef.ALU__DOT__operand_B)));
            }
        } else if ((1U & (IData)(vlSelfRef.OP))) {
            ++(vlSymsp->__Vcoverage[342]);
            vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                            - vlSelfRef.ALU__DOT__operand_B);
        } else {
            ++(vlSymsp->__Vcoverage[341]);
            vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                            + vlSelfRef.ALU__DOT__operand_B);
        }
        ++(vlSymsp->__Vcoverage[358]);
    } else {
        ++(vlSymsp->__Vcoverage[359]);
    }
    ++(vlSymsp->__Vcoverage[360]);
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__state_next) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlSelfRef.ALU__DOT____Vtogcov__state_next = 
            ((2U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)) 
             | (1U & (IData)(vlSelfRef.ALU__DOT__state_next)));
    }
    if ((2U & ((IData)(vlSelfRef.ALU__DOT__state_next) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlSelfRef.ALU__DOT____Vtogcov__state_next = 
            ((1U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)) 
             | (2U & (IData)(vlSelfRef.ALU__DOT__state_next)));
    }
    if (((IData)(vlSelfRef.ALU__DOT__VLD) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__VLD))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlSelfRef.ALU__DOT____Vtogcov__VLD = vlSelfRef.ALU__DOT__VLD;
    }
    vlSelfRef.VLD = vlSelfRef.ALU__DOT__VLD;
    if ((1U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (1U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((2U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffdU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (2U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((4U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffbU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (4U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((8U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffff7U 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (8U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffefU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffdfU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffbfU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffff7fU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffeffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x100U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffdffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x200U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffbffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x400U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffff7ffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x800U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffefffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x1000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffdfffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x2000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffbfffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x4000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffff7fffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x8000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffeffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffdffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffbffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfff7ffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffefffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x100000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffdfffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x200000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffbfffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x400000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xff7fffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x800000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfeffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x1000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfdffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x2000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfbffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x4000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xf7ffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x8000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xefffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xdfffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xbfffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if (((vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[270]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0x7fffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__mult_res) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__mult_res)))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffeULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | (IData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlSelfRef.ALU__DOT__mult_res)))));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 1U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffdULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 1U))))) 
                                                      << 1U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 2U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffbULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 2U))))) 
                                                      << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 3U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffff7ULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 3U))))) 
                                                      << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 4U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffefULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 4U))))) 
                                                      << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 5U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffdfULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 5U))))) 
                                                      << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 6U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffbfULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 6U))))) 
                                                      << 6U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 7U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffff7fULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 7U))))) 
                                                      << 7U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 8U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffeffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 8U))))) 
                                                      << 8U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 9U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffdffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 9U))))) 
                                                      << 9U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xaU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffbffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xaU))))) 
                                                      << 0xaU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xbU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffff7ffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xbU))))) 
                                                      << 0xbU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xcU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffefffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xcU))))) 
                                                      << 0xcU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xdU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffdfffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xdU))))) 
                                                      << 0xdU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xeU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffbfffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xeU))))) 
                                                      << 0xeU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xfU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffff7fffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xfU))))) 
                                                      << 0xfU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x10U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffeffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x10U))))) 
                                                      << 0x10U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x11U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffdffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x11U))))) 
                                                      << 0x11U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x12U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffbffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x12U))))) 
                                                      << 0x12U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x13U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffff7ffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x13U))))) 
                                                      << 0x13U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x14U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffefffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x14U))))) 
                                                      << 0x14U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x15U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffdfffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x15U))))) 
                                                      << 0x15U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x16U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffbfffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x16U))))) 
                                                      << 0x16U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x17U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffff7fffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x17U))))) 
                                                      << 0x17U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x18U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffeffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x18U))))) 
                                                      << 0x18U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x19U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffdffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x19U))))) 
                                                      << 0x19U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffbffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1aU))))) 
                                                      << 0x1aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffff7ffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1bU))))) 
                                                      << 0x1bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffefffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1cU))))) 
                                                      << 0x1cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffdfffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1dU))))) 
                                                      << 0x1dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffbfffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1eU))))) 
                                                      << 0x1eU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1fU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffff7fffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1fU))))) 
                                                      << 0x1fU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x20U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffeffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x20U))))) 
                                                      << 0x20U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x21U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffdffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x21U))))) 
                                                      << 0x21U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x22U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffbffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x22U))))) 
                                                      << 0x22U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x23U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffff7ffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x23U))))) 
                                                      << 0x23U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x24U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffefffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x24U))))) 
                                                      << 0x24U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x25U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffdfffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x25U))))) 
                                                      << 0x25U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x26U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffbfffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x26U))))) 
                                                      << 0x26U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x27U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffff7fffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x27U))))) 
                                                      << 0x27U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x28U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffeffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x28U))))) 
                                                      << 0x28U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x29U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffdffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x29U))))) 
                                                      << 0x29U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffbffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2aU))))) 
                                                      << 0x2aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffff7ffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2bU))))) 
                                                      << 0x2bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffefffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2cU))))) 
                                                      << 0x2cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffdfffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2dU))))) 
                                                      << 0x2dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffbfffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2eU))))) 
                                                      << 0x2eU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2fU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffff7fffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2fU))))) 
                                                      << 0x2fU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x30U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffeffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x30U))))) 
                                                      << 0x30U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x31U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffdffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x31U))))) 
                                                      << 0x31U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x32U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffbffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x32U))))) 
                                                      << 0x32U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x33U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfff7ffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x33U))))) 
                                                      << 0x33U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x34U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffefffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x34U))))) 
                                                      << 0x34U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x35U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffdfffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x35U))))) 
                                                      << 0x35U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x36U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffbfffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x36U))))) 
                                                      << 0x36U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x37U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xff7fffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x37U))))) 
                                                      << 0x37U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x38U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfeffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x38U))))) 
                                                      << 0x38U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x39U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfdffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x39U))))) 
                                                      << 0x39U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfbffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3aU))))) 
                                                      << 0x3aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xf7ffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3bU))))) 
                                                      << 0x3bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xefffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3cU))))) 
                                                      << 0x3cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xdfffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3dU))))) 
                                                      << 0x3dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xbfffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3eU))))) 
                                                      << 0x3eU));
    }
    if ((IData)(((vlSelfRef.ALU__DOT__mult_res ^ vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                 >> 0x3fU))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0x7fffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3fU))))) 
                                                      << 0x3fU));
    }
    if ((2U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
        if ((1U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
            vlSelfRef.ALU__DOT__DATA = (IData)((vlSelfRef.ALU__DOT__mult_res 
                                                >> 0x20U));
            ++(vlSymsp->__Vcoverage[375]);
        } else {
            ++(vlSymsp->__Vcoverage[374]);
            vlSelfRef.ALU__DOT__DATA = (IData)(vlSelfRef.ALU__DOT__mult_res);
        }
    } else if ((1U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
        ++(vlSymsp->__Vcoverage[373]);
        vlSelfRef.ALU__DOT__DATA = vlSelfRef.ALU__DOT__norm_res;
    } else {
        ++(vlSymsp->__Vcoverage[372]);
        vlSelfRef.ALU__DOT__DATA = 0U;
    }
    ++(vlSymsp->__Vcoverage[376]);
    vlSelfRef.DATA = vlSelfRef.ALU__DOT__DATA;
    if ((1U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffeU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (1U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((2U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffdU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (2U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((4U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffbU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (4U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((8U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffff7U 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (8U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffefU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffdfU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffbfU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffff7fU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffeffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x100U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffdffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x200U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffbffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x400U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffff7ffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x800U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffefffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x1000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffdfffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x2000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffbfffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x4000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffff7fffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x8000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffeffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffdffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffbffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfff7ffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffefffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x100000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffdfffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x200000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffbfffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x400000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xff7fffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x800000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfeffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x1000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfdffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x2000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfbffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x4000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xf7ffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x8000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xefffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xdfffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xbfffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if (((vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[168]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0x7fffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.CLK) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__CLK__0 = vlSelfRef.CLK;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.RST) {
        ++(vlSymsp->__Vcoverage[369]);
        vlSelfRef.ALU__DOT__state_curr = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[370]);
        vlSelfRef.ALU__DOT__state_curr = vlSelfRef.ALU__DOT__state_next;
    }
    ++(vlSymsp->__Vcoverage[371]);
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__state_curr) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlSelfRef.ALU__DOT____Vtogcov__state_curr = 
            ((2U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)) 
             | (1U & (IData)(vlSelfRef.ALU__DOT__state_curr)));
    }
    if ((2U & ((IData)(vlSelfRef.ALU__DOT__state_curr) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlSelfRef.ALU__DOT____Vtogcov__state_curr = 
            ((1U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_curr)) 
             | (2U & (IData)(vlSelfRef.ALU__DOT__state_curr)));
    }
    __Vtableidx1 = (((IData)(vlSelfRef.ALU__DOT__mult_req) 
                     << 3U) | (((IData)(vlSelfRef.ACT) 
                                << 2U) | (IData)(vlSelfRef.ALU__DOT__state_curr)));
    vlSelfRef.ALU__DOT__state_next = Vtop__ConstPool__TABLE_h09c48e33_0
        [__Vtableidx1];
    vlSelfRef.ALU__DOT__RDY = (0U == (IData)(vlSelfRef.ALU__DOT__state_curr));
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__state_next) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlSelfRef.ALU__DOT____Vtogcov__state_next = 
            ((2U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)) 
             | (1U & (IData)(vlSelfRef.ALU__DOT__state_next)));
    }
    if ((2U & ((IData)(vlSelfRef.ALU__DOT__state_next) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlSelfRef.ALU__DOT____Vtogcov__state_next = 
            ((1U & (IData)(vlSelfRef.ALU__DOT____Vtogcov__state_next)) 
             | (2U & (IData)(vlSelfRef.ALU__DOT__state_next)));
    }
    if (((IData)(vlSelfRef.ALU__DOT__RDY) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__RDY))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlSelfRef.ALU__DOT____Vtogcov__RDY = vlSelfRef.ALU__DOT__RDY;
    }
    vlSelfRef.RDY = vlSelfRef.ALU__DOT__RDY;
    vlSelfRef.ALU__DOT__VLD = (1U & (~ ((IData)(vlSelfRef.RST) 
                                        | (IData)(vlSelfRef.ALU__DOT__RDY))));
    vlSelfRef.ALU__DOT__norm_res = 0U;
    vlSelfRef.ALU__DOT__mult_res = 0ULL;
    if (vlSelfRef.ALU__DOT__RDY) {
        if ((8U & (IData)(vlSelfRef.OP))) {
            if ((4U & (IData)(vlSelfRef.OP))) {
                if ((2U & (IData)(vlSelfRef.OP))) {
                    if ((1U & (IData)(vlSelfRef.OP))) {
                        vlSelfRef.ALU__DOT__norm_res 
                            = (vlSelfRef.ALU__DOT__operand_B 
                               - (IData)(1U));
                        ++(vlSymsp->__Vcoverage[356]);
                    } else {
                        ++(vlSymsp->__Vcoverage[355]);
                        vlSelfRef.ALU__DOT__norm_res 
                            = ((IData)(1U) + vlSelfRef.ALU__DOT__operand_B);
                    }
                } else if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[354]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            ^ vlSelfRef.ALU__DOT__operand_B));
                } else {
                    ++(vlSymsp->__Vcoverage[353]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            | vlSelfRef.ALU__DOT__operand_B));
                }
            } else if ((2U & (IData)(vlSelfRef.OP))) {
                if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[352]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ (vlSelfRef.ALU__DOT__operand_A 
                            & vlSelfRef.ALU__DOT__operand_B));
                } else {
                    ++(vlSymsp->__Vcoverage[351]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (vlSelfRef.ALU__DOT__operand_A 
                         ^ vlSelfRef.ALU__DOT__operand_B);
                }
            } else if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[350]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                                | vlSelfRef.ALU__DOT__operand_B);
            } else {
                ++(vlSymsp->__Vcoverage[349]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                                & vlSelfRef.ALU__DOT__operand_B);
            }
        } else if ((4U & (IData)(vlSelfRef.OP))) {
            if ((2U & (IData)(vlSelfRef.OP))) {
                if ((1U & (IData)(vlSelfRef.OP))) {
                    ++(vlSymsp->__Vcoverage[348]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        (~ vlSelfRef.ALU__DOT__operand_B);
                } else {
                    ++(vlSymsp->__Vcoverage[347]);
                    vlSelfRef.ALU__DOT__norm_res = 
                        ((vlSelfRef.ALU__DOT__operand_B 
                          << 1U) | (vlSelfRef.ALU__DOT__operand_B 
                                    >> 0x1fU));
                }
            } else if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[346]);
                vlSelfRef.ALU__DOT__norm_res = ((vlSelfRef.ALU__DOT__operand_B 
                                                 << 0x1fU) 
                                                | (vlSelfRef.ALU__DOT__operand_B 
                                                   >> 1U));
            } else {
                ++(vlSymsp->__Vcoverage[345]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_B 
                                                << 1U);
            }
        } else if ((2U & (IData)(vlSelfRef.OP))) {
            if ((1U & (IData)(vlSelfRef.OP))) {
                ++(vlSymsp->__Vcoverage[344]);
                vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_B 
                                                >> 1U);
            } else {
                ++(vlSymsp->__Vcoverage[343]);
                vlSelfRef.ALU__DOT__mult_res = ((QData)((IData)(vlSelfRef.ALU__DOT__operand_A)) 
                                                * (QData)((IData)(vlSelfRef.ALU__DOT__operand_B)));
            }
        } else if ((1U & (IData)(vlSelfRef.OP))) {
            ++(vlSymsp->__Vcoverage[342]);
            vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                            - vlSelfRef.ALU__DOT__operand_B);
        } else {
            ++(vlSymsp->__Vcoverage[341]);
            vlSelfRef.ALU__DOT__norm_res = (vlSelfRef.ALU__DOT__operand_A 
                                            + vlSelfRef.ALU__DOT__operand_B);
        }
        ++(vlSymsp->__Vcoverage[358]);
    } else {
        ++(vlSymsp->__Vcoverage[359]);
    }
    ++(vlSymsp->__Vcoverage[360]);
    if (((IData)(vlSelfRef.ALU__DOT__VLD) ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__VLD))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlSelfRef.ALU__DOT____Vtogcov__VLD = vlSelfRef.ALU__DOT__VLD;
    }
    vlSelfRef.VLD = vlSelfRef.ALU__DOT__VLD;
    if ((1U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (1U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((2U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[240]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffdU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (2U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((4U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[241]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffffbU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (4U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((8U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[242]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffff7U 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (8U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[243]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffefU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[244]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffdfU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[245]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffffbfU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[246]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffff7fU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[247]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffeffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x100U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[248]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffdffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x200U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[249]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffffbffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x400U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[250]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffff7ffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x800U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[251]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffefffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x1000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[252]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffdfffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x2000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[253]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffffbfffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x4000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[254]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffff7fffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x8000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[255]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffeffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[256]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffdffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[257]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfffbffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[258]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfff7ffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[259]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffefffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x100000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[260]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffdfffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x200000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[261]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xffbfffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x400000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__norm_res 
                      ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[262]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xff7fffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x800000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[263]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfeffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x1000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[264]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfdffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x2000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[265]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xfbffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x4000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__norm_res 
                       ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[266]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xf7ffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x8000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[267]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xefffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x10000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[268]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xdfffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x20000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__norm_res 
                        ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res))) {
        ++(vlSymsp->__Vcoverage[269]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0xbfffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x40000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if (((vlSelfRef.ALU__DOT__norm_res ^ vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[270]);
        vlSelfRef.ALU__DOT____Vtogcov__norm_res = (
                                                   (0x7fffffffU 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__norm_res) 
                                                   | (0x80000000U 
                                                      & vlSelfRef.ALU__DOT__norm_res));
    }
    if ((1U & ((IData)(vlSelfRef.ALU__DOT__mult_res) 
               ^ (IData)(vlSelfRef.ALU__DOT____Vtogcov__mult_res)))) {
        ++(vlSymsp->__Vcoverage[271]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffeULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | (IData)((IData)(
                                                                     (1U 
                                                                      & (IData)(vlSelfRef.ALU__DOT__mult_res)))));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 1U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 1U))))) {
        ++(vlSymsp->__Vcoverage[272]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffdULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 1U))))) 
                                                      << 1U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 2U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 2U))))) {
        ++(vlSymsp->__Vcoverage[273]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffffbULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 2U))))) 
                                                      << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 3U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 3U))))) {
        ++(vlSymsp->__Vcoverage[274]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffff7ULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 3U))))) 
                                                      << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 4U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 4U))))) {
        ++(vlSymsp->__Vcoverage[275]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffefULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 4U))))) 
                                                      << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 5U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 5U))))) {
        ++(vlSymsp->__Vcoverage[276]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffdfULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 5U))))) 
                                                      << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 6U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 6U))))) {
        ++(vlSymsp->__Vcoverage[277]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffffbfULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 6U))))) 
                                                      << 6U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 7U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 7U))))) {
        ++(vlSymsp->__Vcoverage[278]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffff7fULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 7U))))) 
                                                      << 7U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 8U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 8U))))) {
        ++(vlSymsp->__Vcoverage[279]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffeffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 8U))))) 
                                                      << 8U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 9U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                           >> 9U))))) {
        ++(vlSymsp->__Vcoverage[280]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffdffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 9U))))) 
                                                      << 9U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xaU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xaU))))) {
        ++(vlSymsp->__Vcoverage[281]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffffbffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xaU))))) 
                                                      << 0xaU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xbU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xbU))))) {
        ++(vlSymsp->__Vcoverage[282]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffff7ffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xbU))))) 
                                                      << 0xbU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xcU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xcU))))) {
        ++(vlSymsp->__Vcoverage[283]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffefffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xcU))))) 
                                                      << 0xcU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xdU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xdU))))) {
        ++(vlSymsp->__Vcoverage[284]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffdfffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xdU))))) 
                                                      << 0xdU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xeU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xeU))))) {
        ++(vlSymsp->__Vcoverage[285]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffffbfffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xeU))))) 
                                                      << 0xeU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0xfU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                             >> 0xfU))))) {
        ++(vlSymsp->__Vcoverage[286]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffff7fffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0xfU))))) 
                                                      << 0xfU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x10U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x10U))))) {
        ++(vlSymsp->__Vcoverage[287]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffeffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x10U))))) 
                                                      << 0x10U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x11U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x11U))))) {
        ++(vlSymsp->__Vcoverage[288]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffdffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x11U))))) 
                                                      << 0x11U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x12U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x12U))))) {
        ++(vlSymsp->__Vcoverage[289]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffffbffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x12U))))) 
                                                      << 0x12U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x13U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x13U))))) {
        ++(vlSymsp->__Vcoverage[290]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffff7ffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x13U))))) 
                                                      << 0x13U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x14U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x14U))))) {
        ++(vlSymsp->__Vcoverage[291]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffefffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x14U))))) 
                                                      << 0x14U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x15U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x15U))))) {
        ++(vlSymsp->__Vcoverage[292]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffdfffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x15U))))) 
                                                      << 0x15U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x16U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x16U))))) {
        ++(vlSymsp->__Vcoverage[293]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffffbfffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x16U))))) 
                                                      << 0x16U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x17U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x17U))))) {
        ++(vlSymsp->__Vcoverage[294]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffff7fffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x17U))))) 
                                                      << 0x17U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x18U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x18U))))) {
        ++(vlSymsp->__Vcoverage[295]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffeffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x18U))))) 
                                                      << 0x18U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x19U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x19U))))) {
        ++(vlSymsp->__Vcoverage[296]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffdffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x19U))))) 
                                                      << 0x19U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1aU))))) {
        ++(vlSymsp->__Vcoverage[297]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffffbffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1aU))))) 
                                                      << 0x1aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1bU))))) {
        ++(vlSymsp->__Vcoverage[298]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffff7ffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1bU))))) 
                                                      << 0x1bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1cU))))) {
        ++(vlSymsp->__Vcoverage[299]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffefffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1cU))))) 
                                                      << 0x1cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1dU))))) {
        ++(vlSymsp->__Vcoverage[300]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffdfffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1dU))))) 
                                                      << 0x1dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1eU))))) {
        ++(vlSymsp->__Vcoverage[301]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffffbfffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1eU))))) 
                                                      << 0x1eU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x1fU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x1fU))))) {
        ++(vlSymsp->__Vcoverage[302]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffff7fffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x1fU))))) 
                                                      << 0x1fU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x20U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x20U))))) {
        ++(vlSymsp->__Vcoverage[303]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffeffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x20U))))) 
                                                      << 0x20U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x21U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x21U))))) {
        ++(vlSymsp->__Vcoverage[304]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffdffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x21U))))) 
                                                      << 0x21U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x22U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x22U))))) {
        ++(vlSymsp->__Vcoverage[305]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffffbffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x22U))))) 
                                                      << 0x22U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x23U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x23U))))) {
        ++(vlSymsp->__Vcoverage[306]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffff7ffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x23U))))) 
                                                      << 0x23U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x24U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x24U))))) {
        ++(vlSymsp->__Vcoverage[307]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffefffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x24U))))) 
                                                      << 0x24U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x25U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x25U))))) {
        ++(vlSymsp->__Vcoverage[308]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffdfffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x25U))))) 
                                                      << 0x25U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x26U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x26U))))) {
        ++(vlSymsp->__Vcoverage[309]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffffbfffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x26U))))) 
                                                      << 0x26U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x27U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x27U))))) {
        ++(vlSymsp->__Vcoverage[310]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffff7fffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x27U))))) 
                                                      << 0x27U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x28U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x28U))))) {
        ++(vlSymsp->__Vcoverage[311]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffeffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x28U))))) 
                                                      << 0x28U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x29U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x29U))))) {
        ++(vlSymsp->__Vcoverage[312]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffdffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x29U))))) 
                                                      << 0x29U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2aU))))) {
        ++(vlSymsp->__Vcoverage[313]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffffbffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2aU))))) 
                                                      << 0x2aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2bU))))) {
        ++(vlSymsp->__Vcoverage[314]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffff7ffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2bU))))) 
                                                      << 0x2bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2cU))))) {
        ++(vlSymsp->__Vcoverage[315]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffefffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2cU))))) 
                                                      << 0x2cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2dU))))) {
        ++(vlSymsp->__Vcoverage[316]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffdfffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2dU))))) 
                                                      << 0x2dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2eU))))) {
        ++(vlSymsp->__Vcoverage[317]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffffbfffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2eU))))) 
                                                      << 0x2eU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x2fU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x2fU))))) {
        ++(vlSymsp->__Vcoverage[318]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffff7fffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x2fU))))) 
                                                      << 0x2fU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x30U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x30U))))) {
        ++(vlSymsp->__Vcoverage[319]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffeffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x30U))))) 
                                                      << 0x30U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x31U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x31U))))) {
        ++(vlSymsp->__Vcoverage[320]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffdffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x31U))))) 
                                                      << 0x31U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x32U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x32U))))) {
        ++(vlSymsp->__Vcoverage[321]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfffbffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x32U))))) 
                                                      << 0x32U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x33U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x33U))))) {
        ++(vlSymsp->__Vcoverage[322]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfff7ffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x33U))))) 
                                                      << 0x33U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x34U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x34U))))) {
        ++(vlSymsp->__Vcoverage[323]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffefffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x34U))))) 
                                                      << 0x34U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x35U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x35U))))) {
        ++(vlSymsp->__Vcoverage[324]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffdfffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x35U))))) 
                                                      << 0x35U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x36U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x36U))))) {
        ++(vlSymsp->__Vcoverage[325]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xffbfffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x36U))))) 
                                                      << 0x36U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x37U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x37U))))) {
        ++(vlSymsp->__Vcoverage[326]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xff7fffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x37U))))) 
                                                      << 0x37U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x38U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x38U))))) {
        ++(vlSymsp->__Vcoverage[327]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfeffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x38U))))) 
                                                      << 0x38U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x39U)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x39U))))) {
        ++(vlSymsp->__Vcoverage[328]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfdffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x39U))))) 
                                                      << 0x39U));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3aU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3aU))))) {
        ++(vlSymsp->__Vcoverage[329]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xfbffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3aU))))) 
                                                      << 0x3aU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3bU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3bU))))) {
        ++(vlSymsp->__Vcoverage[330]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xf7ffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3bU))))) 
                                                      << 0x3bU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3cU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3cU))))) {
        ++(vlSymsp->__Vcoverage[331]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xefffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3cU))))) 
                                                      << 0x3cU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3dU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3dU))))) {
        ++(vlSymsp->__Vcoverage[332]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xdfffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3dU))))) 
                                                      << 0x3dU));
    }
    if ((1U & ((IData)((vlSelfRef.ALU__DOT__mult_res 
                        >> 0x3eU)) ^ (IData)((vlSelfRef.ALU__DOT____Vtogcov__mult_res 
                                              >> 0x3eU))))) {
        ++(vlSymsp->__Vcoverage[333]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0xbfffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3eU))))) 
                                                      << 0x3eU));
    }
    if ((IData)(((vlSelfRef.ALU__DOT__mult_res ^ vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                 >> 0x3fU))) {
        ++(vlSymsp->__Vcoverage[334]);
        vlSelfRef.ALU__DOT____Vtogcov__mult_res = (
                                                   (0x7fffffffffffffffULL 
                                                    & vlSelfRef.ALU__DOT____Vtogcov__mult_res) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelfRef.ALU__DOT__mult_res 
                                                                                >> 0x3fU))))) 
                                                      << 0x3fU));
    }
    if ((2U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
        if ((1U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
            vlSelfRef.ALU__DOT__DATA = (IData)((vlSelfRef.ALU__DOT__mult_res 
                                                >> 0x20U));
            ++(vlSymsp->__Vcoverage[375]);
        } else {
            ++(vlSymsp->__Vcoverage[374]);
            vlSelfRef.ALU__DOT__DATA = (IData)(vlSelfRef.ALU__DOT__mult_res);
        }
    } else if ((1U & (IData)(vlSelfRef.ALU__DOT__state_curr))) {
        ++(vlSymsp->__Vcoverage[373]);
        vlSelfRef.ALU__DOT__DATA = vlSelfRef.ALU__DOT__norm_res;
    } else {
        ++(vlSymsp->__Vcoverage[372]);
        vlSelfRef.ALU__DOT__DATA = 0U;
    }
    ++(vlSymsp->__Vcoverage[376]);
    vlSelfRef.DATA = vlSelfRef.ALU__DOT__DATA;
    if ((1U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffeU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (1U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((2U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffdU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (2U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((4U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffffbU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (4U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((8U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffff7U 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (8U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffefU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffdfU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffffbfU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x80U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffff7fU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x100U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffeffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x100U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x200U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffdffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x200U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x400U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffffbffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x400U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x800U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffff7ffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x800U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x1000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffefffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x1000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x2000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffdfffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x2000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x4000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffffbfffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x4000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x8000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffff7fffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x8000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffeffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffdffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfffbffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x80000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfff7ffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x100000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffefffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x100000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x200000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffdfffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x200000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x400000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xffbfffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x400000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x800000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xff7fffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x800000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x1000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfeffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x1000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x2000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfdffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x2000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x4000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xfbffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x4000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x8000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xf7ffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x8000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x10000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xefffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x10000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x20000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[166]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xdfffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x20000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if ((0x40000000U & (vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0xbfffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x40000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
    if (((vlSelfRef.ALU__DOT__DATA ^ vlSelfRef.ALU__DOT____Vtogcov__DATA) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[168]);
        vlSelfRef.ALU__DOT____Vtogcov__DATA = ((0x7fffffffU 
                                                & vlSelfRef.ALU__DOT____Vtogcov__DATA) 
                                               | (0x80000000U 
                                                  & vlSelfRef.ALU__DOT__DATA));
    }
}
