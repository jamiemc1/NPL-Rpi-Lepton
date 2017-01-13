#!/usr/bin/python

import numpy as np
import argparse
from datetime import datetime
from pylepton.Lepton3 import Lepton3


# Define the argument parser
parser = argparse.ArgumentParser()

# Add the output argument
parser.add_argument('-o', '--output', help='Output file', required=True)

# Parse the arguments
args = parser.parse_args()

# Check there is an output file
if len(args.output) < 1:
	print "Specify an output file."
	sys.exit(1)

# Capture a frame from the Lepton 
with Lepton3() as l:
	arr,_ = l.capture()

# Determine the array dimensions
arr_dim = np.shape(arr)

# Identify current date and time
date_time = datetime.utcnow().strftime("%d-%m-%Y\t%H:%M:%S.%f")[:-3]

# Open a file in memory
tmp_file = open(args.output, 'w')
try:

# Write header to output file

	tmp_file.write("##############################################################\n")
	tmp_file.write("# \n")
	tmp_file.write("# File created using NPL-RPi-Lepton LeptonReadPy.py\n")
	tmp_file.write("# Based on pylepton https://github.com/groupgets/pylepton.git\n")
	tmp_file.write("# \n")
	tmp_file.write("# File created:\t%s\n" % date_time)
	tmp_file.write("# \n")
	tmp_file.write("# Image Cols:\t%i\n" % arr_dim[1])
	tmp_file.write("# Image Rows:\t%i\n" % arr_dim[0])
	tmp_file.write("# \n")
	tmp_file.write("# Column headers:\n")
	tmp_file.write("# Row\tColumn\tSignal\n")
	tmp_file.write("# \n")
	tmp_file.write("##############################################################\n")

# Write array to output file in coordinate format
	for j in range(arr_dim[0]):
		for i in range(arr_dim[1]):
			tmp_file.write("%03i\t%03i\t%06i\n" % (j, i, arr[j,i]))

# Close the file in memory regardless of any previous errors
finally:
	tmp_file.close()

