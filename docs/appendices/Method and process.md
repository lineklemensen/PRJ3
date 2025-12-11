---
title: "SW3 Semester Project"
subtitle: "Method and Process"
fontsize: 12pt
geometry: margin=1.5cm
---

\begin{center}


\includegraphics[width=0.28\textwidth]{docs/appendices/pictures/AU.png}


\vspace{0.6cm}


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

\vspace{0.8cm}

\textbf{Project Counselor} \\
“Jenny” Jung Min Kim


Submission date: \textbf{12-12-2025} \\[6mm]

University Name: Aarhus University \\
Degree / Program: Software Engineering

\end{center}

\clearpage


\clearpage

\newpage


# Method and Process
In this project, specific tools have been utilized to ensure a clean, systematic and well documented process from idea to prototype. The methods used have been a combination of requirement specifications, technical assesments, analysis and design. All of these choices have been made with the purpose of creating a solid foundation for implementation.

## Brainstorm  
The projects idea phase was initalized with a brainstorm, utilizing the "dont say no" method. Where all ideas are weighted equally. Afterwards all ideas have been critized and looked over untill a final idea emerged that everyone could agree on.

  
## MoSCoW   
For prioritization MoSCoW have been utilized to categorize all requirements in to categories such as *Must have*, *Should have*, *Could have* and *Wont have*. Using these categories all requirements got sorted depending on how important they were for the project and if there would be enough time and know how to properly execute them.


## SysML
When creating the system architecture, system modeling language(SysML) was used. Here two diagrams was created: 

* **Block Definition Diagram(BDD)**  
BDD shows the entire system, and the relationship between different hardware blocks, and how they connect to each other.  

* **Internal Block Diagram(IBD)**  
IBD describes the different internal connections and signals between the blocks in the system and the rest of the world.  
  
**UML**  
For the software architecture, Unified Modeling Language(UML) has been utilized. The following diagrams and models have been used:  

* **State Machine Diagram(STM)**  
STM is used to show the different states and transistions the system can be in and what happens when entering, leaving or staying in those states.  

* **Domain model**  
Domain model is used to identify important, objects and relations in the system.  

* **Sequence Diagram(SD)**  
The sequence diagrams shows how the different blocks and actors connects and communicate in sequence.  

* **Application model**  
Application models are made up of class diagrams and sequence diagrams with function calls. They show how different hardware blocks and function calls are structured on each CPU in the system.  
  
## Technical analysis 
For chosing components and programming language, a technical analysis was performed, weighing all the differnt options for hardware and langauge agianst as many possible factors as possible. This ensured that the componets that got chosen were the best suited to complete the project with as few mistakes as possible.

# Process
## Group creation  
The group was created based on a mixture of insight profiles, and previous experiences working together across different classes. Most people from the group had found out from previous experiences they worked well together. Whereafter the insight profils were used to try and fill the gaps in the group to make sure it was well rounded and could work. The insight profiles goes as follows:  
   

* **Supporting coordinater (green/blue)**  
* **Coordinating observer(blue/green)**  
* **Coordinating supporter(blue/green/yellow/red)**  
* **Creative entrepreneur(red/green)**  
* **Coordinating observer(blue/green)**  
* **Coordinating observer(blue/green)**  
* **Coordinating supporter(green/blue)**  
* **Supporting coordinator(green/blue)**
  
As seen above a lot of the profiles pointed towards a passive approach to the project which it was decided to look for more member that was more "red-ish" to get a broader group and more well rounded personalities. This helped give the group more people to grab the tasks rather than wait for someone to take charge, meanwhile the rest could focus more energy on making sure the project was propperly structured and running on time.

## Collaboration contract  
In this project a collaboration contract has been used to keep a high standard, as well as having a document to refer back to, whenever disagreements would arise. The collaboration contract is located in the appendix under "collaboration contract".  

The collaboration contract has been a useful tool for us to keep the work going as well as keep a good and orderly work culture. This has been useful in instances where the group have had to take decisions to reprimand group members in ways that did not seem to harsh. This intailed creating the cake order, where if a member would show up late or no call, no showed, they would owe cake and would have to bring some for the next meeting. The only exception to this rule, was if the group was warned before hand or if some extraordinary circumstance prevented the person from showing up, such as a family member falling ill. This also meant the rule was very flexible, since the group did not like giving "punishments".  

Luckily just having this system in place really helped make sure everyone showed up as well as made way for creating jokes and keeping people a bit on their toes when it came to show up for meetings, group work etc. Which meant that people would show up smiling and happy to work, with little to no problems.
 
