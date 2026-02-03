#motorsports 

# High Voltage
Any voltage greater than 60V DC or 25V AC RMS

# Dangers
- Accidental contact with any high voltage supplying sufficient energy may result in server injury or death. This can occur as a person's body provides a path for current flow, causing tissue and heart failure.
- Other affects
	- Nervous system damage
	- Numbness
	- Difficulty moving limbs

# PPE
Personal Protection Equipment
- HV Gloves
- HV Tools
- HV Blanket
- Face Shield

# Orange
Orange cabling and connectors are reserved for High Voltage components
- TSMP Connectors
- TSMP Wires
- HVD
- DC Mains
- Phase Connections

# HVD
High Voltage Disconnect
- Quickly disconnect one or both poles of the accumulators.
- Easily Operable
- The KS5E has two HVDs
	- On Accumulator
	- On discharge box

# HV Master Switch
EV.8.9.3
- Orange face
- Has HV Sticker next to it
- If LV master switch has been flipped (Red - seen in pic)
	- Will shut AIRs allowing for HV to leave Accumulator

# E-Stops
- There are 3 on the car:
	- One in the cokcpit
	- Two on the main roll hoop
- Will open shutdown circuit and stop HV leaving Acc.

# TSMPs 
Tractive System Measuring Points
EV.6.8
- Two Red Jacks labelled "HV+" & "HV-"
- Black jack "GND"
- Set on car switch panel next to the master switches
- Set on Charger box body

# TSAL
Tractive System Active Light
EV.6.9
- If the voltage outside of the Acc < 60vdc the light is 
	- Green
	- Solid
- If vdc > 60 the light is
	- Red
	- Flashing

# AVI
Accumulator Voltage Indicator
- When acc voltage < 60V a red solid light turns on
- This must also work when acc is not in the car, so when charging

# RTD Noise
Ready to Drive
EV.10.5 and EV.10.4.3
- Motors will not respong until Ready to Drive action (in our case button) i s pressed
- Driver must press brake, hold, then press button to engage motors
- Ready to drive sound will occur showing car is now active

# IMD
Insulation Monitoring Device
EV.8.6
- The IMD is a part of the shutdown circuit
- It measures for isolation failures between HV and LV GND
- IF detected it will open a non-reset able (except by reset button) latch in the shutdown circuit
- A red light will turn in the cockpit