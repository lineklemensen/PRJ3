
# Nonfunctional requirements

## Functionality
1. The car must be designed as a compact rectangular box with wheels, optimized for navigation and load carrying.
2. The server must be a standalone unit (box form) that can operate on a floor or table.
3. The system must include obstacle detection and safe path navigation to avoid collisions.


## Usability

1. Operability
    1. The system must allow loading by pressing a button, placing the material inside it and then close the compartment.
    2. The system must allow unloading by entering a code, retrieving the said material and closing the compartment, then it will resume operation after the press on the start button again

1. Accessibility
   1. The user interface must use text $\geq$ 14pt, high contrast colors and be readable in the daylight.
   2. An alternative access method such as NFC card could be supported

1. Documentation
   1. A short user guide ($\leq$ 2 pages, printed and digital) must be available near the charging station, explaining loading, unloading, and charging.
   2. The user guide could include troubleshooting with the 5 most common scenarios. 

2.  Metrics
    1. A novice user should make no more than 2 errors when retrieving the material from the car and should not take more than 2 minutes to complete the retrieve task. Time to learn to use the retrieve function of the car should be learned within 10 minutes of showing.
    2. A novice user should make no more than 2 errors when loading the material on the car and should not take more than 5 minutes to complete the loading task. Time to learn to use the load function of the car should be learned within 15 minutes of showing.
    3. Time to learn retrieval from the car must be $\leq$ 10 minutes, time to learn the loading must be $\leq$ 15 minutes

## Reliability

1. Availability
   1. The car must be operable for at least 1 hour of continuous driving without restart.

2. Maintainability
   1. Simple maintenance tasks (restart, battery swap, reconnection) must take $\leq$ 15 minutes.
   2. Software updates to the system must not take more than 30minutes of downtime

3. Fault tolerance
   1. The car must stop safely if it loses connection with the central processor or encounters a critical error.
   2. The system must notify the server and display an error code when a fault occurs.


## Performance
 1. User input (button press, code) must be acknowledged within 1 second.
 2. The car must be ready for operation within 30 seconds of power-on.
 3. The car must payload of up to x kg without performance degradation
 4. The car must have a minium range of x km per charge.

## Safety and security
 1. The system must lock out for 1 minute after 3 failed code attempts.
 2. An emergency stop must halt all movement within 1sec
 3. The car must not exceed a speed limit of x km/h

## Supportability
 1. The server software must be designed so new modules (e.g., path optimization, object detection) can be added without major rewrites.
 2. The car must log successful deliveries, failed attempts, and system errors for debugging and evaluation.
 3. The logs could be stored for up to 30 days or manually deleted.
 4. The system could support remote retrieval of logs.

## Scalability
 1. The server might support operations of more cars simultaneous
 2. The might integrate with external IT systems.

## Constraints
1. The car could operate on wet surfaces and dust

## Compliance
1. The system must comply with data protection regulations like GDPR