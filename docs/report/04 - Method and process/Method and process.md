---
title: "SW3 Semester Project"
subtitle: "Self Driving Medicine Delivering System"
date: "12/12/2025"
fontsize: 12pt
geometry: margin=2cm
---

\begin{center}



\vspace{1cm}


\vspace{2cm}

\begin{tabular}{r r r}
\hline
\textbf{Students} & \textbf{Student number} & \textbf{Initials} \\
\hline
Johan Høffner & 202409238 & JH \\
Line Nystrup Klemensen & 202407497 & LK \\
Nicolai Broholm Hansen & 202409080 & NH \\
Frederik Vagn Lorenzen & 202406665 & FL \\
Daniel Jenrich Svendsen & 202408416 & DS \\
Mikkel Kristiansen & 202301563 & MK \\
Kasper Ørtoft Rasmussen & 202207121 & KR \\
Christopher Frank Jørgensen & 202300791 & CJ \\
\hline
\end{tabular}

\vspace{1.5cm}

\textbf{Project Counselor} \\
“Jenny” Jung Min Kim

\vspace{2cm}

Submission date: \textbf{12-12-2025} \\[6mm]



University Name: Aarhus University \\
Degree / Program: Software Engineering

\end{center}

\clearpage

# Index

\newpage


# Method and Process
In this project, specific tools have been utilized to ensure a clean, systematic and well documented process from idea to prototype. The methods used have been is a combination of requirements specifications, technical assesments, analyses and design. All of these choices have been made with the purpose of creating a solid fundation for implementation.

**Brainstorm**  
The projects idea phase was initalized with a brainstorm, utilizing the "dont say no" method. Where all ideas are weighted equally. Afterwards all ideas have been critized and looked over untill a final idea emerged that everyone could agree on.

  
**MoSCoW**  
For prioritization MoSCoW have been utilized to categories all requirements in to categories such as *Must have*, *Should have*, *Would have* and *Wont have*. Using these categories all requirements got sorted depending on how important they were for the project and if there would be enough time and know how to properly execute them.


**SysML**  
When creating the system arkitecture, system modeling language(SysML) was used. Here two diagrams created: 

* **Block Definition Diagram(BDD)**  
BDD Shows the entire system, and the relationship between different hardware blocks, and how they connect to eachother.  

* **Internal Block Diagram(IBD)**  
IBD Describes the different internal connections and signals, between the blocks in the system and the rest of the world.  
  
**UML**  
For the software arkitecture, Unified Modeling Language(UML) have been utilized. Here under are the following diagrams and models used:  

* **State Machine Diagram(STM)**  
STM is used to show the different states and transistions the system can be in and what happens when entering, leaving or staying in those states.  

* **Domain model**  
Domain model is used to identify important, objects and relations in the system.  

* **Sequence Diagram(SD)**  
The SD's shows how the different blocks and actors connects and communicate in sequence.  

* **Application model**
Application models, are made up of class diagrams and sequence diagrams with function calls. They show how different hardware blocks and function calls are structured on each CPU in the system.  
  
**Technical analysis**  
For chosing componets and programming language, a technical analysis was performed, weighing all the differnt options for hardware and langauge agianst as many possible factors as possible. This ensured that the componets that got chosen were the best suited to complete the project with as few mistakes as possible.

\newpage

# Process
## Group creation  
The group was created based on a mixture of insight profils, and previous experiences working together across different classes. Most people from the group had found out from previous experiences they worked well together. Whereafter the insight profils were used to try and fill the gaps in the group to make sure it was well rounded and could work. The insight profils goes as follows:  
   

* **Supporting coordinater (green/blue)**  
* **Coordinating observer(blue/green)**  
* **Coordinating supporter(blue/green/yellow/red)**  
* **Creative entrepreneur(red/green)**  
* **Coordinating observer(blue/green)**  
* **Coordinating observer(blue/green)**  
* **Coordinating supporter(green/blue)**  
* **Line insert**
  
