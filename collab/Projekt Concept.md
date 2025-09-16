# Project Concept

Danish hospitals has for the past many years been defined by strikes and many loud and public discussions between employers and the nursing staffs trade union. Through these, the public has become increasingly aware of the often lacking, and sometimes appaling, work-environments, with poor pay, large amounts of overtime and understaffing. 

One part of the day-to-day tasks that nurses engage in, is transportation of medicine. If a patient is in need of a specific medication, but the given ward has run out of said medication, a nurse will typically be forced to walk a rather large distance to a depot and back. This causes a period of downtime, in which that staff will not be able to perform their regular, life-saving duties. 

With this project, we aim to drastically reduce this downtime, by constructing a small vehicle to conduct this transport, instead of staff. The vehicle will be able to semi-autonomously drive from the medicine depot, to the designated destination, only requiring staff to load and unload the vehicle, increasing time spent doing actual nursing work, to ease the problem, caused by understaffing.

The vehicle will be controlled by a Raspberry Pi microcontroller, which, through communication with a dedicated Linux server, will receive driving instructions. These instructions will be used as parameters in a specially designed algortithm, that the car uses to determine its path. This also allows for expansion, as multiple vehicles can connect to the same server, making deliveries to multiple different wards at the same time possible.

The vehicle will contain a User Interface, where nurses, with a passcode, keycard, etc., can unlock a storage unit on the vehicle, load it with medicine requested by other nursing staff, and define a destination for the vehicle. Upon arrival, the staff who requested said medicine, can unlock the storage unit and receive the medicine, after which the vehicle will return to its route, or its designated home.

As the vehicle will be transporting rather sensitive cargo, such as prescribtion drugs, security is one of the largest concerns. Because of this, the storage unit on the vehicle will be secure, to not allow patients forcing it open, and/or requiring a certain level of access from staff. 

Throughtout the project, we plan to communicate with actual hospitals and nursing staff, to gather a more detailed picture of the different needs and requirements, such a vehicle would need to accomodate in the real world, especially Sygehus Lillebælt and Kolding Sygehus, that earlier this year, have been part of tests using similar vehicles. 
Nurses having to keep track who, where and what medicine to administer only adds to the amount of stress nurses experience and deal with, on top of their already hectic worklife. Relieving them of this will hopefully lead to less mistakes in treatment from distributing medicine, and thereby also a better all around experience for the patients.
Throughtout the project, we plan to communicate with actual hospitals and nursing staff, to gather a more detailed picture of the different needs and requirements, such a vehicle would need to accomodate in the real world, especially Sygehus Lillebælt and Kolding Sygehus, that earlier this year, have been part of tests using similar vehicles. 

![Project sketch](<../docs/diagrams/out/Project Concept/Project concept.svg>)
