reset_cp = coverpoint('RST')
reset_val = normal_bins(reset_cp, (0, 1), at_least=1)
reset_seq = sequence(reset_cp, [0, 1, 0])
