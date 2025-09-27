
# Nonfunctional requirements

1. Functionality

1.1 The car must be designed as a compact rectangular box with wheels, optimized for navigation and load carrying.

1.2 The server must be a standalone unit (box form) that can operate on a floor or table.

1.3 The system must include obstacle detection and safe path navigation to avoid collisions.


2. Usability

2.1  Operability

2.1.1 The system must allow loading by pressing a button, placing the material inside it and then close the compartment.

2.1.2 The system must allow unloading by entering a code, retrieving the said material and closing the compartment, then it will resume operation after the press on the start button again

2.2 Accessibility

2.2.2 The user interface must use text $\geq$ 14pt, high contrast colors and be readable in the daylight.

2.2.3 An alternative access method such as NFC card could be supported


2.3 Documentation

2.3.1  A short user guide ($\leq$ 2 pages, printed and digital) must be available near the charging station, explaining loading, unloading, and charging.

2.3.2 The user guide could include troubleshooting with the 5 most common scenarios. 

2.4  Metrics

2.4.1 A novice user should make no more than 2 errors when retrieving the material from the car and should not take more than 2 minutes to complete the retrieve task. Time to learn to use the retrieve function of the car should be learned within 10 minutes of showing.

2.4.2 A novice user should make no more than 2 errors when loading the material on the car and should not take more than 5 minutes to complete the loading task. Time to learn to use the load function of the car should be learned within 15 minutes of showing.

2.4.3 Time to learn retrieval from the car must be $\leq$ 10minutes, time to learn the loading must be $\leq$ 15minutes

3. Reliability

3.1 Availability

3.1.1 The car  must be operable for at least 1 hour of continuous driving without restart.

3.2 Maintainability

3.2.1 Simple maintenance tasks (restart, battery swap, reconnection) must take $\leq$ 15 minutes.

3.2.2 Software updates to the system must not take more than 30minutes of downtime


3.3 Fault tolerance

3.3.1 The car  must stop safely if it loses connection with the central processor or encounters a critical error.

3.3.2 The system must notify the server and display an error code when a fault occurs.


4.  Performance

4.1  User input (button press, code) must be acknowledged within 1 second.

4.2 The car must be ready for operation within 30 seconds of power-on.

4.3 The car must payload of up to x kg without performance degradation

4.4 The car must have a minium range of x km per charge.

5. Safety and security

5.1 The system must lock out for 1 minute after 3 failed code attempts.

5.2 An emergency stop must halt all movement within 1sec

5.3 The car must not exceed a speed limit of x km/h

6.  Supportability

6.1  The server software must be designed so new modules (e.g., path optimization, object detection) can be added without major rewrites.

6.2 The car  must log successful deliveries, failed attempts, and system errors for debugging and evaluation.

6.3 The logs could be stored for up to 30 days or manually deleted.

6.4 The system could support remote retrieval of logs.

7. Scalability

7.1 The server might support operations of more cars simultaneous

7.2 The might integrate with external IT systems.

8. Constraints

8.1 The car could operate on wet surfaces and dust

9. Compliance

9.1 The system must comply with data protection regulations like GDPR