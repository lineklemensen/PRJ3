Summary

4th semester has a completely different project developement model, due to it being completely web based.

Other groups might use a different "deployment model" instead of bdd/ibd. Ignore that, Jenny will back our choice of method

Combine all SD to one big one, with all UC for system architecture

AP-modeller should be split per UC.

BDD needs a main/top block with name of combined system. All other blocks should point that.  
Car and Server needs to point to system, then it has the other inheriting components  
Computer needs to be composition under system, as it's a independent part of the system.  

Double check BDD names, be careful with naming components RPI, use controller instead

IBD - Put car in a bigger box, bigger box contains server + computer(ui)
Capitalize wifi -> WiFi, remove HTTP line

STM - State change can only happen with happy path - No error handling allowed, it implicityly happens in Idle state.

Instead of a choice, use 2 arrows with separate guard clauses to control the flow of states.


For next: 
Design, with more details.

Reccomended everyone tests restinio lib