As seen above allot of the profiles pointed towards a passive approach to the project which it was decided to look for more memember that was more "red-ish" to get a broader group and more well rounded personalities. This helped give the group more people to grab the tasks rather then wait for someone to take charge, meanwhile the rest could focus more energy on making sure the project was propperly structured and running on time.

## Collaboration contract  
In this project a collaboration contract have been used to keep a high standard, aswell as having a document to reffere back to, whenever disagreements would arise. The collaboration contract is located in the appendix under "collaboration contract".  

The collaboration contract have been a usefull tool for us to keep the work going aswell as keep a good and orderly work culture. This have been usefull in instances where the group have had to take decisions to repermand group memembers in ways that did not seem to harsh. This intailed creating the cake order, where if a memember would show up late or no call no showed, they would owe cake and would have to bring some for the next meeting. The only exception to this rule, was if the group was warned before hand or if some extrodinary circumstance prevented the person from showing up, such as a family memember falling ill. This also meant the rule was very flexible, since the group did not like giving "punishments".  

Luckily just having this system in place really helped make sure everyone showed up aswell as made way for creating jokes and keeping people a bit on their toes when it came to show up for meetins, group work etc. Which meant that people would show up smiling and happy to work, with little to no problems.
 
## Development timeline  
In this project the scrum method have been used to structure the work. Scrum is a way of working which intails working in sprints of 1 to 4 weeks where people work closely together on completing their assignments for that sprint. These sprints start with a planing phase and ends with a evaluating phase at the end of the sprint.  

Scrum puts allot of weight group work, the way that has been done here is with having sprints lasting 2  weeks, where doing the first sprint the scrum master would plan the current sprint and delocate tasks to different memembers of the group. At which point those memembers would start working on that part of the project. On top of that there would be weekly meetings to check progress and see if anyone needed help. This gave space to check up on eachother offer help and ask for assistence in specific problems.  

Furthermore this project have been build on the Aarhus university semesterproject model, which consist of an assortment of development phases. The project started in the problem formulating phase, where the vision for the project was defined, and the scope got focused to make sure the project was also doable. Hereafter the requirement specification phase came where the requirements for the project got defined and functional and none functional requirements got made, along side fully dressed use cases.  

Design and implementation phase were completed parral to eachother, doing these at the same time allowed for more room to change different design choices that did not seem feesable to create or implement smarter solutions that might arise while writting code, or creating hardware. Hereafter an intergrationtest was developed, and completed at the end the accepttest was checked and completed which is where we validate the systemsfunctionality based on the requirements.

## Project management  
To better control the flow of work and make sure everything was kept in order, every member of the group was given a specific role that they were in charge of. This helped better divide up sudden tasks aswell making sure there always was a person to ask about specific needs of the group. All of these roles are detailed in the collaboration contract.  

Some of these roles include a scrum master, scrum assistent, contact person, GIT master, meeting leader, note taker, and internal HR. Scrum master and assistent ran the scrum meetings managed the backlog and made sure deadlines were met, the GIT master functioned as a quality controll making sure the git was kept nice and tidy aswell as approving all code. The contact person have been in charge of contacting review groups aswell as the supervisor of the project. Meeting leader and note taker made sure there always was an agenda and a summery of the meetings. Internal HR was a role that was made to make sure that if conflict would appear in the group a impartial party would be able to step in and midiate the conflict and make sure work could continue on schedule.  

This division of roles allowed for everyone to have a area to put some extra focus. The roles have worked well for most of the semester, however towards the end most of roles became very muddied since many of the areas that was worked in started overlapping, especially since meetings with supervisors and review groups became fewer, and fewer.  

## Work distrubution  
Work distrubution have partly been based on what each person had a desire to work with, aswell as what played to each persons strengths. This have left room for some memembers to take charge on areas like system architechture where others have been able to take the lead on code, and hardware. This have helped create a culture where everyone have been able to shine and give it 110% when it comes to their passion in the project.  

Furthermore a rule was established in the group that every memeber of the group needed to "touch some code". This meant that every single memember needed to be able write themselves as atleast somewhat responsible for an amount of code.  