## Development timeline  
In this project the scrum method have been used to structure the work. Scrum is a way of working which intails working in sprints of 1 to 4 weeks where people work closely together on completing their assignments for that sprint. These sprints start with a planing phase and ends with a evaluating phase at the end of the sprint.  

Scrum puts a lot of weight on group work, the way it has been done here is by having sprints lasting 2 weeks, where doing the first sprint the scrum master would plan the current sprint and delegate tasks to different members of the group. At which point those members would start working on that part of the project. On top of that, there would be weekly meetings to check progress and see if anyone needed help. This gave space to check up on each other offer help and ask for assistance in specific problems.  

Furthermore this project was built using the Aarhus University semesterproject model, which consists of an assortment of development phases. The project started in the problem formulating phase, where the vision for the project was defined, and the scope got focused to make sure the project was also doable. Hereafter the requirement specification phase came, where the requirements for the project got defined and functional and none functional requirements got made, along side fully dressed use cases.  

Design and implementation phase were completed parallel to eachother, as doing these at the same time allowed for more room to change different design choices that did not seem feesable to create, while writing code and creating hardware. Hereafter an intergration test was developed, and completed. At the end the acceptance test was checked and completed which is where we validate the systems functionality based on the requirements.

## Project management  
To better control the flow of work and make sure everything was kept in order, every member of the group was given a specific role that they were in charge of. This helped better divide up sudden tasks aswell making sure there always was a person to ask about specific needs of the group. All of these roles are detailed in the collaboration contract.  

These roles consists of scrum master, scrum assistent, contact person, GIT master, meeting leader, note taker, and internal HR. Scrum master and assistent ran the scrum meetings, managed the backlog and made sure deadlines were met. The GIT master functioned as a quality control making sure the git was kept nice and tidy as well as approving all code. The contact person have been in charge of contacting review groups aswell as the supervisor of the project. Meeting leader and note taker made sure there always was an agenda and a summery of the meetings. Internal HR was a role that was made to make sure that if conflict would appear in the group a impartial party would be able to step in and mediate the conflict and make sure work could continue on schedule.  

This division of roles allowed for everyone to have a area to put some extra focus. The roles have worked well for most of the semester, however towards the end most of roles became very muddled since many of the areas that was worked in started overlapping, especially since meetings with supervisors and review groups became fewer, and fewer.  

## Work distrubution  
Work distrubution have partly been based on what each person had a desire to work with, as well as what played to each persons strengths. This have left room for some memembers to take charge on areas like system architechture where others have been able to take the lead on code, and hardware. This have helped create a culture where everyone have been able to shine and give it 110% when it comes to their passion in the project.  

Furthermore a rule was established in the group that every memeber of the group needed to "touch some code". This meant that every single member needed to be able write themselves as atleast somewhat responsible for an amount of code.  

## Planing  
At the start of this project a timetable of what needed to be done when was created. This timetable was followed for the first couple of months, until the group ran into problems with use cases which ended up setting it abit behind. From that point on the timetable sadly ended up on the backburner and was largely forgotten until implementation.

The timetable is documented in the appendix, which is the one the group made and tried to follow throughout this project.  

## Project administration  
The group have been administrated with clear work distrubution and meetings twice a week, one with the group for scrum purposes and one with the supervisor. Furthermore a timetable was set to keep the project on track, this tool was not utilized or realised to it's fullest potential due to the neglect it got. The platform GitHub was used to keep track of the backlog of assignments that needed to be completed aswell as the timetable and code. External communication to other groups and supervisors was done over AU's internal email. Internal communication happened over Discord.  

## Meetings  
Every week there were two meetings planned, first a meeting with the supervisor, and then a internal meeting. Supervisor meetings would take place ever Tuesday in the Hamilton building(AU 5123), and it would last from 10 to 12. Then the following an internal meeting would be done every wednesday in the Shannon building(AU 5789), these would be primarily scrum meetings and check in meetings to make sure the project was running on time. Furthermore for every meeting with the supervisor the agenda and any additional material needed to be send at least 24 hours in advance of the meeting.  

Typically the agendas consisted of: 

* Walk through points from previous meetings  
* Supervisor feedback to the sent material  
* Questions about the project to the supervisor  
* Deciding who is going to be the next meeting leader and note taker.  


## Conflict handling  
Through this project the group has not experienced many challenges that would constitute having to handle it as a conflict. The few bumps in the road that have been experience have been swiftly handled with the help of internal HR. The only minor conflicts that have been had, have been absense from members for short periods of time or code etiquette, deciding between, snake and camel case.  

However both of these conflicts was handled swiftly with discord being used to communicate with the absent member and a vote was held for code etiquette, with the stipulation that there were no hard feelings after the vote.

