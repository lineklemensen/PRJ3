

## The problem

In hospitals nurses often have to administer medicine to many different patients, which can be in rooms that are far apart from eachother on a floor. This leads to a lot of time being wasted entirely on walking back and forth between rooms and the dispensary.
Hospitals across denmark have for a while had a labor shortage of nurses, which is why we decided to choose that as our primary focus when designing the system.

## The solution

What we had in mind was a small autonomous car that would be able to hold a "package" of medicine which it would be able to deliver to the appropriate drop-off points.

The car will receive the "orders" from a central point which would be responsible for keeping track of all the orders needing to be executed. This allows having multiple cars run in parallel each being able to deliver to seperate locations.

The cars would each have a computer that lets them path-find to their designated drop-off points, in our prototype this is realised as a Raspberry Pi 5 (RPi). Upon arrival they await a nurse to pick up the package, allowing the car to return to the central pick-up point again to proceed to the next order.

One facet of the issue we want to excemplify is the need to keep proper security when delivering the orders, as they will be delivering various medicines, some of which fall under prescription drugs. Because of this the cars will wait for a nurse who'll have to authenticate before being able to access the medicine, this prevents unauthorized people from accessing or patients potentially self-medicating.

