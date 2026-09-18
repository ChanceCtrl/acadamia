#phys2211 

# What is energy?
Lets say _energy_ is a physical scalar quantity associated with any existence, which is a measure of the ability to cause change. 

We know there are different types of energy (mechanical, chemical, nuclear, electrical, etc) in two forms: [[Kinetic Energy]] and [[Potential Energy]]. 

# Dont forces and Newton's laws tell us how systems change or cause changes?
They do, but not always quite easily and sometimes they just don't, because of complexity and unknown mechanisms. Also, energy is a scalar and usually easier to handle.

# Work
Energy and force are related through the concept of "Work". In physics, Work is the amount of _energy transferred_ by a force into or from a system. The work done by the constant force (F->) on the object over the distance ($\Delta \vec{x}$) is defined as

$$W = F \Delta \vec{x}$$

If it is a case of a constant stopping force it ($\Delta \vec{x}$) becomes negative

$$W = -F \Delta \vec{x}$$

**The SI unit of work and energy is joules**

Now we introduce the general definition of the work done by a constant force ($\vec F$) on an object over the displacement ($\Delta \vec{x}$)
$$W = \vec {F} cos(\theta) \Delta \vec{x}$$

# Work done by a varying force

## What if the force is not constant and/or the $\Theta$ is not constant?

We can resolve the issue by breaking up the path into very small segments; For each small segments of the path we are still allowed to write
$$dW = $$ Fuck

### Work done by gravity on an object moving _near surface of the earth_

$$W = \int_{r_{1}}^{r_{2}} \vec{F} * dl$$
$$W = -mg\Delta y$$

Now work done by the Earth on an object moving around the earth
$$W = \int \vec{F_{g}} * \vec{dl} = \int -G \frac{mM_{e}}{r^{2}} * \vec{dl}$$ 

$$W = GmM_{e}(\frac{1}{r_{2}} - \frac{1}{r_{1}})$$

$$\Delta U = -W = U_{2}-U_{1} = -(\frac{GmM_{e}}{r_{2}} - \frac{GmM_{e}}{r_{1}})$$
General Formula
$$E_{mec} = K + U = \frac{1}{2}kv^{2} - GmM_{e} \frac{1}{r}$$
Slightly more useful version of it
$$U = -GmM_{e}\frac{1}{r} = -2K$$

![[Escape velocity]]

### Work done by a spring
$$W = \int_{r_{1}}^{r_{2}} \vec{F_{s} * \vec{dl}} = \int_{x_{1}}^{x_{2}} -kx * dx$$
$$W = \frac{-1}{2}k(x_{2}^{2}-x_{1}^{2})$$

![[Work on a spring example]]

# idk
We said work is the transferred energy to a system and we defined as the dot product of all the forces

We are convey to define the scalar quantity kinetic energy as: 
$$K = \frac{1}{2}mv^{2}$$

Work Kinetic Energy Theorem 
$$W = \int_{r_{2}}^{r_{1}} \vec {F} * \vec{dl}$$

# Conservative Forces
The word done by a conservative force does not depend on the path but only on initial and final position.

## Non-Conservative Forces
The work done by a non-conservative force depends on the path in general
$$W_{ab,1} \DNE W_{ab,2}$$

For example for kinetic friction
$$W_{f}=-\mu_{k}N\Delta s$$

## What is conserved?
Work energy theorem: $$W = \Delta K$$
Kinetic energy: $$\frac{1}{2}mv^{2}$$
We define: $$\Delta K - W = 0$$
$$\Delta U = -W$$
so $$\Delta K + \Delta U = 0$$
Which all means that _K + U = Conserved_, This is only for conservative forces, we can find a universal function for U which depends only on position and not on path nor velocity.

## What we understand
- If all forces that do work on a system are conservative, then $E_{mec} = K + U$ is a conserved quantity under and change.
- K is energy associated with motion while U is the energy associated with position. $$K = \frac{1}{2}mv^{2}$$
$$W = -mg\Delta y$$
$\Delta U = U_{2}-U_{1} = -W = mg \Delta y = mgy_{2}-mgy_{1}$ **->** $U_{g} = mgy$

# Overview
We learned that for a conservative force $\vec{F}$:
$$\Delta U = -W = \int_{r_{1}}^{r_{2}} \vec{F} * dl$$

If the derivative of potential is zero, the force is zero. This notion helps us to analyze the motion and stability of systems. 

# Non-Conservative Forces

Energy of the system in the presence of non-conservative forces:
$\Delta K = W_{c}+W_{NC}$ ***->*** $\Delta K = -\Delta U + W_{NC}$

When we talk about potential energy, we are including the source of the conservative force in the system, instead of being an external force on a part of the system.

For example:
$\Delta K + \Delta U = W_{NC}$
Where $W_{NC}$ is equal to all the work done by non conservative forces, including friction.

Work done by friction on a slope:
$f = \mu_{k} * N$ => $f = \mu_{k} * mgcos\Theta$
$W_{NC} = f * \Delta x$ => $(\mu_{k} * mgcos\Theta) * \Delta x$

## Conservation of energy in the presence of non-conservative forces
Friction increases the internal energy of the system. Its work goes into $E_{int}$, or energy associated with temperature

$$\Delta_{system} = \Delta K + \Delta U + \Delta E_{int} = W$$

In the absence of other transfers $\Delta E_{int} = -W_{f}$
