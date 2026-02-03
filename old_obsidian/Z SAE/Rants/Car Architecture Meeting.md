#motorsports 
(Anything in parenthesis is my thoughts, *these are thoughts from peeps*, everything else is lightly abridged teams notes)


## Look at design goals
Avoid blanket statements
Get more points in design

## Design earlier 
The design process was fine, just late, and we need more sims to justify

# THE GOAL OF THIS MEETING IS TO DEFINE GOALS
and layout the plans for each subgroup in a collaborative manner in how each subgroup affects one-another

(Structured like a list of problems with some bucket list type items in the middle?)
## VD
- Rear diff ecar
	- Spool contributes to understeer gradient and increased yaw inertia
	- Tire jacking
	- Drive train packaging
- Tire modeling and reevaluation
	- cost (will it last us? is it effective for its price?)
- Regenerative braking
	- More efficiency points
- Anti roll bar
- Anti dive/pitch geometry
- Motion ratio evaluation for platforming and normal load
- Verify track width offset for aero efficiency
	- Track width v. frontal area trade off
	- To reach desired steering ratio and ackerman(?) percentage
- Figure out the abnormally high steering effort
- Moving wheel base to minimum for ecar
	- Yaw inertia of ecar
- Driver ergonomics investigation
	- Seating angle
	- Seating angle
		- Front leg spacing
		- contribution to yaw inertia
		- Fire wall seating?
		- CG affect
- Compliance Analysis
	- Integrate lap sim?
	- Displacement per G
	- Go into assemblies of how they could be more or less compliant, bearing packages, bushing v bearings, etc. 
- Direct actiation/direct mount shocks 
	- Remove bell crank to lighten unsprung mass
- Pull rod vs push rod
	- differs from ev to ic

