#motorsports 

LoRa is half duplex vs XBee is full duplex
XBee makes a mesh network while LoRa makes a star network
Mesh means every device is connected to every device
Star means every device is connected to a hub device
Possibly use [[MCAP & Foxglove]]? (probably not)

List of data logging points **bold** means live
- VD
	- Shock
	- Gyro
	- Accelerometer (front and rear?)
	- Driver control
		- Brake position
		- **Accelerator position**
		- Steering angle
		- **Break pressure**
	- Wheel speed
	- GPS
- IC
	- **ECU**
		- RPM
		- MAP
		- AFR
		- AFR Target
		- Oil pressure
		- Oil temp
		- Coolant temp
- EV
	- **Pack temp**
	- **Motor temp**
	- **Inverter temp**
	- **Pack V**
	- **Pack A**
	- Motor RPM
	- Power W
	- Cell delta
		- Highest & Lowest
	- **Inverter state**
	- **VCU state**
	- **Fault Status**
		- AMS
		- IMD
		- BSPD
		- APPS
		- Inverter

Flow chart of data

# Why log data?
- Because while driver feedback is important, they can be wrong.
- It helps to debug other parts of the car.
- Speeds up development by learning as much as possible from what you do
- To keep track of wear of parts
- To give people like sponsors hard data on how you are getting better and why you deserve/need more money

# Why have live telemetry?
- The driver (or at least ours) will not be looking at the wheel trying to go fast. That means putting a bunch of lights on the dash wont do shit until the car stops go fasting.
- Thus having live telemetry to people who can focus on the data and what it means and effectively convey what the driver needs to do over radio would be more ideal. Some examples being
	- X temps too hot; Slow down on the straights.
	- Front acclerometer not reaching normal peaks; Take corners with under steer in mind.
	- APPS/BSPD buggin; Be more careful with trail breaking.
	- Pedal position buggin; Use more pedal.
	- Brake pressure falling; Slow down and use more pedal, be careful of BOTS.
- Even if you can't instruct the driver on how to drive different to not break the car further, knowing why the car is dying before something explodes allows you to pit and fix the problem quicker than running it till it does break and then having to hunt down what broke, and seeing if you even can fix it.

# Why corner nodes?
- More robust by removing the need to run cables across the entire car and having a CAN for just data aqq.
- You can make failures more isolated.
- Each corner node will have an optional micro SD card so if the CAN starts to die you can still pull data from each wheel and try to diagnose the CAN problem.
- Having the corner nodes feeding a main node would allow easier pulling of logs to put into a proper database

# What will you do with the data?
The live telemetry can be recorded separately for debugging it, but the main node will save to a micro SD and so will all the corner nodes for extra redundancy. After pulling what data you want you put it in a folder and push it to a MySQL database for storage and later processing. Once someone wants to read it they go and grab the data they want and run it thru a MATLAB script to visualize it.

- [ ] wosdasd

Circuit Diagram
![[eveLogger_Circuit_Diagram.excalidraw]]
Code Diagram
![[eveLogger_Code_Diagram.excalidraw]]
