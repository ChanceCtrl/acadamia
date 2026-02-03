#motorsports 
- Comes from "grounded low voltage" in FSAE EV rules

# What are LV responsible for
## PCB Design
- High level electrical system design
- Various circuits on both cars

## Firmware
- Coding vehicle controls data aqq tool
- integrating peripherals
- testing and debugging

# Boards
- Module Distribution board (MDB)
	- On top of each module (6 in total)
	- Reads and interpolates the thermistor value from the cells
	- Temp data is read  and calculated on board and sent to ACU over CAN
	- Voltage sent through fuses before going to BMS
	- 2 types of BMS Distributed and centralized
- Accumulator Voltage indicator (AVI)
	- When ACC voltage >= to 60v a red light comes on
	- This must also work when Acc is not in the car, so when charging
- Tractive system Active light (TSAL)
	- The light is located on the main hoop
	- the controller is located inside the Acc
	- when under 60v light is solid green
	- When above 60 v it must change red and blink at a frequency of 2 to 5 hz
- Vehicle control unit (VCU)
	- Primarily responsible for controlling inverter with torque requests over CAN
	- Controls "Read to Drive" state transition after TS enable
	- Executes brake/accelerator pedal plausibility checks in software
	- Contains BSPD curcuity and latching SDC stage
	- 3x CAN bus
		- Dedicated buses for drive control, accumulator (ACU, BMS) and data logging
	- Future-proofing:
		- Spare MCU GPIOs broken out to thru-holes
		- extra board space turned into "protoboard"
- Accumulator control unit (ACU)
	- Monitors the accumulators voltage and temp
	- receives temperature data from the MDB's setting on each module
	- Receives voltage from the BMS
	- Contains IMD, AMS, ACU shutdown circuit stages
	- Interfaces with shit over CAN
- HV TAP
	- HV tap board distributes TS+ and TS- as well Acc+
	- TSAL and AVI on top
		- They both get TS+ and TS- distributed through the board
- Pre-charge Discharge
	- Well it pre-charges the system, So we dont instantly send 300v to the system pre-charge is the most dangerous stage of the car
	- Discharge dissipates the remaining voltage in the system after shutting off
- Power Distribution Unit (PDU)
	- Takes in LV battery voltage and distributes the power to each system
	- PDU houses the fuses for each system
	- Newest version
		- Measures and logs current draw for each system
		- ???
- Isolation Measuring Device (IMD)
	- The IMD is something we buy
	- Detects a isolation failure and closes the Airs
	- There must be a indicator light on the dash that is red when triggered


# Defs
- Wire: A strand of material that conducts electricity such as aluminium or copper
- Cable: Multiple wires, usual braided 

# Common connectors
- DT/DTM
- AMPSEAL
- ANDERSON
- MOLEX

# Sizing wires
Depending on the power or signal we send over a wire well pick an appropriate size or gauge a larger corss section wire will be able to carry more current for our 12v battery cables, we use 8 awg wire



