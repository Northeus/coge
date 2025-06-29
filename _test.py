from coverage import *

vld = coverpoint('VLD')

transition_010 = sequence(vld, [0, 1, 0])
transition_0110 = sequence(vld, [0, 1, 1, 0])