## Conclusion  
This project have been a challenging and teaching experience, we have had free opportunity to choose our own project based on the parameters placed by the project supervisor. This have given space to find a interesting project to dive into. Throughout this project scrum have been used to keep track of the progess and stay on top of the work through out. Furthermore insights profiles have been used to find the missing member of the group to make sure the group was more well rounded as we thought that would make more sense and be a good tool to make sure the group was not compeletly one sided.  

Below are the individual conclusions from each group memember, refelcting back on the project. Both in terms of how the group work felt, and how the work went but also what could have gone better aswell as reflecting on what to do and not to do next semester.


### Christopher Frank Jørgensen  
It was easy to feel a difference in our project group, now that we can pick who we want to work with. It felt a lot better to work with people you knew you could work with. Even though it did end up that I would easily get chatty with the others and then procrastinate the work. We do know now that we should have had more communication in the group. Especially myself with hearing if people need help, as people in the group have also been asking for help with verifying that what they did was good, I should have been a lot better at helping people out with that. In general, I wasn’t very focused on what needed to be done.  

I also made very poor hardware decisions, with the parts i needed to handle, to the point where someone else needed to handle it. In the future I will not let that happen again, and I will be more open to needing help. Using GitHub for the report was very likely not the right choice. I think we should go back to using overleaf to handle all the report work next semester. Using GitHub for everything else, all our files, were very nice as it was very easy to find what you were looking for and everything stayed organized. We could also very easily see what was committed to the repository, so it was easy to follow where things were going wrong.  

Overall, the experience of this project was the most enjoyable out of all the semesters so far, and I'm expecting the next to be even better. Working with our current advisor was also good, as she pushed us in the right direction. I think we could also have been way better at following our timeline, as it ended in us finding hardware issues way too late. In relation to next semester, I would love to work with a lot of the same people as this semester.  

### Daniel Jenrich Svendsen  
This semester project came with a couple new challenges, it was a lot more free in the sense that it's the first project where we fully get to pick our own groups, as well as the theme of the project being completely free. This led to a very enjoyable working experience where everyone was largely able to work on their own time, and if someone needed a break, or need an extra hour in the morning, that was just allowed.

Although towards the later half of the semester we started to slip from our schedule, which didn't immediately seem to cause any issues but towards the final couple of weeks we really started to feel the pressure, and challenges from integrations. Unfortunately this led to us having to prioritise the core functionality over smaller nice-to-have features.

I worked with developing the TUI for the project, and i'm quite satisfied with its outcome, i wanted to design something that would be general enough to also be useful for other personal side projects, and i believe the current iteration satisfies that to a good extent, although like most software, it'll probably be better on the next rewrite.

### Frederik Vagn Lorenzen
At the start of the project, we underestimated the size of the task we had taken on, maybe because we had some experience with programming a car from our 1st semester, or perhaps we were just too enthusiastic. Regardless of why, we encountered a huge time crunch towards the end, which hindered us from being as iterative with this project as we had liked, since we struggled with even getting our prototype ready in time for our acceptance test, which is obviously not ideal. This semester was also our first time working with Scrum, which we also brought along some confusion and growing pains. 
However, I still think this project has been very beneficial to my development as a software engineer, becoming way more comfortable with Git, which I have become quite familiar with at this point, and in general, especially towards the end of the project, becoming more aware of how important it is to be on the same page as the people you work with, as I believe better communication would have resulted in our final prototype being better and less frustration/burnout towards in the time crunch towards the end of the project.  

Overall I still think the project was a success, becoming a lot more familiar with Scrum, and creating a product without a lot of supervision or requirements, helping us become more independent as software developers. 


### Johan Høffner  
The project this semester have been very different from the once before this, since this is the first time we got to make the groups on our own, and not being balanced by the insights profile scores. This lead us to already from the start of the project to give people roles and responsibilities so even though we shared a lot of traits within the group we could still cover all the bases.

Even with good work ethic and atmosphere we ran into a problem of sorts, that people sometimes had a hard time actually making a decision, to make sure it didn't conflict with anyone or how someone wanted it to be. It sounds like a good thing but sometimes it grind our progress to a halt. Moving forward and if the group decides to work together on another project it would benefit a lot people would be quicker and more decisive to make decisions and roll with them.

Everyone in the group is a hard worker and everyone felt like they wanted to accomplish the project in good fashion. Everyone also have good understand of software, the projects goal, problem solving skills and could independent, so more often that not people in the group would work outside of the agreed work schedule. This came both with good and bad effects, the good being that when we got behind on our time line, the independent work could catch us straight up again so we could meet the final deadline, but the bad part became that people sometimes felt left behind or that they didn't put in the same amount of work as someone else in the group. I see it as everyone had different times throughout the project to shine, it helped lessen the workload from others and helped the morale to always see changes and progress in the project.