(List of things that still need to happen, with DRS and DAQ being bucket list-ish?)
## LV
DAQ: investing in daq can verify designs and overall build a better car, the info can help in our design season and in the design event for validation.
- Currently have shockpot, stearing, accel/gyro, tho no one looks at the data
- We want to have (not in any order (not my parenthesis, val's))
	- Wheel speed
	- Shock pots
	- Tire temps (mounting on aero and no stupid brackets (not my parenthesis, val's))
	- Steering angle
	- Throttle Pos
	- Brake Pos
	- GPS
	- Accel
	- Gyro
	- Telem
	- Pedo tube
- Getting all this data means nothing if no-one uses the data

DRS: able to control when down-force is applied such as in corners and straits for max performance.

### EV
- 600v TSAL
- AVI needs to be redesigned for +350v
- ACU needs component check for +350v
- Precharge relay is +500v but not rest of components
- Need new VCU
	- Traction Control (for 2 or 4 motor car)
	- Launch Control
- Mother Board for lid boards
	- Huge risk, all boards need to work or be isolated enough where 1 dying doesn't kill them all
	- Eliminates loose wires and shrinks lid packaging
- Custom BMS
	- currently capped with configs and modules
- Regen
	- More points
	- Drive harder
	- Heats up pack
- Everything 600v (don't agree with this (not my parenthesis, val's)), it will not be efficient for a sub 600v system, it will cost more, weigh more, and take more space

### IC
- Launch control

(Formatted like a shopping list)
## EV Power-train
- Pouch Pack
	- Configs
		- 400v
		- 600v
- Custom BMS
	- Centralized or custom
- Pack format
	- Change seat
	- Mounting
		- be under driver seat area
	- Lid formats
- Power electronics
	- Motors
		- HV 208
		- MV 208
		- HV 228
		- MV 228
		- H3X 30
		- Hubs?
	- Inverters
		- CM200
		- DTI 550
		- Custom (I mean I would be down lol)
- Launch control
- Traction control
- Regen
	- Dynamic
	- Steady
- Water cooling
	- Rad placement *Should add radiator shroud for better cooling* - Nathan
		- Rad fan
	- Smaller pump
- TS Modeling
	- Energy
	- Torque/Power
- Rear diff
- Switch panel
- Fan ducting

(50% DRS, 50% Cope)
## Aero - EV
RW active Aero
	Aerobrake, AOA matched to speed
FW active Aero
	DRS, aerobrake, AOA matched to speed
	Left/Right active
Rake
	1-3 degrees?
	Raising rear to allow diffuser expansion
Purpose designed side wings
	Longer chord
	Designed to the application
Radiator placement 
	Exploring different pos
	Shroud?

(??? (I need to understand this better))
## Composites
Wing structure
		Move bonding seam off leading edge
	Leading edge is separate that fits onto the offset added to the top and bottom skin
	Increase bonding area and helps reduce air flow disruption
		Looking into different ways of bonding to eliminate seams
			Vulcanization
	Inset insertions 
	Spar location and effect
		Do better about identifying optimal position
		Look at incorporating wing spar into mold
			Reverse bagging technique
Grounding
	Looking into a carbon better and conducting
	Electrostatic flocking 
	Nickle coating
Monocoque Research
	Understand what we have better and figure out what is needed where for structural architecture
		Make a mock-up with the fiber glass we have, see how viable it is, and then see how much better carbon would be
	Multi-piece 
		Change out parts every year
		Would start with half space frame half coque

## Thoughts from peeps that I tried to remember (take this with a few kilos of salt)

*Why are we listing out what we want and not moving anywhere?* - Val

*People have made full ecar sims that account for thermals* - Joey
	*What does that mean for us?* - Bailey 

*Are we going to have 2 aero packages next year?* - Sammy
	*I think thats a different discussion* - Nathan
		*I don't think we should have such high scope projects for both cars* -  Nathan
		*We won't be making two wings* - Nathan

*We most likely will go with the safe option of 400v* - Johnathan
*A diff would be a better improvement that 200v* - Johnathan
*BMS, Motor, and inverter have to change for 600v* - Johnathan

*Hub motors are on there, No.* - Bailey
	*Not for the KS8* - Jonathan
		*Five year plan lol* - Bailey

*If you make a good launch control system, you can make a good traction control system* - Bailey

*DRS is a proof on concept for the KS7* - Val

*I don't think a monocoque is in our team's interest* - Val
	*We don't have the money for the molds* - Nathan
		*We also don't have the man power* - Val
			*You should still do the testing* - Johnathan
				*The data isn't worth having if you aren't doing it* - Nathan

*This meeting is about should this be designed and if it should be designed with someone else* - Nathan



## Other things(?)
Side wings are a cope for lost down force from less expansion on the rear of diffuser and we should give aero more room on the next Ecar frame.

ETS hub motor table(?)




# FINAL SNIP (unformated)
Problems: 

there wasn't a very strong plan for how design was going to start for the car 

Made it hard to find a starting point in the summer 

Sub group goals were broad, limited by simulation at the top level 

The goals for our subgroups need to take the next step further if we want to place well in design 

Some issues with sub group integration on some projects 

CAD, assemblies, etc.  

 

Sam notes: 

I say "design early" but I think this can be broken down a little further 

To solve the first point, I think the design process wasn't bad (ie. Top down goals, ranked priority list, project proposals), but the two other problems on the list depend a lot on how quickly we can start 

 

Meeting goal: 

Start with ranked priority list for subgroup and go down 

 

 

 

 

 

Take aways from the metting: ( 2-3 tings we want to start looking in to now)  

 

VD 

 

 

Rear differential ecar 

Spool contributes to understeer gradient and increased yaw inertia 

Tire jacking 

Drive train - power train rear packging 

Sizing of components and efficiency with power transmission 

Compliance Analysis 

Integrate to lap sim? 

Displacement per G 

Go into assemblies of how they could be more or less compliant, bearing packages, bushing v bearings, etc. 

Tire modeling and reevaluation 

Cost 

Good for design and integrate to lap sim 

Changes the entire basis of the car architecture 

Driver ergonomics investigation 

Seating angle, Positioning of steering hoop and seating angle, Main roll hoop positioning and height, fire wall seating? CG effect 

Front leg spacing, contribution to yaw inertia 

 

Aero 

 

Active aero 

RW and FW active 

FW left vs right 

LV controlled (scope) 

Side wing design 

Radiator location (scope) 

Optimizing the use of space in the aero box 

Rake 

Undertray optimization 

Rear Chassis bottom profile (scope)  

ACCU (scope) 

 

 

EV powertrain  

Pack configurations/format  

Chassis- driver positioning, moving pack forwards, rear packaging, SIS, Main Roll hoop. Overall goal of minimizing the wasted space behind the driver 

EV- will look into the various forms and configs and provide various volumes to test out in CAD to determine the movement of the tubes for chassis 

Composites - Firewall and seat interactions to pack, grounding for TS spacing rules and if it will be possible to count on that 

EV- will give placement and potential distances for with grounding and without 

Aero-  Change in aero boxes due to shorter wheel base potentially, optimizing acc placement for flat bottom/better undertray design  

LV- BMS and board voltage tolerances 

VD-  CG, CM, placement of driver & pack and trade off of moving one vs the other and how they interact, control arm pickup points 

EV- give potential placements to work with and investigate what would be best for VD 

Water cooling loop 

Chassis- Rear packaging and placement 

EV- look into different size rads from testing we may be able to carry out and use this to figure out optimal placements 

Aero- Component interactions, flow sims, taking advantage of having a powered fan on the rear 

VD- moving weight up or down and tradeoffs for that 

Regen 

LV- Programming in VCU for having the needed inputs and outputs  

VD- Need control scheme to determine when the optimal points are to engage, Dynamic vs Static values 

EV- investigate the TS modeling, points, thermal load, etc using data from endurance  

TS modeling  

VD- Lap simmmmm and using the data from that to make the thermal model and such 

 

LV 

VCU 

Look into a VCU redesign, current design is unreliable and a current major risk item  

Need to simplfly the boards overall design  

Need to investagate the Power stage , since it failed and things sotped workin  

Daq 

A Complete flushed out Daq system , 

 included but not limited to Nodes, CAN comunication , Telemety, and a parcing system that’s easy for people to pull the data    

Lunch/traction control 

Will inprove the cars potential overall performance on launches and cornoring  

This is heavily reliant on Daq sensors and heavy code implementation 

This needs a reliable /working VCU 