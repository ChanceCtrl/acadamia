#motorsports 

Its important to make sure the frame is rigid, and also light, and also cheap, and also designed in a way to work as naturally as possible with things like the suspension and aero.  

# Considerations
- Rules
- Weight
	- Front/Rear balance
	- Balance with stiffness
- Stiffness
	- Torsion (chassis twist in turns)
	- Suspension loads 
	- Aero Loads
- Driver Cockpit
	- Need space for driver and controls
- Space
	- Still need space for fuel, electronics

## Monocoque
Good for the way it disperses stress
- Carbon fiber
- Potentially lighter for similar space-frame stiffness
- Combination of carbon weave layers and honeycomb for stiffness
- Requires autoclave
	- Mold required

## Tube Space Frame
Cheap and easy
- Our car uses Welded 4130 Chromoly Tube
- Varying tube thickness where needed
	- Rules
	- Stiffness
- Welder required
	- Need jogs
	- Can have multiple welders at once

# Triangulation
"An engineer's best friend"
- Turns loads into tension and compressive forces rather than bending
- Use triangulated structure (space frame) for stiffness

# Rules
28 pages dedicated to chassis alone, thankfully SAE gives us a handy document called the SES (Structural Equivalency Sheet)

Required Minimum tube thickness:
- Role hoops - .095
- Seat belt Bar - .095
- SIS - .064
- Front Bulkhead - .065
- Front Hoop Brace - .065
- Other Structural Tubing - .049

## The three templates
- Cockpit Opening
- Internal Cross Section (Foot Template)
- Driver Template (PERCY)

# The SES
Lots of values that get sent off to someone to make sure yo car dont crumple wrong
- Used to organize chassis design and confirm it with rules

# Design Basics
- Kinematic Skeleton
	- Every suspension point
- Placement of weight
	- Center of Gravity

# Stiffness
- Chassis that are not sufficiently stuff result in unpredictable handling
	- Due to expected movement of suspension geometry
	- "It is important to recognize that all simple calculations are based on the assumption that the chassis of the car is rigid, that is, it does not bend or twist under any driving condition"
- Torsional stiffness sims and physical testing
	- Apply load to chassis
	- Measure deflection of nodes
		- Calculated degrees of rotation
	- Calculate stiffness
t = torque applied
theta = resulting degrees of twist
$$K = \frac{t}{\theta}$$

# Suspension Loads
- Suspension will apply tension and compressive loads on the chassis
	- Move as suspension moves
- Chassis must not comply under loads
	- Impossible for there to be 0 compliance
		- Chassis must not comply enough to affect suspension geometry

# Jigging
Critical components jigged
- All suspension nodes
- Motor placement
- Angled/Hard to hold tubes jugged with 3D prints