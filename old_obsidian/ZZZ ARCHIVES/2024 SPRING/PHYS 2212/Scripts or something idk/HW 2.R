#
##
### Uniform disk charge at given Z
##
# Given values
sigma = 6.6e-3  # C/m^2
R = 0.4  # m
z = 2  # m
k = 8.85e-12  # C^2/(N*m^2)

# Calculate electric field (E) of a disk
E_1 = (sigma/(2*k))* (1-(z/(sqrt(R**2 + z**2))))

E_1 * 1.E-6  # Electric field in MN/C

#
##
### Uniform rod charge at given x from origin
##
# Given values
L = 0.10 # m
x = 0.36 # m
Q = (20e-6) # uC
k = 8.99e9  # C^2/(N*m^2)

# Calc distance from mid point 
z = (x - (L/2))

E_2 = (k * Q) / (z * (L + z))

#
##
### idek
##
# Desmos 
\left|\frac{\left(2\pi\left(8.99\cdot10^{9}\right)\left(-7.5\cdot10^{-6}\right)\right)}{\left(.115\right)^{2}}\right|
