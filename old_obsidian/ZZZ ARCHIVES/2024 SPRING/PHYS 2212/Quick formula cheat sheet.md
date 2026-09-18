#phys2212 
# Constants / Var Defs
Coulomb constant: $k_{e} = 8.99 * 10^{9}$ as $\frac{Nm^{2}}{C^{2}}$
Vacuum permittivity: $\epsilon_{0} = 8.85 * 10^{-12}$ as $\frac{C^{2}}{Nm^{2}}$
q = electric field
r = some distance in $m$
d = also some distance in $m$
$\kappa = \frac{E_{o}}{E}$
Avogadro's constant: $N_{A}$ = $6.022 * 10^{23}$
Elementary charge of an electron: $q_{e}$ =  $1.602 * 10^{-19}$
Mass of an electron: $m = 9.11 * 10^{-31}$
Permeability of free space: $\frac{Tm}{A} = u_{0} = 4\pi * 10^{-7}$
turns per unit length: $n = \frac{N}{l}$ 

# Chap 22
### Field force at point from one element
$$F_{e} = k_{e}\frac{|q_{1}||q_{2}|}{r^{2}}$$

### Field force at point from all elements
$$k_{e} \int \frac{dq}{r^{2}} \vec r$$

### Net force
$$\Sigma \vec F = q\vec E = m\vec a$$

### Flux for flat area
$$\phi_{E} = EAcos\theta$$
(the cos makes it perpendicular)

### Potential or something
$$V = k_{e} \frac{q}{r}$$
oh and V is scalar btw

# Chap 24
### Potential difference in a uniform field
$$E = - \frac{\Delta V}{d}$$
($\delta V$ is the delta of difference of fields)

### Capacitance
$$C = \frac{Q}{\Delta V}$$
$$C = \frac{\epsilon_{0}A}{d}$$

#### Plate capacitor with dialectic
$$C = \kappa * \frac{\epsilon_{0}A}{d}$$
(kappa is the dialectic constant)

### Surface charge of a conductor
$$E = \frac{\sigma}{\epsilon_{0}}$$

# RC circuits
### Time constant
$$\tau = R * C$$
with $\tau$ in seconds

### Max charge on the cap
$$Q_{max} = C * V$$
with Q in Columbus

### Charge after given time connected
$$Q = \frac{V}{R} * e^{\frac{-t}{\tau}}$$

### Charge after given time disconnected
$$Q = Q_{max} * (1 - e^{\frac{-t}{\tau}})$$

# Electron Dynamics (ED)
## Velocity of a particle
$$v = \frac{E}{B}$$
for some reason now E is the particles charge and B is the field strength

## Mass of a particle
$$\frac{m}{q} = \frac{rBB_{0}}{R}$$
m = mass, q = charge, B is field, B0 is the velocity selectors field, r is the gyroradius(?), and R is the radius of deflection.

## Force on a particle
$$F = qVB$$
or
$$F = i(LB)$$

## Time spent in a field going in a circle
$$T = \frac{2\pi * M}{qb}$$
$M$ is the mass of the particle
$q$ is charge of the particle in colombs
$b$ is strength of the field in Tesla

# Chap 28
## the magnetic field due to the current in the wire
$$B = \frac{u_{0}I}{4\pi a} (sin\Theta_{2} - sin\Theta_{1})$$
$B$ is in Tesla
$u_{0}$ is the permeability of free space
$a$ is the vertical distance from the wire
$\Theta_{1}$ & $\Theta_{2}$ is the angles from vertical 

### And if that wire is infinantly long
$$B = \frac{u_{0}I}{2\pi a}$$

### And if its a closed loop
$$B = u_{0}I$$

# Chap 30+
## Induced EMF
$$E_{L} = -L \frac{di}{dt}$$

### For a coil of N turns
$$L = \frac{N\phi_{B}}{i}$$
or something like this
$$L = \mu_{0}n^{2}V$$
$L$ being in Henrys
$\mu_{0}$ being a constant
$n = \frac{N}{l}$ or turns per meter
$V = Al$