In conclusion the group had a good work flow and worked together nicely, but more open communication, order and structure would elevate on the process and project as a whole.

### Kasper Ørtoft Rasmussen  
This project have been both very hard and very rewarding. The project as a whole have been very open in terms of what each group have wanted to do and design. Were as this normally would have cost me allot of trouble, do to decision paralayzis, this semester it has not been an issue at all due to other people in the group being very creative and generally good at idea creation. Using scrum for this semester have personally been a victory since it sets clear expectations and deadlines for when different parts of the project have to be done. The group work itself have for the most part been excellent and have functioned well due to everyone in the groups willingness to help were needs be and not being afraid to admit they needed help.  

This however did also open the door to the only and biggest problem that I felt like we had as a group. That being some if not most memembers are very independt thinking people, which would result in some people showing up having made huge steps forward in the work while others did not. Which could sometimes lead to the feeling of being lazy or even abit behind. However most of the instances of this happning was later dicussed and everyone got caught up on the work.  

Personally for the future I would say a big step that needs to be taking, is to better organize how and when work is done. This also includes better using and maintaining the timetable. 

### Line Nystrup Klemensen  
Working in a group has been challenging for me in the past, and has caused some problems in this project as well. This project has taught me a lot about how I work with other people, and what I can do to improve my collaboration skills in the future.  
This project is the first time we have been able to choose our own group members. This choise has brought both advantages and disadvantages. On one side, it means that we know each other well, and have a good understanding of each other's strengths and weaknesses. On the other side, it also means that difference of opinions can grow into conflicts, and can be more difficult to resolve, because it can affect our personal relationships.  
Overall, I think the group has worked well together. We have been able to communicate effectively.

The technical aspects of the project has brought some interesting challenges as well. The project had very broad requirements, which meant that we were able to base our ideas on our own interests. However, since the group consists of very ambitious people, this also meant that we have had a tendency to take on too much work, which has caused some stress and pressure throughout the project. In the future, I think it would be beneficial to set more realistic goals, and to prioritize tasks more effectively. This would help to ensure that we are able to complete the project on time, without feeling overwhelmed.

### Mikkel Kristiansen  
From the very start this semster projekt has been diffrent compared to previous ones because the groups were not made by the teachers but rather us students deciding ourselfs. Since the group already knew each other, we did not need to spend a lot of time getting to know each other, which sped up the early phase of the project and allowed us to get stright into brainstorming ideas. 
  
Everyone was quickly assigned a role such as scrum master, git master, group leader, referent etc. With the roles devided a structure was quickly established giving us a better workflow and sense of order. Meetings with our advisor were great and very helpfull even though some of them could get a bit frustrating at times. Another thing i learned throughout this semester is that we were a bit too reliant on our adviser saying "good" to everything insted of us making a decision and going with it. 
  
Because the group work was split, everyone for the most part had something to do but that also meant there was some confusion among group members, since people were in doubt about what was being written and how far everyone was with their individual work. The Scrum meetings, and the fact that the group was sitting together every day, were the main reasons this problem did not become so big that the work structure would collapse, and they made sure we could continue working in a stable way. 
  
Personally, I was not that good at using GitHub to do reviews, pull requests and see the updated content in our documents. This is something I need to improve on going forward, since it could have helped with catching a few, or even a lot of the problems that were present in the documents. 
  
My conclusion is that as a group we worked together pretty well, but we should improve in some areas to really boost the efficiency of our workflow and minimize internal confusion. Another place to improve is also to better spread out the workload, since some of the group members had a significantly higher workload compared to others.  


### Nicolai Broholm Hansen  

This semester was the first time we were allowed to form our own groups, which resulted in a team where our expectations for the project were aligned. It also meant that many of us already knew each other well and worked comfortably together. However, this did not completely eliminate communication challenges. When we split into smaller sub-groups, there were still moments where information did not flow as clearly as it should have. Despite this, the group as a whole collaborated effectively, and everyone contributed actively to the project. Many decisions were made collectively, and even though decision making is not something I usually feel confident with, I noticed myself becoming more comfortable with it throughout the semester.

We used Scrum to structure the work and decide which tasks to prioritize, and for most of the project this proved helpful. Towards the end, however, Scrum alone was not enough, especially as deadlines from other courses piled up. Next semester, I think it will be important to plan our internal deadlines more carefully to account for the workload in other classes.

Overall, the group functioned well, and I would be happy to work with the same people again in a future project. With slightly better communication, I believe the collaboration could become even stronger.

\newpage
