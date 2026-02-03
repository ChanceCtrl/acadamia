#phys2211 

A point which follows the trajectory predicted by the newton's laws of motion, as if all the mass of the system is concentrated at a single point. 

## How do you find the center of mass of an object with a simple experiment?

We can use the fact that center of mass of a regular size object near the surface of the Earth is almost the same as its center of gravity.

One method is to hang an object from two separate points, drawing a line following gravity for both, and you should have the COM.

$$\Sigma m_{n}\vec R_{n} = 0$$

For each dimension
$$\vec R_{CM} = \frac{\Sigma_{i}m_{i}\vec r_{i}}{M}$$
$$X_{CM} = \frac{\Sigma_{i}m_{i}x_{i}}{M}$$
$$Y_{CM} = \frac{\Sigma_{i}m_{i}y_{i}}{M}$$
$$Z_{CM} = \frac{\Sigma_{i}m_{i}z_{i}}{M}$$

## Center of mass of a continuous mass distribution
$$\vec R_{CM} = \frac{\int dm*\vec r}{\int dm}$$
$$X_{CM} = \frac{\int dm*x}{\int dm}$$
$$Y_{CM} = \frac{\int dm*y}{\int dm}$$
$$Z_{CM} = \frac{\int dm*z}{\int dm}$$

## Kinematics and dynamics of COM
$\vec R_{CM} = \frac{\Sigma_{i}m_{i}\vec r_{i}}{M}$ =d/dt> $\vec V_{CM} = \frac{\Sigma_{i}m_{i}\vec v_{i}}{M}$ =d/dt> $\vec A_{CM} = \frac{\Sigma_{i}m_{i}\vec a_{i}}{M}$

## System of particles
If all the forces are internal, then no matter what happens the center of mass will not change. 
All internal forces are action-reaction forces which are pairs of equal and opposite forces

$$M\vec A_{CM} = \Sigma m_{i}\vec a_{i} = \Sigma \vec F_{i} = \Sigma \vec F_{ext} + \Sigma \vec F_{i} = 0$$

# Rotation
## Rotational Kinematics
There are a lot of situations when the objects rotate about their center of mass while moving.

Displacement   $\Delta \vec X = \Delta \theta$   Angular Displacement
Velocity            $\vec v = \vec w$                              Angular velocity
Acceleration     $\vec a = \vec \alpha$                    Angular acceleration
Mass                 $m = I$                                                Moment of inertia
Force                 $\vec F = \vec \tau$                       Torque

### Rotational plus transnational kinetic energy
$$K = \frac{1}{2}mv^{2}_{cm} + \frac{1}{2}I_{cm}w^{2}$$
$v_{cm}$ and $w$ are not always related. For example if the object is slipping and rolling, the two values are different, but if the object is only rolling, then they are related like so.
$$K = \frac{1}{2}(M + \frac{I_{cm}}{R^{2}})v^{2}_{cm}$$

#### Conservation of Energy
Conservation of energy is the presences of non-conservative forces in the absensce of other transfers.
$$\Delta K + \Delta U = W_{nc}$$
$$K_{f}-K_{i}+U_{f}-U_{i} = W_{nc}$$
**Static friction does not do any work**

#### Work-Kinetic energy theorem
The rotational kinetic energy is given by: $$K = \frac{1}{2}Iw^{2}$$

#### Rod about an axis with L/2
$$K = \frac{1}{2}(\frac{1}{3}ML^{2})w^{2} = \frac{1}{6}ML^{2}w^{2}$$
or
$$K = \frac{1}{2}Mv^{2}_{cm} + \frac{1}{2}I_{cm}w^{2}$$

### Relation between translation and rotational variables.
For any point on a rigid body rotating about a fixed axis, suppose S is the arc length traveled by that point;
**Because r remains constant for each point.**
$s = r\Theta$ =$\frac{d}{dt}$> $v = rw$ =$\frac{d}{dt}$> $a = r \alpha$

### Conservation of anuglar momentum
If the net external torque on a system is zero, then the total angular momentum is conserved.

### Gyroscopic Motion
If your net external torque in the system is in the direction of $\vec{w}$, it increases in that direction. And it will increase in the opposite direction if it is in the opposite direction of $\vec{w}$

