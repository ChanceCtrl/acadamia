#phys2211 
### Two masses over fulcrum (DYNAMICS)
#### Find angular acceleration of the system in terms of the force $F$, angle $\phi$, masses $m$ and $M$, and the length $L$

$$\tau_{net} = I\alpha$$
$$\tau_{1} = \frac{1}{4}(mg)sin(90) = \frac{mgL}{4}$$
$$\tau_{2} = \frac{1}{4}(Mg)sin(90) = \frac{-Mgl}{4}$$
$$\tau_{3} = \frac{3L}{4}Fsin\phi$$
thus
$$\tau_{net} = \frac{mgL}{4} + \frac{3L}{4}Fsin\phi - \frac{Mgl}{4} = I_{tot}\alpha$$
where $I_{tot}$
$$I_{tot} = m(\frac{L}{4})^{2} + (\frac{1}{12}ML^{2}+M(\frac{L}{4})^{2})$$
So
$$\frac{\tau_{net}}{I_{tot}} = \alpha$$

#### Find the force F that keeps the system in equilibrium
$$\tau_{net} = \frac{mgL}{4} + \frac{3L}{4}Fsin\phi \frac{-MgL}{4} = 0$$

### Bar hung by strings (DYNAMICS)
#### Can we find $T_{1}, T_{2}$ given that the system is in equilibrium?
$$\Sigma F = 0, \Sigma \tau = 0$$
$$F_{net} = T_{1} + T_{2} - mg = 0$$
$$\tau_{net} = r_{2}T_{2}sin(90) - r_{1}T_{1}sin(90) = 0$$
goes into
$$\frac{L}{4}T_{2} = \frac{L}{2}T_{1} => T_{2} = 2T_{1}$$
$$T_{1} + 2T_{1} = mg$$
So $T_{1} = \frac{mg}{3}$ and $T_{2} = \frac{2mg}{3}$

### Ball rolling up ramp by string (ROTATIONAL + TRANSNATIONAL)
#### A uniform disk shape wheel of mass $M$ and radius $R$ is being pulled up by a constant force $F$ on a ramp of inclination $\Theta$. Find the acceleration of the ball. Assume 0 slip.

We can say that $F_{net} = ma_{cm}$, and then we can write out newton's shit $$F_{net} = F - mgsin\phi - f_{s} = ma_{cm}$$
Now we can write out our net torque $$\tau_{net} = RF + Rf_{s} = I\alpha$$
We can get alpha from $a_{cm} = R\alpha$, and now we add the two systems together.
$$(F - mgsin\phi - f_{s}) + (F + f_{s}) = (ma_{cm} + \frac{Ia_{cm}}{R^{2}}) $$
Which gives us
$$2F - mgsin\phi = \left(m + \frac{I}{R^{2}}\right)a_{cm}$$
Which simplify down into this if we say $I = \frac{1}{2}mR^{2}$
$$???$$

### Ball falling with string (WORK)
#### The string unwraps without slipping and the disk goes down, what is the speed of the disk after descending the height h?
We are looking for $v_{f}$ so we can write out work theorem $U_{i} + K_{i} + W_{nc} = U_{f} + K_{f}$ and we can cancel some out giving us $U_{i} + 0 + 0 = 0 + K_{f}$, subbing in formulas for things we get
$$mgh = \frac{1}{2}mv^{2}_{f} + \frac{1}{2}Iw^{2}$$
and we can make it simpler with $w_{f} = \frac{v_{f}}{R}$ => $$mgh = \frac{1}{2}mv^{2}_{f} + \frac{1}{2} \frac{v^{2}_{f}}{R^{2}}$$