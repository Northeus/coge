reset_cp = coverpoint('RST')
reset_val = normal_bins(reset_cp, (0, 1), at_least=1)
reset_seq = sequence(reset_cp, [0, 1, 0])

reg_a_cp = coverpoint('REG_A')
reg_a_val = normal_bins(reg_a_cp, (0, 5))
cross = cross([reg_a_val, reset_val])