## Planing  
At the start of this project a timetable of what needed to be done when was created. This timetable was followed for the first couple of months, untill the group ran into problems with use cases which ended up setting it abit behind. From that point on the timetable sadly ended up on the backburner and was largely forgotten untill implementations.

The timetable is documented in the appendix, which is the one the group made and tried to follow through out this project.  

## Project administration  
The group have been administrated with clear work distrubution and meetings twice a week, one with the group for scrum purposes and one with the supervisor. Furthermore a timetable was set to keep the project on track, this tool was not utilized or realised to it's fullest potential due to neglect it got. The platform Git was used to keep trak of the backlog of assignments that needed to be completed aswell as the timetable and code. External communication to other groups and supervisors was done over AU's internal email. Internal communication happend over discord.  

## Meetings  
Every week there was two meetings planned, first a meeting with the supervisor, and then a internal meeting. Supervisor meetings would take place ever Tuesday in the Hamilton building(AU 5123), and it would last from 10 to 12. Then the following an internal meeting would be done every wensday in the Shannon building(AU 5789), these would be primarily scrum meetings and check in meetings to make sure the project was running on time. Furthermore for every meeting the with the supervisor the agenda and any additional material needed to be send atleast 24 hours in advance of the meeting.  

Typically the agendas consisted of: 

* Walk through points from previous meetings  
* Supervisor feedback to the sent material  
* Questions about the project to the supervisor  
* Deciding who is going to be the next meeting leader and note taker.  


## Conflict handling  
Through this project the group has not experienced many challenges that would constitute having to handel it as a conflict. The few bumps in the road that have been experience have been swiftly handled with the help of internal HR. The only minor conflicts that have been had, have been absense from memembers for short periods of time or code etiquette, deciding between pillow, snake and camel case.  

However both of these conflicts was handled swiftly with discord being used to communicate with the absent memember and a vote was had for code etiquette, with the stimulation that there were no hard feelings after the vote.

## Conclusion  
This project have been a challenging and teaching experience, we have had free oppertunity to choose our own project based on the perameters placed by the project supervisor. This have given space to find a interesting project to dive down into. Through this project scrum have been used to keep track of the progess and stay on top of the work through out. Furthermore insight profils have been used to find the missing memember of the group to make sure the group was more well rounded as we thought that would make more sense and be a good tool to make sure the group was not compeletly one sided.  

Below are the individule conclusions from each group memember, refelcting back on the project. Both in terms of how the group work felt, and how the work went but also what could have gone better aswell as reflecting on what to do and not to do next semester.


### Christopher Frank Jørgensen  


### Daniel Jenrich Svendsen  


### Frederik Vagn Lorenzen  


### Johan Høffner  


### Kasper Ørtoft Rasmussen  
This project have been both very hard and very rewarding. The project as a whole have been very open in terms of what each group have wanted to do and design. Were as this normally would have cost me allot of trouble, do to decision paralayzis, this semester it has not been an issue at all due to other people in the group being very creative and generally good at idea creation. Using scrum for this semester have personally been a victory since it sets clear expectations and deadlines for when different parts of the project have to be done. The group work itself have for the most part been excellent and have functioned well due to everyone in the groups willingness to help were needs be and not being afraid to admit they needed help.  

This however did also open the door to the only and biggest problem that I felt like we had as a group. That being some if not most memembers are very independt thinking people, which would result in some people showing up having made huge steps forward in the work while others did not. Which could sometimes lead to the feeling of being lazy or even abit behind. However most of the instances of this happning was later dicussed and everyone got caught up on the work.  

Personally for the future I would say a big step that needs to be taking, is to better organize how and when work is done. This also includes better using and maintaining the timetable. 

### Line Nystrup Klemensen  
Working in a group has been challenging for me in the past, and has caused some problems in this project as well. This project has thought me a lot about how I work with other people, and what I can do to improve my collaboration skills in the future. 

### Mikkel Kristiansen  


### Nicolai Broholm Hansen  


## Sources
\newpage
