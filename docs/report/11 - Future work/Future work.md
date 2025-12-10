# Future work

## Improvements
The project finalized into being a prototype to be looked into a given a proof of concept before making it into actual hospitals, hence a lot of improvements can be made to it.

## Hardware

For the hardware we ran into a few problems, mainly the we had trouble getting it to a size we could use, since it needed to be supported by our selection of motors and the wheels we had to find on our own as well hence why the financial usage also became a topic. This ended with our car not being supported to the capabilities we would have preferred. Since it would have been better with a larger battery and more place on the car itself to storage the medicine/product on.

## Software

An area of significant improvement for the system as a whole, would be how we handle the rooms, since as seen in the source code the rooms are hard-coded directly into the system at the moment, and can only be added this way at the moment. This limits the flexibility and makes the software more difficult to scale, maintain and reuse for other places. A way to fix this would be to make it a dynamic room-configuration, which would allow the user, preferably an admin to add and define rooms through input rather than modifying the source code. By allowing external inputs, it would be easier to create new environments, adjust boundaries and modify room layouts without altering the program directly, making scalability, reusability, maintainability and user accessibility so much better

# Project in the future

## Advanced Navigation and autonomy

In the future we would like to make a dynamic obstacle detection using sensors with real-time environmental mapping, so it would allow the car to adapt to changing conditions such as people moving around in the hallways

## Hospital integration

To function optimal in a clinical environment where privacy is valued and rules must be obeyed, so we would need to implement an authentication and user permissions, which ensures only authorized staff can dispatch and confirm deliveries. This is tandem with making the medicine storage component on the car itself be locked and using the same form of authentication should ensure a safe medicine delivery and limit medicine theft and exploits. Preferably there should also be implemented a tracker on the car so it could be tracked in real time.

## Safety, compliance and reliability

The prototype doesn't address clinical safety requirements at the moment. which is critical before real world usage. This includes regulatory compliance, to ensure the robots meets the healthcare standards for hygiene, electrical safety and operational reliability. Redundancy and fail-safe mechanisms to prevent the system from failures during navigation or medicine delivery

## Multi-robot coordination

To make the system make a considerable difference to real hospitals it would require multiple robots working simultaneously. this would mean to make task scheduling and load balancing between multiple units, and collision avoidance and communication between the cars to coordinate movement in the shared corridors. 



\newpage