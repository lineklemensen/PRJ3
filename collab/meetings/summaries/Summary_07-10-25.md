## Meeting leader: Nicolai  
## Summary: Kasper  

Meeting starts out by summarizing the project, going over what is needed and what isnt.  

# RPI1(Robot):  
Drives the route and deliveres  
battery: doesnt make sense to do 8 so either 12,18 or 24 hour battery. How long would a battery survive ? Its not super important.  

## LEDS: 
two LEDS would be chosen a green and a red.  

## Buttons: 
two buttons, one for on/off one for start.  

## Hbro: 
1 Hbro is needed  

# new suggestions:  
Car makes a request every 30 seconds or minute to the server for a order.  
Add a picture or screen grab of UI to show in system specs or to censor

# RPI2(Server):  
Server saves orders.  
## Power: 
it needs power.  
RPI2 is passive server, which means it can only respond to request but not send on its own, else websocket would be required.  
RPI2 has wireless communication with PC through HTTP.  
order gets saved from PC to RPI2 as a text file.  

# PC(HTML):  
## Has the UI.  
Recieves communication from RPI2  
User interacts with computer to create order  

# Teknisk analyse:  
maybe use JSON for handling of order.  

# Use case 2:  
Switch user with dispense nurse or some way point to specific user.   
"User opens UI on PC" be more specific in initialization.   
The order should be send to the server not the car.   
The car finished pathfinding calculations is not relevent for the use case.  
The use case should only save to server.  
## main senario 1 
"The dispensary nurse opens UI on pc" be more specific.  
## main senario 2 
"Appears on UI screen" be more specific.  
## main senario 3 
"Finish and cencel options appear" needs to be more specific as wording and extension/exception  
## main senario 4 
it will be a text based UI there for a way to seperate 1,2 and 3 would be since buttons would be feecable. command terinal (argv) inputs. be more specific in wording 
text line appears, "Is order finished press x else select more rooms y".  

# Jenny's Libary
https://gitlab.au.dk/knp-module2  
restinio-bundle, supports c++, clients and HTTP contains sample for main. This libary shows how to save order with JSON and create it in a struct. Have to grab and replace code.  
We run the code on the PC with RPI2 connected, then on RPI1 the same libary is connected and makes a request for the JSON from RPI2 to RPI1.

# For next
system arcitecture, usecases and accepttest.  

# Next leads
## Summaries: 
Line
## Meeting leader:
Daniel
