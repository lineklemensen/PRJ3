# Nonfunctional requirements {-}

## Functionality {-}

1. The car must make a request to the server for route when then action button is pressed while idle and not out on route.
2. While idle at a destination(Waiting for pickup), the car must continue its route when the action button is pressed, after a given waiting period. 

## Usability {-}

1. Accessibility
    1. The car must be equipped with two LEDs of different colors(green and red), indicating whether it is ready for execution of route, among other things.
    2. The car could have a speaker, letting the car indicate that its ready for driving route, waiting for pickup, etc.  auditorily.
   
2. Documentation
    1. At least 5 routes could be stored in a JSON file on the server, while waiting for car to drive routes.
    2. A short user guide ($\leq$ 2 pages, printed and digital) could be available near the charging station, explaining loading, unloading, and charging.
    3. The user guide should include troubleshooting with the 5 most common error-scenarios. 
    
3. User Interface
    1. The car must be equipped with 2 buttons, labelled 'Action' and 'Power'.
    2. The server must be accessed using a terminal UI on a local PC.
    3. The User Interface must use text $\geq$ 14pt, high contrast colors and be readable in the daylight.

## Reliability {-}

1. Availability
    1. The car must be operable for at least 1 hour of continuous driving without restart or charging.
    2. The server should be able to run continously for at least 6 hours.

2. Maintainability
    1. Simple maintenance tasks (restart, battery swap, reconnection) must take $\leq$ 10 minutes.
    2. The battery powering the car should be replaced every ~6 years.

3. Fault tolerance
    1. The car should be able to execute 9 out of 10  routes.
    2. The system won't handle any unexpected shutdowns of the car during execution of routes.
   
## Performance {-}

1. Efficiency & Speed
   1. User input (button press, code) must be acknowledged within 1 second.
   2. The car must be ready for operation within 1 minute of power-on.
   3. The car must have a minium range of 500 meters per charge.
   4. The car must drive at an maximum speed of 5 km/h
2. Scalability
   1. The server could support operations of several cars simultaneously
   2. The car could integrate with external IT systems.

## Supportability {-}

1. Serviceability
   1. The car could log routes, failed attempts, and system errors for debugging and evaluation.
   2. These logs could be stored for up to 30 days or manually deleted.
   3. The system could support remote retrieval of logs.

## + {-}

1. Safety and security
   1. An emergency stop must halt all movement within 1 second.

2. Constraints
   1. The car must only be operable indoors on flat surfaces.
   2. The car shouldn't be able to operate on wet surfaces.
   3. The car won't have any obstacle detection and safe path navigation to avoid collisions.
