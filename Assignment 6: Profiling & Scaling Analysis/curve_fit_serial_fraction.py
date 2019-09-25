# Jean-Michel Boudreau
# February 26, 2018

### Import Dependencies ###
# Import numpy
import numpy as np
# Import curve_fit from scipy package
from scipy.optimize import curve_fit

### Define Speed up function for use with curve)fit from scipy package ###
def speedUpFunc(p, f):
	return 1/(f + (1 - f)/p)

### Hardcode data taken from results.txt for fitting to anal. func. above ###

# Create a linespace for the number of cores (i.e. vec. of 1-8 increment by 1)
numCore = np.linspace(1, 8, 8)

# Wall Times 
wallTime = np.array([1, 1.9759, 2.8545, 3.9158, 4.4751, 5.2081, 6.2239, 7.5354])

### Estimate serial fraction by fitting to speed up function ###
fEst, fCov = curve_fit(speedUpFunc, numCore, wallTime)
# Print result to user
print("The estimated value of the serial fraction 'f' is:")
print(fEst[0])
