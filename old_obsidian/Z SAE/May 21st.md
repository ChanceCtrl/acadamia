#motorsports 

This is going to be aids

# Overview
The meeting was just supposed to be about pack pouch development, not that cell selection was an open process nut we got them from the Tesla sponsorship. How we design the acc affects more or less everything for the e-car so its important that we all agree on the direction of the car for the next two years

The original cell selection was made around the idea we would be a 600v car, but now that we probably will not be going with 600v with the ks8e we need to decide what cope we go with

Bailey thinks that more or less any combo can get us a top 10 dynamic event finish


# Pack config options
## Cell testing notes
We need to make some IR table or something in order to actually understand and model our pack for thermal sims and what not. There is a promising company is "Energy assurance"

## 400v
So the first config is the 96s (400v) 1p config, it gives us less power (aprx 1.2 kW) but we have to drive slower and overall we don't worry about heat as much (the mystery python script is saying 50c by the end of endurance vs our current 72c)

## 300v
The next option is 72s 2p (300v), now we run back into thermal issues and now we also have to worry about fuses

## 600v
last guy is 144s 1p (600v), the problems being described below and would take a whole team effort.

# 600v vs <=400
We have to buy a lot of supporting equipment in order to make the change to 600v but the cells we picked were optimized for 600v, so any of the configs to keep are current hardware is just going to be a band-aid solution and never perfect.

However it would be around 10k in equipment like the inverter and BMS stuffs, not to mention redoing a lot of rules boards.

Bailey however, thinks 2p is stupid, and that the cells picked are not optimal for it nor is it better. As the fuses would degrade the cells and the added temp 


# 2 year vs 1 year 600v
So if we split the dev time into 2 years and make it something for the ks9e then we make it only a 1/10th our budget disappear 


# How does the switch to pouches affect the IC
MEs don't really get affected, but LV gets hammered with 600v. So really just the EEs get fucked lol.