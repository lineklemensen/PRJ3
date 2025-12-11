# Project formulation

## Introduction

The administration of medication in hospitals is a very critical process where can have severe consequences for a patient safety. Even the tiniest lapses, like a nurse being uncertain whether a patient has received prescribed medication, could lead to serious health risks.
For instance, a nurse said she was afraid of killing one of her eight post-surgery patients, because she was unsure which of her patients she had already given medicine, which highlights how human error can occur in high-pressure conditions, which are common in hospitals, and then becomes a real concern in the healthcare sector.
Furthermore, more professionals are retiring, and the young people can not keep up with the growth of the sector. There is then being put more pressure by this imbalance on already overworked medical staff. [@hunter-2024].
This results in a heightened workload and pressure on the remaining staff, who must maintain the high levels attention ot detail under physically and mentally taxing work environment.

Statistical data illustrates the magnitude of this issue. Since 2020 the number of patients on danish hospitals has risen by almost 200.000 [@dst]. Also since 2019 the amount of overtime done by nurses rose by 97%, and for ambulance drivers that increase was 219%. It's especially social workers, nurses and other workers in the public sector that's being overworked, they're typically dealing with difficulty sleeping, brain fog and constant stress as the result of overworking. [@FOA]

The combination of increasing patient numbers and overburdened staff underscores the urgent need for technological interventions that supports medical personnel. Automation and smart systems can play a critical role in reducing the workload, improving operational efficiency, and minimizing the risk of human error. In particular, a system capable of safely delivering medications to a given patients rooms can help alleviate the daily pressures on nurses and other hospital workers, allowing them to focus more on the patients care, rather than routine logistical tasks.

## Problem formulation
To address said challenges, this project proposes the development of an automated medicine delivery system comprising two primary components, a server and a self driving delivery car. The system is designed to streamline medicine distribution within the hospitals themselves, to ensure safe, timely and efficient delivery whilst reducing the cognitive and physical strain on nurses.

The server functions as a central control system. It receives medicine delivery orders submitted by dispensary nurses, specifying which rooms said order needs to visit on the next delivery. Once an order is received, the dispensary nurse loads the medicine into the self driving car. The server also handles all communication, between the client and car.

The self driving car receives the giving list of rooms from the server. Using these instructions, the car calculates the optimal delivery route to minimize travel, whilst ensuring all the given rooms are visited in a sequence that ends up at the homebase. The system is equipped with 2 LED indicators that signals when the car is ready to operate and which state it is in. Once the route is initiated, the car drives autonomously through the hospital corridors, stopping at the designated rooms for delivery.

Despite the automation, nurses remain integral to the process. They are the once responsible for confirming orders, loading the car, starting the route and the unloading of of the car once it reached the destination. This interaction ensures that nurses maintain oversight and control whilst the system handles the repetitive and time consuming tasks.

The proposed system is designed to enhance patient safety by reducing the likelihood of medication errors, optimize workflow and provide relief to overworked hospital personnel. By combining order management, autonomous navigation and supervision by nurses, the system represents a practical step toward modernizing the internal workflow of hospital operations and leveraging technology to address staffing challenges.

\newpage