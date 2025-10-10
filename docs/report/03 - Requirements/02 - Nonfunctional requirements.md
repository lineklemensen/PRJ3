
# Nonfunctional requirements

## Functionality
1. The car must be designed as a compact rectangular box with wheels, optimized for navigation and load carrying.
2. The server must be a standalone unit (box form) that can operate on a floor or table.
3. The system must include obstacle detection and safe path navigation to avoid collisions.
4. The car must make a request for orders every 30 seconds(?)


## Usability

1. Operability
    1. The car must stay idle for up to x(?) minutes upon reaching destination, while waiting for the 'continue' button to be pressed.
    2. While idle at a destination(Waiting for pickup), the car must continue its route when the 'continue' button is pressed.

2. Accessibility
    1. The user interface must use text $\geq$ 14pt, high contrast colors and be readable in the daylight.
    2. The car must be equipped with two LEDs of different colors(green and red), indicating whether it is ready for delivery, among other things(?).
    3. The car could have a speaker, letting the car indicate that its ready for delivery, waiting for pickup, etc.  auditorily.
    4. An alternative access method such as NFC card could be supported.
   

3. Documentation
    1. A short user guide ($\leq$ 2 pages, printed and digital) must be available near the charging station, explaining loading, unloading, and charging.
    2. Orders must be stored in a JSON file on the server, up to a total of x(?).
    3. Orders should also be logged in a text file(JSON as well?) on the car.
    4. The user guide could include troubleshooting with the 5 most common scenarios. 
   

4. Metrics
    1. A novice user should make no more than 2 errors when retrieving the material from the car and should not take more than 2 minutes to complete the retrieve task. Time to learn to use the retrieve function of the car should be learned within 10 minutes of showing.
    2. A novice user should make no more than 2 errors when loading the material on the car and should not take more than 5 minutes to complete the loading task. Time to learn to use the load function of the car should be learned within 15 minutes of showing.

## Reliability

1. Availability
    1. The car must be operable for at least 1(?) hour of continuous driving without restart.
    2. The car must be available for service 18 hours(?) a day.
    3. The server must be available 24(?) hours a day. (You should be able to make orders while car is charging)

2. Maintainability
    1. Simple maintenance tasks (restart, battery swap, reconnection) must take $\leq$ 15 minutes.
    2. Software updates to the system must not take more than 30minutes of downtime.
    3. The battery powering the car should be replaced every ~6 years.

3. Fault tolerance
    1. The car must stop safely if it loses connection with the central processor or encounters a critical error.
    2. The system must notify the server and display an error code when a fault occurs.
    3. The car must go idle if it takes more than 30 minutes(?) to complete a delivery.
    4. If the car cannot complete its delivery, the car must send a message to the server, stating this.
    5. The car should be able to complete 9 out of 10 deliveries.


## Performance

1. User input (button press, code) must be acknowledged within 1 second.
2. The car must be ready for operation within 30 seconds of power-on.
3. The car must payload of up to x(?) kg without performance degradation
4. The car must have a minium range of x(?) km per charge.

## Safety and security

1. An emergency stop must halt all movement within 1 second.
2. The car must not exceed a speed limit of x(?) km/h

## Supportability

1. The car must log successful deliveries, failed attempts, and system errors for debugging and evaluation.
2. The logs could be stored for up to 30 days or manually deleted.
3. The system could support remote retrieval of logs.

## Scalability

1. The server might support operations of more cars simultaneous
2. The might integrate with external IT systems.

## Constraints

1. The car should not be able to operate on wet surfaces and dust

## Compliance

1. The system must comply with data protection regulations like GDPR