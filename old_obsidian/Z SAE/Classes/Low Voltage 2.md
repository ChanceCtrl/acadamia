#motorsports 

# What is CAN?
- Controlled Area Network (communication protocol)
- Protocol to send data digitally
- Only 2 wires for 1-50+ devices
- Used mainly in automotive, farming & heave equipment
- Similar to a "nervous system", enables communication between components

# Why is CAN?
- Need to send info
- Multiple forms
- Important factors
	- Speed
	- Bandwidth

# How is CAN?
- CAN needs terminating resistors at the beginning and end of the buss
- The resistance on each end needs to be 120 Ohms in total. One method is two 60.4 ohm resistors
- Yellow = CAN High
- Green  = CAN Low
- The 2 wires are twisted to reduce noise.

## The process
1. Micro controller sends data out
2. CAN Controller takes data and turns it into CAN packet
3. CAN Transceiver sends actual message (& receives them)

# Micro controllers
- small computers used to control integrated systems
- the main brain of boards
- simple IO
- we use teensy micro controllers

# Analog Data
- Typical 0-5v "infinite" resolution
- Sin Waveform
- Must be translated to Digital when used by micro controller

# Digital Data
- Digital signal (1 or 0)
	- Square waveform
	- Peaks are 1
	- Valleys are 0

# State Machine
- A list of states and their respective commands/behaviors non-linear

# What is Github
- Version Control
	- System that allows tracking changes in code, enabling reverts to previous versions if needed
- Git
	- Its the most popular version control system. imagine it as a magical undo button for code
- GitHub
	- An online service for hosting git shit
- Repository
	- Is a project folder

# Why is Github
- Backup and versioning: You can save different versions of your Arduino code and revert to any version at a given time
- Collaboration
- Ease of access

# How is Github
- Main
	- Tested and is known to work, must submit a pull request and have it approved
- Testing
	- Code about to go onto the car
- Legacy
	- Code that used to run on the car

