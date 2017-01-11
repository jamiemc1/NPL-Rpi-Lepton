#!/usr/bin/python

import numpy as np
import cv2
from pylepton.Lepton3 import Lepton3

with Lepton3() as l:
    arr_in,_ = l.capture()
arr_in_dim = np.shape(arr_in)

tmp_file = open('output.txt', 'w')
try:
	tmp_file.write("Row\tColumn\tSignal\n")
	for j in range(arr_in_dim[0]):
		for i in range(arr_in_dim[1]):
			tmp_file.write("%03i\t%03i\t%06i\n" % (j, i, arr_in[j,i]))
finally:
	tmp_file.close()

