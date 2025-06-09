PWD = $(shell pwd)

TOPLEVEL_LANG ?= verilog

SIM ?= verilator
EXTRA_ARGS += --coverage

VERILOG_SOURCES += $(PWD)/arithmetic_unit.sv
TOPLEVEL = arithmetic_unit
MODULE = test_arithmetic_unit

include $(shell cocotb-config --makefiles)/Makefile.sim
