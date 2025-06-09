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

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.arithmetic_unit__DOT__CLK = vlSelfRef.CLK;
    vlSelfRef.arithmetic_unit__DOT__RST = vlSelfRef.RST;
    vlSelfRef.arithmetic_unit__DOT__ACT = vlSelfRef.ACT;
    vlSelfRef.arithmetic_unit__DOT__OP_CODE = vlSelfRef.OP_CODE;
    vlSelfRef.arithmetic_unit__DOT__MOVI = vlSelfRef.MOVI;
    vlSelfRef.arithmetic_unit__DOT__REG_A = vlSelfRef.REG_A;
    vlSelfRef.arithmetic_unit__DOT__REG_B = vlSelfRef.REG_B;
    vlSelfRef.arithmetic_unit__DOT__MEM = vlSelfRef.MEM;
    vlSelfRef.arithmetic_unit__DOT__IMM = vlSelfRef.IMM;
    if (((IData)(vlSelfRef.CLK) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__CLK))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__CLK 
            = vlSelfRef.CLK;
    }
    if (((IData)(vlSelfRef.RST) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__RST))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__RST 
            = vlSelfRef.RST;
    }
    if (((IData)(vlSelfRef.ACT) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__ACT))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__ACT 
            = vlSelfRef.ACT;
    }
    if (((IData)(vlSelfRef.arithmetic_unit__DOT__DATA_VALID) 
         ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA_VALID))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA_VALID 
            = vlSelfRef.arithmetic_unit__DOT__DATA_VALID;
    }
    if (((IData)(vlSelfRef.arithmetic_unit__DOT__mul_busy) 
         ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_busy))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_busy 
            = vlSelfRef.arithmetic_unit__DOT__mul_busy;
    }
    vlSelfRef.DATA = vlSelfRef.arithmetic_unit__DOT__DATA;
    vlSelfRef.DATA_VALID = vlSelfRef.arithmetic_unit__DOT__DATA_VALID;
    if ((1U & ((IData)(vlSelfRef.OP_CODE) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE)))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE 
            = ((2U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE)) 
               | (1U & (IData)(vlSelfRef.OP_CODE)));
    }
    if ((2U & ((IData)(vlSelfRef.OP_CODE) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE)))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE 
            = ((1U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__OP_CODE)) 
               | (2U & (IData)(vlSelfRef.OP_CODE)));
    }
    if ((1U & ((IData)(vlSelfRef.MOVI) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI 
            = ((2U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI)) 
               | (1U & (IData)(vlSelfRef.MOVI)));
    }
    if ((2U & ((IData)(vlSelfRef.MOVI) ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI 
            = ((1U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__MOVI)) 
               | (2U & (IData)(vlSelfRef.MOVI)));
    }
    if ((1U & ((IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter) 
               ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter 
            = ((2U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)) 
               | (1U & (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter)));
    }
    if ((2U & ((IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter) 
               ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter 
            = ((1U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)) 
               | (2U & (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter)));
    }
    if ((1U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (1U & vlSelfRef.REG_A));
    }
    if ((2U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (2U & vlSelfRef.REG_A));
    }
    if ((4U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (4U & vlSelfRef.REG_A));
    }
    if ((8U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (8U & vlSelfRef.REG_A));
    }
    if ((0x10U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x10U & vlSelfRef.REG_A));
    }
    if ((0x20U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x20U & vlSelfRef.REG_A));
    }
    if ((0x40U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x40U & vlSelfRef.REG_A));
    }
    if ((0x80U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x80U & vlSelfRef.REG_A));
    }
    if ((0x100U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x100U & vlSelfRef.REG_A));
    }
    if ((0x200U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x200U & vlSelfRef.REG_A));
    }
    if ((0x400U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x400U & vlSelfRef.REG_A));
    }
    if ((0x800U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x800U & vlSelfRef.REG_A));
    }
    if ((0x1000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x1000U & vlSelfRef.REG_A));
    }
    if ((0x2000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x2000U & vlSelfRef.REG_A));
    }
    if ((0x4000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x4000U & vlSelfRef.REG_A));
    }
    if ((0x8000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x8000U & vlSelfRef.REG_A));
    }
    if ((0x10000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x10000U & vlSelfRef.REG_A));
    }
    if ((0x20000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x20000U & vlSelfRef.REG_A));
    }
    if ((0x40000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x40000U & vlSelfRef.REG_A));
    }
    if ((0x80000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x80000U & vlSelfRef.REG_A));
    }
    if ((0x100000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x100000U & vlSelfRef.REG_A));
    }
    if ((0x200000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x200000U & vlSelfRef.REG_A));
    }
    if ((0x400000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x400000U & vlSelfRef.REG_A));
    }
    if ((0x800000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x800000U & vlSelfRef.REG_A));
    }
    if ((0x1000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x1000000U & vlSelfRef.REG_A));
    }
    if ((0x2000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x2000000U & vlSelfRef.REG_A));
    }
    if ((0x4000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x4000000U & vlSelfRef.REG_A));
    }
    if ((0x8000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x8000000U & vlSelfRef.REG_A));
    }
    if ((0x10000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[35]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x10000000U & vlSelfRef.REG_A));
    }
    if ((0x20000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[36]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x20000000U & vlSelfRef.REG_A));
    }
    if ((0x40000000U & (vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A))) {
        ++(vlSymsp->__Vcoverage[37]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x40000000U & vlSelfRef.REG_A));
    }
    if (((vlSelfRef.REG_A ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[38]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_A) 
               | (0x80000000U & vlSelfRef.REG_A));
    }
    if ((1U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[39]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (1U & vlSelfRef.REG_B));
    }
    if ((2U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[40]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (2U & vlSelfRef.REG_B));
    }
    if ((4U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[41]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (4U & vlSelfRef.REG_B));
    }
    if ((8U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[42]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (8U & vlSelfRef.REG_B));
    }
    if ((0x10U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[43]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x10U & vlSelfRef.REG_B));
    }
    if ((0x20U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x20U & vlSelfRef.REG_B));
    }
    if ((0x40U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x40U & vlSelfRef.REG_B));
    }
    if ((0x80U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x80U & vlSelfRef.REG_B));
    }
    if ((0x100U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x100U & vlSelfRef.REG_B));
    }
    if ((0x200U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x200U & vlSelfRef.REG_B));
    }
    if ((0x400U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x400U & vlSelfRef.REG_B));
    }
    if ((0x800U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x800U & vlSelfRef.REG_B));
    }
    if ((0x1000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x1000U & vlSelfRef.REG_B));
    }
    if ((0x2000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x2000U & vlSelfRef.REG_B));
    }
    if ((0x4000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x4000U & vlSelfRef.REG_B));
    }
    if ((0x8000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x8000U & vlSelfRef.REG_B));
    }
    if ((0x10000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x10000U & vlSelfRef.REG_B));
    }
    if ((0x20000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x20000U & vlSelfRef.REG_B));
    }
    if ((0x40000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x40000U & vlSelfRef.REG_B));
    }
    if ((0x80000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x80000U & vlSelfRef.REG_B));
    }
    if ((0x100000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x100000U & vlSelfRef.REG_B));
    }
    if ((0x200000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x200000U & vlSelfRef.REG_B));
    }
    if ((0x400000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x400000U & vlSelfRef.REG_B));
    }
    if ((0x800000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x800000U & vlSelfRef.REG_B));
    }
    if ((0x1000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x1000000U & vlSelfRef.REG_B));
    }
    if ((0x2000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x2000000U & vlSelfRef.REG_B));
    }
    if ((0x4000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x4000000U & vlSelfRef.REG_B));
    }
    if ((0x8000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x8000000U & vlSelfRef.REG_B));
    }
    if ((0x10000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x10000000U & vlSelfRef.REG_B));
    }
    if ((0x20000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x20000000U & vlSelfRef.REG_B));
    }
    if ((0x40000000U & (vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x40000000U & vlSelfRef.REG_B));
    }
    if (((vlSelfRef.REG_B ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[70]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__REG_B) 
               | (0x80000000U & vlSelfRef.REG_B));
    }
    if ((1U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (1U & vlSelfRef.MEM));
    }
    if ((2U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (2U & vlSelfRef.MEM));
    }
    if ((4U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (4U & vlSelfRef.MEM));
    }
    if ((8U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (8U & vlSelfRef.MEM));
    }
    if ((0x10U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x10U & vlSelfRef.MEM));
    }
    if ((0x20U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x20U & vlSelfRef.MEM));
    }
    if ((0x40U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x40U & vlSelfRef.MEM));
    }
    if ((0x80U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x80U & vlSelfRef.MEM));
    }
    if ((0x100U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x100U & vlSelfRef.MEM));
    }
    if ((0x200U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x200U & vlSelfRef.MEM));
    }
    if ((0x400U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x400U & vlSelfRef.MEM));
    }
    if ((0x800U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x800U & vlSelfRef.MEM));
    }
    if ((0x1000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x1000U & vlSelfRef.MEM));
    }
    if ((0x2000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x2000U & vlSelfRef.MEM));
    }
    if ((0x4000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[85]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x4000U & vlSelfRef.MEM));
    }
    if ((0x8000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[86]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x8000U & vlSelfRef.MEM));
    }
    if ((0x10000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[87]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x10000U & vlSelfRef.MEM));
    }
    if ((0x20000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[88]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x20000U & vlSelfRef.MEM));
    }
    if ((0x40000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[89]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x40000U & vlSelfRef.MEM));
    }
    if ((0x80000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[90]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x80000U & vlSelfRef.MEM));
    }
    if ((0x100000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[91]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x100000U & vlSelfRef.MEM));
    }
    if ((0x200000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[92]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x200000U & vlSelfRef.MEM));
    }
    if ((0x400000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[93]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x400000U & vlSelfRef.MEM));
    }
    if ((0x800000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[94]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x800000U & vlSelfRef.MEM));
    }
    if ((0x1000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[95]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x1000000U & vlSelfRef.MEM));
    }
    if ((0x2000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[96]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x2000000U & vlSelfRef.MEM));
    }
    if ((0x4000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[97]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x4000000U & vlSelfRef.MEM));
    }
    if ((0x8000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[98]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x8000000U & vlSelfRef.MEM));
    }
    if ((0x10000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[99]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x10000000U & vlSelfRef.MEM));
    }
    if ((0x20000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[100]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x20000000U & vlSelfRef.MEM));
    }
    if ((0x40000000U & (vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM))) {
        ++(vlSymsp->__Vcoverage[101]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x40000000U & vlSelfRef.MEM));
    }
    if (((vlSelfRef.MEM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[102]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__MEM) 
               | (0x80000000U & vlSelfRef.MEM));
    }
    if ((1U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[103]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (1U & vlSelfRef.IMM));
    }
    if ((2U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[104]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (2U & vlSelfRef.IMM));
    }
    if ((4U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[105]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (4U & vlSelfRef.IMM));
    }
    if ((8U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[106]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (8U & vlSelfRef.IMM));
    }
    if ((0x10U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[107]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x10U & vlSelfRef.IMM));
    }
    if ((0x20U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[108]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x20U & vlSelfRef.IMM));
    }
    if ((0x40U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[109]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x40U & vlSelfRef.IMM));
    }
    if ((0x80U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[110]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x80U & vlSelfRef.IMM));
    }
    if ((0x100U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[111]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x100U & vlSelfRef.IMM));
    }
    if ((0x200U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[112]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x200U & vlSelfRef.IMM));
    }
    if ((0x400U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[113]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x400U & vlSelfRef.IMM));
    }
    if ((0x800U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[114]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x800U & vlSelfRef.IMM));
    }
    if ((0x1000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[115]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x1000U & vlSelfRef.IMM));
    }
    if ((0x2000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[116]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x2000U & vlSelfRef.IMM));
    }
    if ((0x4000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[117]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x4000U & vlSelfRef.IMM));
    }
    if ((0x8000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[118]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x8000U & vlSelfRef.IMM));
    }
    if ((0x10000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[119]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x10000U & vlSelfRef.IMM));
    }
    if ((0x20000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[120]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x20000U & vlSelfRef.IMM));
    }
    if ((0x40000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[121]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x40000U & vlSelfRef.IMM));
    }
    if ((0x80000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[122]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x80000U & vlSelfRef.IMM));
    }
    if ((0x100000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[123]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x100000U & vlSelfRef.IMM));
    }
    if ((0x200000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[124]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x200000U & vlSelfRef.IMM));
    }
    if ((0x400000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[125]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x400000U & vlSelfRef.IMM));
    }
    if ((0x800000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[126]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x800000U & vlSelfRef.IMM));
    }
    if ((0x1000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[127]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x1000000U & vlSelfRef.IMM));
    }
    if ((0x2000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[128]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x2000000U & vlSelfRef.IMM));
    }
    if ((0x4000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[129]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x4000000U & vlSelfRef.IMM));
    }
    if ((0x8000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[130]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x8000000U & vlSelfRef.IMM));
    }
    if ((0x10000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[131]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x10000000U & vlSelfRef.IMM));
    }
    if ((0x20000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[132]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x20000000U & vlSelfRef.IMM));
    }
    if ((0x40000000U & (vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM))) {
        ++(vlSymsp->__Vcoverage[133]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x40000000U & vlSelfRef.IMM));
    }
    if (((vlSelfRef.IMM ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[134]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__IMM) 
               | (0x80000000U & vlSelfRef.IMM));
    }
    if ((1U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (1U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((2U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (2U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((4U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (4U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((8U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (8U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x80U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x100U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x100U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x200U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x200U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x400U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x400U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x800U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x800U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x1000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x1000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x2000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x2000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x4000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x4000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x8000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x8000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x80000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x100000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x100000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x200000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x200000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x400000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x400000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x800000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x800000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x1000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x1000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x2000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x2000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x4000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x4000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x8000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x8000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if (((vlSelfRef.arithmetic_unit__DOT__DATA ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[166]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    vlSelfRef.arithmetic_unit__DOT__operand_a = vlSelfRef.REG_A;
    if ((2U & (IData)(vlSelfRef.MOVI))) {
        if ((1U & (IData)(vlSelfRef.MOVI))) {
            vlSelfRef.arithmetic_unit__DOT__operand_b = 0U;
            ++(vlSymsp->__Vcoverage[235]);
        } else {
            ++(vlSymsp->__Vcoverage[234]);
            vlSelfRef.arithmetic_unit__DOT__operand_b 
                = vlSelfRef.IMM;
        }
    } else if ((1U & (IData)(vlSelfRef.MOVI))) {
        ++(vlSymsp->__Vcoverage[233]);
        vlSelfRef.arithmetic_unit__DOT__operand_b = vlSelfRef.MEM;
    } else {
        ++(vlSymsp->__Vcoverage[232]);
        vlSelfRef.arithmetic_unit__DOT__operand_b = vlSelfRef.REG_B;
    }
    ++(vlSymsp->__Vcoverage[236]);
    if ((1U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[168]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (1U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((2U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[169]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (2U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((4U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[170]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (4U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((8U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[171]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (8U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x10U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[172]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x10U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x20U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[173]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x20U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x40U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[174]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x40U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x80U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[175]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x80U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x100U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[176]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x100U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x200U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[177]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x200U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x400U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[178]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x400U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x800U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[179]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x800U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x1000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[180]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x1000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x2000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[181]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x2000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x4000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[182]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x4000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x8000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[183]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x8000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x10000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[184]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x10000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x20000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[185]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x20000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x40000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[186]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x40000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x80000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[187]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x80000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x100000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[188]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x100000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x200000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[189]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x200000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x400000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[190]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x400000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x800000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[191]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x800000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x1000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[192]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x1000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x2000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[193]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x2000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x4000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[194]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x4000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x8000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[195]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x8000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x10000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[196]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x10000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x20000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[197]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x20000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((0x40000000U & (vlSelfRef.arithmetic_unit__DOT__operand_a 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a))) {
        ++(vlSymsp->__Vcoverage[198]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x40000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if (((vlSelfRef.arithmetic_unit__DOT__operand_a 
          ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[199]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_a) 
               | (0x80000000U & vlSelfRef.arithmetic_unit__DOT__operand_a));
    }
    if ((1U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[200]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (1U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((2U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[201]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (2U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((4U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[202]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (4U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((8U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[203]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (8U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x10U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[204]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x10U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x20U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[205]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x20U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x40U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[206]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x40U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x80U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[207]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x80U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x100U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[208]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x100U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x200U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[209]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x200U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x400U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[210]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x400U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x800U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[211]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x800U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x1000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[212]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x1000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x2000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[213]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x2000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x4000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[214]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x4000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x8000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[215]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x8000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x10000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[216]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x10000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x20000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[217]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x20000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x40000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[218]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x40000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x80000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[219]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x80000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x100000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[220]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x100000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x200000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[221]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x200000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x400000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[222]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x400000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x800000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[223]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x800000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x1000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[224]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x1000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x2000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[225]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x2000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x4000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[226]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x4000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x8000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[227]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x8000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x10000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[228]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x10000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x20000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[229]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x20000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if ((0x40000000U & (vlSelfRef.arithmetic_unit__DOT__operand_b 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b))) {
        ++(vlSymsp->__Vcoverage[230]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x40000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
    }
    if (((vlSelfRef.arithmetic_unit__DOT__operand_b 
          ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[231]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__operand_b) 
               | (0x80000000U & vlSelfRef.arithmetic_unit__DOT__operand_b));
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
    vlSelfRef.__VactTriggered.set(0U, (((IData)(vlSelfRef.CLK) 
                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK__0))) 
                                       | ((IData)(vlSelfRef.RST) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__RST__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__CLK__0 = vlSelfRef.CLK;
    vlSelfRef.__Vtrigprevexpr___TOP__RST__0 = vlSelfRef.RST;
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
    CData/*1:0*/ __Vdly__arithmetic_unit__DOT__mul_counter;
    __Vdly__arithmetic_unit__DOT__mul_counter = 0;
    CData/*0:0*/ __Vdly__arithmetic_unit__DOT__mul_busy;
    __Vdly__arithmetic_unit__DOT__mul_busy = 0;
    // Body
    __Vdly__arithmetic_unit__DOT__mul_busy = vlSelfRef.arithmetic_unit__DOT__mul_busy;
    __Vdly__arithmetic_unit__DOT__mul_counter = vlSelfRef.arithmetic_unit__DOT__mul_counter;
    if (vlSelfRef.RST) {
        ++(vlSymsp->__Vcoverage[250]);
        vlSelfRef.arithmetic_unit__DOT__DATA = 0U;
        vlSelfRef.arithmetic_unit__DOT__DATA_VALID = 0U;
        __Vdly__arithmetic_unit__DOT__mul_counter = 0U;
        __Vdly__arithmetic_unit__DOT__mul_busy = 0U;
    } else {
        if (((IData)(vlSelfRef.ACT) & (~ (IData)(vlSelfRef.arithmetic_unit__DOT__mul_busy)))) {
            if ((2U == (IData)(vlSelfRef.OP_CODE))) {
                ++(vlSymsp->__Vcoverage[243]);
                vlSelfRef.arithmetic_unit__DOT__DATA_VALID = 0U;
                __Vdly__arithmetic_unit__DOT__mul_counter = 0U;
                __Vdly__arithmetic_unit__DOT__mul_busy = 1U;
            } else {
                vlSelfRef.arithmetic_unit__DOT__DATA_VALID = 1U;
                if ((0U == (IData)(vlSelfRef.OP_CODE))) {
                    ++(vlSymsp->__Vcoverage[240]);
                    vlSelfRef.arithmetic_unit__DOT__DATA 
                        = (vlSelfRef.arithmetic_unit__DOT__operand_a 
                           + vlSelfRef.arithmetic_unit__DOT__operand_b);
                } else if ((1U == (IData)(vlSelfRef.OP_CODE))) {
                    ++(vlSymsp->__Vcoverage[241]);
                    vlSelfRef.arithmetic_unit__DOT__DATA 
                        = (vlSelfRef.arithmetic_unit__DOT__operand_a 
                           - vlSelfRef.arithmetic_unit__DOT__operand_b);
                } else if ((3U == (IData)(vlSelfRef.OP_CODE))) {
                    ++(vlSymsp->__Vcoverage[242]);
                    vlSelfRef.arithmetic_unit__DOT__DATA 
                        = ((0U != vlSelfRef.arithmetic_unit__DOT__operand_b)
                            ? VL_DIV_III(32, vlSelfRef.arithmetic_unit__DOT__operand_a, vlSelfRef.arithmetic_unit__DOT__operand_b)
                            : 0U);
                }
                ++(vlSymsp->__Vcoverage[244]);
            }
            ++(vlSymsp->__Vcoverage[249]);
        } else if (vlSelfRef.arithmetic_unit__DOT__mul_busy) {
            if ((2U == (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter))) {
                ++(vlSymsp->__Vcoverage[245]);
                vlSelfRef.arithmetic_unit__DOT__DATA_VALID = 1U;
                vlSelfRef.arithmetic_unit__DOT__DATA 
                    = (vlSelfRef.arithmetic_unit__DOT__operand_a 
                       * vlSelfRef.arithmetic_unit__DOT__operand_b);
                __Vdly__arithmetic_unit__DOT__mul_counter = 0U;
                __Vdly__arithmetic_unit__DOT__mul_busy = 0U;
            } else {
                __Vdly__arithmetic_unit__DOT__mul_counter 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter)));
                ++(vlSymsp->__Vcoverage[246]);
            }
            ++(vlSymsp->__Vcoverage[247]);
        } else {
            ++(vlSymsp->__Vcoverage[248]);
            vlSelfRef.arithmetic_unit__DOT__DATA_VALID = 0U;
        }
        ++(vlSymsp->__Vcoverage[251]);
    }
    ++(vlSymsp->__Vcoverage[252]);
    vlSelfRef.arithmetic_unit__DOT__mul_busy = __Vdly__arithmetic_unit__DOT__mul_busy;
    vlSelfRef.arithmetic_unit__DOT__mul_counter = __Vdly__arithmetic_unit__DOT__mul_counter;
    if (((IData)(vlSelfRef.arithmetic_unit__DOT__mul_busy) 
         ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_busy))) {
        ++(vlSymsp->__Vcoverage[239]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_busy 
            = vlSelfRef.arithmetic_unit__DOT__mul_busy;
    }
    if (((IData)(vlSelfRef.arithmetic_unit__DOT__DATA_VALID) 
         ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA_VALID))) {
        ++(vlSymsp->__Vcoverage[167]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA_VALID 
            = vlSelfRef.arithmetic_unit__DOT__DATA_VALID;
    }
    vlSelfRef.DATA_VALID = vlSelfRef.arithmetic_unit__DOT__DATA_VALID;
    if ((1U & ((IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter) 
               ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)))) {
        ++(vlSymsp->__Vcoverage[237]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter 
            = ((2U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)) 
               | (1U & (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter)));
    }
    if ((2U & ((IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter) 
               ^ (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)))) {
        ++(vlSymsp->__Vcoverage[238]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter 
            = ((1U & (IData)(vlSelfRef.arithmetic_unit__DOT____Vtogcov__mul_counter)) 
               | (2U & (IData)(vlSelfRef.arithmetic_unit__DOT__mul_counter)));
    }
    vlSelfRef.DATA = vlSelfRef.arithmetic_unit__DOT__DATA;
    if ((1U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[135]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffeU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (1U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((2U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[136]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffdU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (2U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((4U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[137]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffffbU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (4U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((8U & (vlSelfRef.arithmetic_unit__DOT__DATA 
               ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[138]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffff7U & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (8U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[139]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffefU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[140]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffdfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[141]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffffbfU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x80U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                  ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[142]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffff7fU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x100U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[143]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffeffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x100U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x200U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[144]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffdffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x200U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x400U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[145]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffffbffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x400U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x800U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                   ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[146]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffff7ffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x800U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x1000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[147]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffefffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x1000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x2000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[148]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffdfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x2000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x4000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[149]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffffbfffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x4000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x8000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                    ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[150]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffff7fffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x8000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[151]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffeffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[152]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffdffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[153]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfffbffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x80000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                     ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[154]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfff7ffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x100000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[155]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffefffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x100000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x200000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[156]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffdfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x200000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x400000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[157]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xffbfffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x400000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x800000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                      ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[158]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xff7fffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x800000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x1000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[159]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfeffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x1000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x2000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[160]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfdffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x2000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x4000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[161]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xfbffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x4000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x8000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                       ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[162]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xf7ffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x8000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x10000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[163]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xefffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x10000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x20000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[164]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xdfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x20000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if ((0x40000000U & (vlSelfRef.arithmetic_unit__DOT__DATA 
                        ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA))) {
        ++(vlSymsp->__Vcoverage[165]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0xbfffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x40000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
    if (((vlSelfRef.arithmetic_unit__DOT__DATA ^ vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
         >> 0x1fU)) {
        ++(vlSymsp->__Vcoverage[166]);
        vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA 
            = ((0x7fffffffU & vlSelfRef.arithmetic_unit__DOT____Vtogcov__DATA) 
               | (0x80000000U & vlSelfRef.arithmetic_unit__DOT__DATA));
    }
}
