# Software design

## Pc / Tui

### Empty class diagram

### Sequence diagram

![UC2 SD](docs/diagrams/out/apModel/SD UC2 - Create Delivery - PC.png){width=680px}

In order to aid developement we decided to go for a more general framework for making a TUI, this was done so we wouldn't need to hardcode the same button functionality repeatedly and instead could have a general button class that allows for a general "action" to be bound. 

On top of this several different UI elements can be made and easily added to the TUI, such as basic text elements and checkboxes.

### Full class diagram

## Server

### Empty class diagram

### Sequence diagram

The "server" is a very basic HTTP server. It supports handling incoming "orders" and should store them in a local log file as persistent storage. It has two routes "/new_route" and "/get_route" the first handles incoming orders from the pc, while the latter handles sending the order to the car when requested.

### Full class diagram


## Car

### Empty class diagram

### Sequence diagram

### Full class diagram

![alt text](docs/diagrams/out/apModel/car_classes/CarClasses.png){width=500px}

\newpage