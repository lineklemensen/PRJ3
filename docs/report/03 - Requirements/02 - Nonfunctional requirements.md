# Nonfunctional requirements

## Functionality

1. The server must be a standalone unit.
2. The car must make a request to the server for route every 30 seconds(?) (Hvor skal den her være)

## Usability

1. Accessibility
    1. The car must be equipped with two LEDs of different colors(green and red), indicating whether it is ready for delivery, among other things.
    2. The car could have a speaker, letting the car indicate that its ready for delivery, waiting for pickup, etc.  auditorily.
   
2. Documentation
    1. Routes must be stored in a JSON file on the server, up to a total of x(?).
    2. A short user guide ($\leq$ 2 pages, printed and digital) could be available near the charging station, explaining loading, unloading, and charging.
    3. The user guide should include troubleshooting with the 5 most common error-scenarios. 

3. User Interface
    1. The car must be equipped with 2 buttons, labelled 'Action' and 'Power'.
    2. The server must be accessed using a terminal UI on a local PC.
    3. The User Interface must use text $\geq$ 14pt, high contrast colors and be readable in the daylight.

## Reliability

1. Availability
    1. The car must be operable for at least 1(?) hour of continuous driving without restart.
    2. The car must be available for service 18 hours(?) a day.
    3. The server must be available 24(?) hours a day. (You should be able to make routes while car is charging)

2. Maintainability
    1. Simple maintenance tasks (restart, battery swap, reconnection) must take $\leq$ 15 minutes(?).
    2. Software updates to the system must not take more than 30 minutes of downtime(?).
    3. The battery powering the car should be replaced every ~6 years(?).

3. Fault tolerance
    1. If the car takes more than 30 minutes(?) to complete a delivery, it must send a message to the server, and return to home base if possible, otherwise go idle.
    2. The car should be able to complete 9 out of 10 deliveries.
    3. The car won't handle any unexpected shutdowns during deliveries.
    4. The car won't be able to operate on wet surfaces.
   
## Performance

1. Efficiency & Speed
   1. User input (button press, code) must be acknowledged within 1 second.(?)
   2. The car must be ready for operation within 30 seconds of power-on.
   3. The car must have a minium range of x(?) km per charge.
   4. While idle at a destination(Waiting for pickup), the car must continue its route when the action button is pressed.
   5. The car must drive at a speed of ~2 km/h
2. Scalability
   1. The system could support additional cars.
   2. The system could integrate into external software systems. 

## Supportability

1. The car could log deliveries, failed attempts, and system errors for debugging and evaluation.
2. These logs could be stored for up to 30 days or manually deleted.
3. The system could support remote retrieval of logs.

## +

1. Safety and security
   1. An emergency stop must halt all movement within 1 second.
   2. The car must not exceed a speed limit of 5 km/h

2. Scalability
   1. The server might support operations of several cars simultaneously
   2. The car might integrate with external IT systems.

3. Constraints
   1. The car will only be operable indoors.
   2. The car won't have obstacle detection and safe path navigation to avoid collisions.

