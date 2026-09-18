#phys2211 

# Beam
A **3kg** beam of length **0.5m** is hinged through a horizontal axis through point **O** and released from rest in the **horizontal position**. What is the angular acceleration just after it is released?

$$\tau = mg \frac{L}{2} = I\alpha - \frac{1}{3}mL^{2}\alpha$$
$$\alpha = \frac{3g}{2L}$$

Find the force at the hinge on the beam at this instant

$$F_{net} = mg - F_{p} = m a_{cm} = mR_{cm}\alpha$$
$$mg-F_{p} = m \frac{L}{2} \frac{3g}{2L}$$
$$F_{p} = mg - \frac{3mg}{4} = \frac{mg}{4}$$

# Disk
A uniform disk of mass *2.5kg* and radius *20cm*, is mounted on a fixed horizontal axle. A block with mass *1.2kg* hangs from a mass-less cord that is wrapped around the rim of the disk. Find the acceleration of the falling block, the angular acceleration of the disk, and the tension in the cord. The cord does not slip, and there is *no friction* in the axle.

$$a = R\alpha$$
$$m_{block}: mg - T = ma$$
$$m_{disk}: \tau = TR = I\alpha$$

Baller, now do the thing

$$mg - T = ma$$
$$T = \frac{I\alpha}{R} = \frac{Ia}{R^{2}}$$
$$mg = ma + \frac{I}{R^{2}}a$$
vry niace
$$a = \frac{mg}{m+\frac{I}{R^{2}}} = a \frac{2m_{b}g}{2m_{b}+m_{d}}$$

# Block with friction
In the system shown in the picture the pulley is a uniform disk, with *0.5kg and R = .1m*. How much force is needed to move the object in the figure with an acceleration of $2 \frac{m}{s^{2}}$, if the mass of the object is *0.5kg* and there is no friction between the object and the surface? (The picture shows a cube pulled to the right by a string that bends downwards by a pulley).

$$T_{1} = ma$$
$$\tau_{net} = T_{2}R - T_{1}R = I\alpha$$

# Atwood's Machine with BIG pulley
Suppose that the pulley has a mass M and Radius R, and the strings are mass less and don't slip. Find the acceleration of this system and the tensions in the string as a function of the masses, radius of the pulley and the gravitational acceleration.

$$m_{1}: m_{1}g - T_{1} = m_{1}a_{1}$$
$$m_{2}: T_{2} - m_{2}g = m_{1}a_{1}$$
$$m_{p}: T_{1}R - T_{2}R = I\alpha = I \frac{\alpha}{R}$$

solve

$$a = \frac{m_{1}g-m_{2}g}{m_{1}+m_{2} + \frac{I}{R^{2}}}$$

# Roll down ramp
A uniform spherical shell of mass *M* and radius *R* rolls down a ramp of inclination $\theta$. Find the acceleration of the ball.

Free body diagram with decomposed forces
![[Roll down slope]]

$$f_{net}x  = mgcos\theta - f_{s} = ma_{cm}$$
$$\tau = f_{s}R = I\alpha$$
$$F_{s} = \frac{Ia_{cm}}{R^{2}}$$
$$mgsin\theta = \frac{Ia_{cm}}{R^{2}} + ma_{cm}$$
$$a_{cm} : \frac{mgsin\theta}{m+(\frac{I}{R^{2}})}$$
$$a_{cm} = \frac{gsin\theta}{I+b}$$

# Yes
A mass less string is wrapped 0 times around a disk of mass *M = 4kg* and radius *R = .1m*. The disk is constrained to spin without friction about a fixed axis passed through its center, The string is pulled with a force *F = 10N* until it has unwound. Assume the string does not slip, and that the disk is initially at rest. How fast is the disk spinning after the string is fully unwound?

# Long Pendulum
Ball on end of stick is *0.5 kg* and the stick is *.8 m* long

a) What is the angular acceleration of the pendulum at 30?
$$\tau = I\alpha$$
$$\tau = rgsin(30)$$
$$\tau = (.8)(.5)(10)sin(30) = 2$$
$$\alpha = \frac{\tau}{mr^{2}}$$
$$\alpha = \frac{2}{.5*.8^{2}}$$

#### Now the length is *1m* and the stick has no balls but weighs *3kg*
$$mg \frac{L}{2} = (\frac{1}{2}mL^{2} + \frac{mL^{2}}{4})w^{2}$$
$$\frac{g}{2}=\frac{L}{3}w^{2}$$
$$w = \sqrt{\frac{3g}{2L}}$$

# Balls
A uniform sperical shell of mass M and radius R rolls down a ramp of inclination *30* starting from rest. *find the vel* at the bottom of the ramp in terms of whatever. The height of the ramp is *h*.

Use conservation of energy
$$U_{i} + K_{i} + W_{nc} = U_{f} + K_{f}$$

Throw in ya shit
$$mgh = \frac{1}{2}mv^{2}_{cm} + \frac{1}{2}I_{cm}w^{2}$$

some defs for $V_{cm}$
$$V_{cm} = Rw => w = \frac{V_{cm}}{R}$$

Simplify
$$V_{cm} = \sqrt{\frac{6gh}{something}}$$