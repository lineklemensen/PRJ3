# Functional requirements

Use Case 1 Create order (must)
A nurse makes a order by selecting the rooms that need more medicine. The system sends a confirmation of success or failure.

Use Case 2 Prepare and send orders (must)
The server processes the order and sends the necessary information to the car. The car indicates it has received a order and found a path. The nurse loads the medicine in the car and presses the start button.

Use Case 3 Deliver order and return (must)
The car drives to the first patients room, here it stop and notifies that its ready to be unloaded. A nurse takes the medicine and presses the start button. If there are more room left in the path the car goes there and the cycle repeats until it has finished its path. Then it returns to the start location.

Use Case 4 Low battery warning (should)
If the car has less than 25% battery left it finishes its path and returns. When it has returned it sends a message to the server that its running out of battery. It then indicates this to the nurse and the nurse put it to charge.