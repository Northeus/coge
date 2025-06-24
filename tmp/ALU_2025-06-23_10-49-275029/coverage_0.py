reset_cp = coverpoint('RST')
reset_val = normal_bins(reset_cp, (0, 1), at_least=1)
reset_seq = sequence(reset_cp, [0, 1, 0])

op_cp = coverpoint('OP')
op_val = normal_bins(op_cp, (0, 5))
cross = cross([op_val, reset_val])