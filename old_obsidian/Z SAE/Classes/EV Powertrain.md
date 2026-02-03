#motorsports 
# Subgroup Scope:
- Accumulator
- Motor controllers
- Motors
- HV Path design

# What is in it
- Battery Pack:
	- Energy storage unit
- Motor controller
	- A few different types it takes DC and makes it into AC
- Motor
	- Turns AC into mechanical rotation. Types:
		- Brushed DC
		- Brush less DC
		- AC

# EV in FSAE
- Electric FSAE started 2013
	- 5 teams
- 2023- over 70 schools competing
- Kennesaw Motorsports placed 6th in June 2023

# Ohms law
$$V = IR$$
V = Voltage
I = Current
R = Resistance

# Power
P = VI
P = Watts

# Energy
$$E = P*t$$

# Batteries
- Batteries take chemical potential energy and turn it into electric energy
- There are three common types for lithium-ion cells
	- Prismatic (rigid cubes)
	- Pouch Cell (flimsy pads)
	- Cylindrical (Self explanatory)

## Battery configs
Series: + to -
$$2*12v=24v$$

Parallel: + to +
$$8*20a=160a$$

# Inverter
- Takes DC and makes AC

# Electric Motor
Basic Contruction:
- Stator:
	- Stationary component of the motor. Has coil windings used to create the magnetic feild (aka phase windings)
- Rotor:
	- Rotating component that contains the magnets which interact with the stator feilds to rotate

# Basic EV Rules
1. High voltage is anything above 60v
2. Max power output is 80kw
3. Accumulator segments must be under a max of 6MJ

# Shutdown Circuit
- EV.8
- Accumulator Management System (AMS) EV.8.3
- Insulation Monitoring Device (IMD) EV.8.6
- Brake System Plausibility Device (BSPD) EV.8.7
- Interlocks (as required) EV.8.8
- Master switches (GLVMS, TSMS) EV.8.9
- Shutdown Buttons EV.8.10
- Brake Over Travel Switch (BOTS) T.3.2


# Specs:
- Voltage: 302v
- Current: 160A nominal, 280A peak
- Power: 62kw or 85Hp

# Energus Li2x4pHE2
- LG HE2 18650 cells, 8 in parallel
- Voltage (v): 4.2 Peak or 3.6 Nominal
- Current (a): 280 Peak or 160 Nominal
- Capacity: 20 Ah

# Modules
- 12x energus cell groupds
- Weight: 16lbs (7.25kg)
- Configuration: 12s8p
- Voltage Peak: 50.4v
- Discharge: 200A peak, 160A continous

# Accumulator Specs
- Cell count: 576
- Cell configuration: 72s 8p
- Weight: 118lbs or 53.529kg

# Accumulator Lid
- ACU (Accumulator control unit)

# Inverter
- Cascadia Motion PM100DX
- Handles power requests and motor control
- Takes in DC, outputs AC
- Liquid Cooled

# Motor
- Emrax 228 Medium Voltage Combo Cooled
- AC motor
- Gliders, cars, FSAE, bikes, etc