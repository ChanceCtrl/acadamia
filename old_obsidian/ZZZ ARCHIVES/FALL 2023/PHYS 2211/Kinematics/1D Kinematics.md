#phys2211 
# The state of a system is described by a set of qualities and quantities and we try to evaluate and measure them.

Location, Speed, Volume, Temperature, Pressure, Electric charge, etc.

## In **mechanics**, state of the system is described by its motion, energy, and forces.
We want to explain and track the changes in these properties of the systems and objects.
All you need is the position and momentum to know everything about the mechanics of a system

## What about time?
Embedded in the concept of change time is evolving as an independent and universal variable in classical mechanics, but Einstein changed our understanding tho.

# 1D Kinematics is the study of motion of objects in straight line in one dimension. 

## How do we describe a motion?
1. Location (Position)
1. Time
2. Speed (Velocity)
3. Change of speed (Acceleration)
4. Change of acceleration (Jerk)


## There are different types of physical quantities

### Scalars and Vectors
- A Scalar quantity only has a magnitude. They add or multiply to another scalar like numbers
- Vectors have magnitude and direction. We need to learn vector algebra to handle vector operations

## Coordinate system and position?
- You must choose a reference point as origin. Keep it consistent.
- Choose the axes and number of dimensions depending on the problem
- Then position is a vector from the origin to the location
- ^i, ^j, ^k are the unit vectors of directions x, y, z.


### Distance and Displacement
Distance is total length traveled, |f(x)|, and is a scalar quantity
- Speed = (delta(|f(x|))/delta(t))

Displacement is distance from start, f(x), and is a vector quantity 
- Velocity = (delta(f(x))/delta(t))

###### simplification for 1D kinematics
You can drop the ^i for just + or - due to the nature of only having 1 dimension....... what the fuck am I doing here bruh

## Instantaneous Velocity/Acceleration
Find derivative of velocity
or the slope of the tangent line
its fucking acceleration bruh

$$a_{avg}= \frac{delta{v}}{delta{t}} = \frac{V_f-V_i}{delta{t}}$$

## Constant Acceleration Motion
$$a_{x}= lim {\frac{v_{x}}{t}=\frac{dv_{x}}{dt}}$$
Constant Acceleration means:
$$a_{x}(t) = a_{x avg}...$$

For an object moving with constant acceleration, velocity changes linearly with time as follows:
$$v_{x}(t) = a_{x}t+v_{xi}$$
Where $$v_{xi}$$ is the initial velocity, that is the velocity at t=0

Only for a constant acceleration motion:
$$V_{x avg}(t)=\frac{v_{x}(t) + v_{xi}}{2}$$
or
$$x(t)=\frac{1}{2}at^{2}+v_{xi}t+x_{i}$$

##### Analysis model of constant acceleration
A more formal and general way of deriving the model using calculus;
$$\frac{da_{x}(t)}{dt} = 0$$
Integral
$$a_{x}(t) = a_{x}$$

## Categorizing 1D motions
1. Constant velocity or uniform motion 
$$a=0$$
$$v(t) = v_{0}$$
$$v_{x}t + x_{i}$$
2. Constant acceleration
$$v(t) = at+v_{i}$$
$$x(t) = \frac{1}{2}at^{2}+v_{x}t+x_{i}$$
3. Constant jerk
Take the integral of the previous

## Free Fall
- An object moving upward or downward only under gravity, experiences "free fall".
- Free fall near the surface of the earth is approximated by a constant acceleration motion
- The earth's gravitational acceleration near the surface is always h = 9.81 m/s^2 down.
- g is the same for any object regardless of its mass.

## Vectors
Vectors are expressed:
1. Graphically, like an arrow
	Sometimes we can handle the vectors by using a set of graphical rules for + and -
2. Algebraically
	We may choose a coordinate system to show the vector by components. For example in 2D Cartesian system (x, y) or polar coordinates (theta, r)

### Algebraic presentation of vectors
Any vector ->A in two dimensions can be decomposed into two perpendicular components, name them x-component A_(x) and y-component A_(y)
$$A^{->}=A^{->}_{x}+A^{->}_{y}$$