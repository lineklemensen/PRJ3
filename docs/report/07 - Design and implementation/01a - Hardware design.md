# Hardware design 
The project needed to be able to turn the LED's on and off, handle the power to our motors and regulate power to said LED's and our RPi5. To do this, we are using a voltage regulator, to get our input of 7.2V to 5.1V. Then we use three transistors to either open or close a ground connection to our LED's and motors, with the help of a signal from our RPi5. Using Ohm's law, $R = V/I$, we could find the pull down resistances needed for the two LED's, the first one being 160ohm and the other being 330ohm. Then for the resistances thats connected to our voltage regulator, we are using this formula, $V_out = 1.25V * (1 + R2/R1)$, which ends up resulting in 400ohm.

![Multisim diagram over the currently used veroboard](/docs/pictures/multisim.png)


Using the above diagram, we could then make a very compact veroboard design.   
![DIY layout over the current veroboard](/docs/pictures/veroboard.png)




\newpage