### Angular displacement $\theta$
The angular displacement with respect to some chosen orientation is the same for all points of a rigid body rotating about a fixed axis. **$\theta$ is measured in radians**

### Angular Velocity $\vec w$
Angular Velocity is a vector defined as follows
$$\text{Angular speed} = |\vec w| = w = \frac{d\theta}{dt}$$
$$w_{avg} = \frac{\Delta\theta}{\Delta t}$$ where w is measured in (rad/s)

In the case of uniform rotating $w_{avg}$ is the same as instantaneous angular velocity $w$.

Angular velocity $\vec w$ is a vector ***but*** angular displacement $\Delta\theta$ is not

### Angular Acceleration $\vec \alpha$
Angular acceleration is a vector defined as follows
$$\text{Angular Accceleration} = \vec \alpha =\frac{d\vec w}{dt}$$
$$\vec \alpha_{avg} = \frac{\Delta \vec w}{\Delta t}$$ where $\vec \alpha$ is measured in (rad/s^2)

### Rotational kinematics with constant angular acceleration
#### $a = \text{const.}$
#### $w = at + w_{i}$ => $v = at + v_{i}$
#### $\Delta \theta = \frac{1}{2}at^{2} + w_{0}t$ => $\Delta x = \frac{1}{2}at^{2} + v_{0}$

### Moment of Inertia of a continuous mass distribution
$$I = mr^{2}$$
$$I = \Sigma I_{i}$$
$$I = \int r^{2}dm$$

## Rotational Dynamics

Displacement   $\Delta \vec X = \Delta \theta$   Angular Displacement
Velocity            $\vec v = \vec w$                              Angular velocity
Acceleration     $\vec a = \vec \alpha$                    Angular acceleration
Mass                 $m = I$                                                Moment of inertia
Force                 $\vec F = \vec \tau$                       Torque

We'll see that the kinetic energy also has a rotational counterpart
$$K = \frac{1}{2}Iw^{2}$$

### Torque
When systems have freedom to rotate, it matters where you exert the force.
$$\tau \alpha F$$

#### Defining a Torque
$$\tau = r F_{t} = rFsin\phi$$
Or if you are feeling zesty you can use the perpendicular of r times the force to get $\tau$

As a vector :
$$\vec \tau - \vec r * \vec F$$

Also this just kinda scales with whatever you throw at it mass and force wise
$$\tau = \Sigma r_{i}F_{i}$$

#### How is torque related to angular acceleration?
$$\tau = rF_{t} = rma$$
$$a = ra$$
$$\tau mr^{2} a = Ia$$
$mr^{2}$ is the m in $F = ma$ With **$I$** being your moment of inertia

##### Torque by gravity
$$\tau = rMgsin\phi$$

Once again this shit just kinda go up
$$\tau = (\Sigma m_{i}r_{i}^{2})a$$

#### Work energy shit
$$\frac{1}{2}Iw^{2}$$

### Angular momentum
its def is
$$\frac{d\vec{L}}{dt} = \vec{\tau}$$

and it should be something like
$$\vec{L} = \vec{r} * \vec{p} = m\vec{r}*\vec{v}$$
or
$$mrvsin\phi$$

###### But really just use this if the system rotates about a fixed axis in a circular path
$$L = Iw$$

## Parallel Axis Theorem
If we have the moment of inertia of an object spinning about an axis passing through its center mass which is given, we can easily calculate its moment of inertia about any other axis parallel to the first located at some distance **d**.
$$I_{0} = I_{CM} + Md^{2}$$
$I_{CM} = \text{Moment of intertia from the center of mass}$

## Rolling objects
Rolling without slipping always implies the condition:
$X_{cm} = R\theta$,  $v_{cm} = Rw$, $a_{cm} = R\alpha$

Static friction is required to change its speed, otherwise it would just slip.

# Vector Algebra
Cross product (the result is a vector)
$$|\vec A * \vec B| = |A||B|sin\theta$$

- The direction is obtained by right hand rule
$$\vec A * \vec B = -\vec B * \vec A$$

- We can also find cross porduct like so
$$\vec A * \vec B = (A_{x}B_{z} - A_{z}B_{x})i + (A_{y}B_{x} - A_{x}B_{y})j + (A_{x}B_{y} - A_{y}B_{x})k$$