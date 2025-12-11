\newcounter{risk}
\renewcommand{\therisk}{R\arabic{risk}}

\setlength{\extrarowheight}{3pt}
\renewcommand{\arraystretch}{1.2}


# Risk analysis
The risk analysis will contain all predictable risks, which can cause the project to be delayed, unfinished, or lack the expected quality. 

The identified risks will be categorized, and a risk score will be calculated for each item. The risk score is calculated by  
$$
\text{probability} \times \text{consequence}
$$

so the risk score will reflect the impact the risk item can have on the project.  

The probability and consequence of each risk item will be graded 1 to 5, where 1 is unlikely to occur or low consequence, and 5 is very likely to occur or a high consequence.  

The risk score will be used to prioritize the risk items, and to determine which risks need a mitigation strategy, and a contingency plan.  

\begin{figure}[H]
\begin{center}
\includegraphics[width=0.7\textwidth]{docs/diagrams/out/technical analysis/risk-matrix.png}
\caption{Risk matrix, showing the risk score based on probability and consequence \cite{haspod-2024}}
\end{center}
\end{figure}

Generally, the following actions will be taken based on the risk score:   

- **Low (1-9):** No immediate actions are taken.
- **Medium (10-17):** A mitigation strategy is developed, in order to prevent the risk.
- **High (18-25):** A mitigation strategy, as well as a contingency plan is developed. This way, there's a plan in place if the risk should occur.

However, in some cases, a mitigation strategy and contingency plan can be developed for low and medium risks as well, depending on the nature of the risk.

\begin{tabularx}{\textwidth}{|>{\centering\arraybackslash}p{1.5cm}|X|>{\centering\arraybackslash}p{1.2cm}|>{\centering\arraybackslash}p{1.2cm}|>{\centering\arraybackslash}p{1.2cm}|}
    \hline
    \multicolumn{5}{|c|}{\textbf{Technological Risks}} \\
    \hline
    \textbf{Risk ID} & \textbf{Description} & \textbf{Prob.} & \textbf{Cons.} & \textbf{Score} \\
    \hline
    \ref{risk:tech-learning-curve} & Technological learning curve & 3 & 3 & 9  \\
    \hline
    \ref{risk:sw-skills} & Software challenges in difficult parts of the project & 4 & 5 & 20 \\
    \hline
    \ref{risk:integrate-components} & Integration challenges between components & 3 & 2 & 6 \\
    \hline
    \ref{risk:hw-fail} & Hardware failures & 3 & 3 & 9 \\
    \hline
    \ref{risk:proper-components} & Lack of knowledge to choose proper components & 1 & 3 & 3 \\
    \hline
    \ref{risk:vc-break} & Version control breakdown & 3 & 3 & 9 \\
    \hline
    \ref{risk:ph} & Lack of knowledge or skills necessary to assemble the frame for the vehicle & 4 & 2 & 8 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{Team and Resources}} \\
    \hline
    \textbf{Risk ID} & \textbf{Description} & \textbf{Prob.} & \textbf{Cons.} & \textbf{Score} \\
    \hline
    \ref{risk:internal-conflicts} & Internal conflicts & 2 & 5 & 10 \\
    \hline
    \ref{risk:team-availability} & Availability of team members & 3 & 3 & 9 \\
    \hline
    \ref{risk:drop} & Complete or partial loss of team members & 1 & 5 & 5 \\
    \hline
    \ref{risk:skill-gap} & Skill gap amongst team members, as well as in comparison to the ambition levels & 2 & 3 & 6 \\
    \hline
    \ref{risk:work-ethics} & Work ethics & 3 & 4 & 12 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{Project Management}} \\
    \hline
    \textbf{Risk ID} & \textbf{Description} & \textbf{Prob.} & \textbf{Cons.} & \textbf{Score} \\
    \hline
    \ref{risk:requirement-changes} & Requirement changes & 3 & 4 & 12 \\
    \hline
    \ref{risk:dependency-delays} & Dependency delays & 4 & 4 & 16 \\
    \hline
    \ref{risk:scope} & Initial scope of the project might not match a realistic time frame & 4 & 3 & 12 \\
    \hline
    \ref{risk:scrum-experience} & SCRUM experience & 2 & 3 & 6 \\
    \hline
    \ref{risk:time-management} & Time management & 4 & 4 & 16 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{External Risks}} \\
    \hline
    \ref{risk:academic-deadlines} & Academic Deadlines & 4 & 4 & 16 \\
    \hline
    \ref{risk:ext-availability} & Availability of supervisor and other external helpers & 3 & 5 & 15 \\
    \hline
    \ref{risk:external-conflicts} & External conflicts & 2 & 4 & 8 \\
    \hline
    \ref{risk:finance} & Financial issues & 2 & 5 & 10 \\
    \hline
\end{tabularx}

\newpage
## Technical Risks
\refstepcounter{risk}\label{risk:tech-learning-curve}
**Risk ID:** \therisk\
**Description:** Technological learning curve.  
The project is based on knowledge and technological skills the team will get during the semester. The learning curve might not be as expected, resulting in a potential lack of important knowledge.  
**Probability:** 3  
Due to the limited time frame and other academic deadlines [\ref{risk:academic-deadlines}], team members might be otherwise occupied, and therefore not gain required knowledge as expected. Furthermore, other academic deadlines can cause team members to prioritize mandatory assignments, which can affect the quality of the knowledge gained, as well as steepen the learning curve.  
The team consists of eight people, which all contribute to the project. Not all team members need to know everything. The collective knowledge of the team can affect the project. The probability that no team member acquired the necessary knowledge, or have time to research the subject is low however.   
**Consequence:** 3    
Lack of knowledge can cause severe delays, since time will then be used to gain the knowledge required to accomplish a task.  
The quality of the final product can be affected as well.  
**Risk Score:** 9  
**Mitigation Strategy:** Lack of time due to academic deadlines [\ref{risk:academic-deadlines}] cannot be prevented. However, the team can minimize the issue by different project management strategies, allowing a small group of team members to research subjects. The best way to prevent the issue is to treat research as tasks to do for the project. This is implemented on the project board on GitHub. <!-- Omformuler og/eller henvis til metode og proces afsnit -->  

\refstepcounter{risk}\label{risk:sw-skills}
**Risk ID:** \therisk\
**Description:** Software challenges in difficult parts of the project.  
Concepts such as pathfinding, dead reckoning, and PID regulation are new to the team.  
**Probability:** 4  
There is a high probability that the team encounters challenges in the development process, especially for these three aspects of the project.  
**Consequence:** 5   
If one of these parts of the project are unfinished at the end of the project, the final product will have major flaws, and it will greatly impact the acceptance tests for the project. The final product might end up unfinished as a direct result of this.  
**Risk Score:** 20    
**Mitigation Strategy:** The issue cannot be prevented, but it is possible to prevent the timeline for the project to be critically affected. Extra time can be allocated to research and development of these important and challenging parts of the project. The project board on GitHub contain all tasks for the project. The scrum master [ see roles in collaboration agreement ] should be aware of this risk, and allocate time accordingly, as well as delegate tasks to team members with relevant knowledge.  
**Contingency Plan:** If the timeline is affected despite of the mitigation strategy, the team needs to prioritize the remaining tasks in the project. Furthermore, team members not working on these areas can provide support by handling less time consuming tasks.   

\refstepcounter{risk}\label{risk:integrate-components}
**Risk ID:** \therisk\
**Description:** Integration challenges between components.   
This risk applies to both hardware and software components. The project will likely be split into smaller, more manageable parts, and assigned as tasks to members of the team during the project.  
**Probability:** 3    
Integration challenges are very common, especially considering that different team members will be in charge of different components.  
**Consequence:** 2  
Usually these kinds of challenges are fixed at some point, though it can be a time consuming process.  
**Risk Score:** 6   
**Mitigation Strategy:** Enough time needs to be allocated to integrating submodules. Proper project management is important.  

\newpage

\refstepcounter{risk}\label{risk:hw-fail}
**Risk ID:** \therisk\
**Description:** Hardware failures.  
Any failures in hardware components, or in modules containing several components, is a risk for the project.  
**Probability:**  3  
Different kinds of hardware failures are common, just like they are for software. The project is however iterative, and so most problems will likely be fixed.  
**Consequence:**  3  
The consequences depends on the kind of failure. The worst case scenario is a broken component, which cannot be replaced within the time frame. However, this is not likely.  
Another failure could be defective wiring, which can be solved. The process of finding and fixing the error could be time consuming.  
**Risk Score:**  9  

\refstepcounter{risk}\label{risk:proper-components}
**Risk ID:** \therisk\
**Description:** Lack of knowledge to choose proper components.   
**Probability:**  1   
Basic knowledge of hardware was subjects of the previous semesters, so the team should be able to choose proper components, or research subjects necessary to choose the proper components for the project.    
**Consequence:** 3  
The ability to meet the requirements for the project can be affected if components are not chosen carefully.    
**Risk Score:** 3    

\refstepcounter{risk}\label{risk:vc-break}
**Risk ID:**  \therisk\
**Description:** Version control breakdown.   
**Probability:** 3    
The team have some knowledge of version control through a course on a previous semester. The experience with using it for projects on a larger scale varies amongst the team members.  
**Consequence:** 3  
The risk of a complete breakdown of the version control is improbable. A server breakdown is unlikely, but can happen, in which case there is a risk of a few commits being lost. Recovering lost commits can be time consuming. A bigger risk is the teams limited experience with using version control on a project shared with other team members. Building routines, protecting the work, etc. can be time consuming in the beginning of the project, but will improve as the project moves forward.  
**Risk Score:** 9   
**Mitigation Strategy:** One of the roles mentioned in the collaboration agreement is a GitMaster. This team member is responsible for proper use of version control for the project. This includes making sure that all team members are using version control properly, and that the work is protected. Furthermore, the GitMaster should help team members with any issues regarding version control.   
**Contingency Plan:** If the strategies for version control fails, the team needs to be prepared to spend time recovering any lost work, as well as implementing relevant strategies to prevent it from happening again.  

\refstepcounter{risk}\label{risk:ph}
**Risk ID:** \therisk\
**Description:** Lack of knowledge or skills necessary to assemble the frame for the vehicle.  
**Probability:** 4    
Designing and assembling the frame of the car is not within the scope of the education. Any knowledge and experience required should be sought through external sources.  
**Consequence:** 2  
If a frame is not properly designed and assembled, the final product will still be a prototype and a proof of concept. Even though it might not meet the teams level of ambition, the project can still be a success.   
**Risk Score:** 8   

\newpage

## Team and Resources
\refstepcounter{risk}\label{risk:internal-conflicts}
**Risk ID:** \therisk\
**Description:** Internal conflicts.  
**Probability:** 2  
Since the team consists of eight people, all dedicated to the project, the probability of conflicts are quite high. Furthermore, personal conflicts can occur, which will have the same consequence as professional conflicts.  
**Consequence:** 5    
Any time spend on conflicts will result in less time for working on the project. The timeline can be greatly impacted by this, which can interfere with the quality of the final product. 
Furthermore, personal conflicts can create a bad work environment. Motivation and ambition level can drop amongst the team members, which can cause work to be slower and of less quality.  
**Risk Score:** 10  
**Mitigation Strategy:**  Conflicts can be prevented by proper and clear communication, to avoid any misunderstandings.  
The team made a collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->] addressing the issue.    
**Contingency Plan:**  All team members have an assigned role, which they are responsible for. One role is Internal HR. If conflicts occur, and cannot be solved by the involved parties, the Internal HR is tasked with solving the conflict, or seek help from external sources. More details in the collaboration agreement. <!-- Indsæt reference til bilag: Samarbejdskontract -->  

\refstepcounter{risk}\label{risk:team-availability}
**Risk ID:** \therisk\
**Description:** Availability of team members.  
Members of rhe team can be unavailable due to illness, personal and private circumstances, etc. The academic deadlines [\ref{risk:academic-deadlines}] can cause unavailability as well, especially since members of the team are working in different groups across courses.  
**Probability:** 3   
It is likely that availability will vary throughout the semester. However, the probability that all team members are unavailable at the same time is low.  
**Consequence:** 3
Unavailable team members can cause delays, and a bigger workload for the remaining team members. However, if proper communication is maintained, the impact can be minimized.  
**Risk Score:** 9   

\refstepcounter{risk}\label{risk:drop}
**Risk ID:** \therisk\
**Description:** Complete or partial loss of team members.  
Members of the team can get severely ill, or drop out completely.  
**Probability:** 1   
Complete loss of team members is not likely, especially considering that this is a 3. semester project. However, there is a risk that a team member can get severely ill, resulting in a lot of sick days, or even partial leave.   
**Consequence:** 5   
If a team member is suddenly on part time, or drops out completely, the team needs to compensate for the lost member. The work this member could have contributed are missing, and the rest of the team is required to contribute extra to the project in order to reach the goals set in the beginning of the project.  
**Risk Score:** 5   

\refstepcounter{risk}\label{risk:skill-gap}
**Risk ID:** \therisk\
**Description:** Skill gap amongst team members, as well as in comparison to the ambition levels.  
If the collective knowledge in the team is insufficient to reach the goal set, and meet the level of ambition agreed upon in the collaboration agreement [], a skill gap occurs.   
**Probability:** 2  
Since the concept of the project was developed in the beginning of the semester, the basic idea of the project was made before the team had any experience with some of the concepts involved in the project [\ref{risk:sw-skills}].  
**Consequence:** 3  
If the collective knowledge is insufficient, the quality of the final product can be affected. The timeline can be affected as well, since time will be used to research subjects necessary to gain the knowledge required. However, if there is a skill gap between the team and the ambition level, the goals can be adjusted.  
**Risk Score:** 6  

\newpage

\refstepcounter{risk}\label{risk:work-ethics}
**Risk ID:**  \therisk\
**Description:** Work ethics.  
The members of the team can have different work ethics and level of ambition. The collective level of ambition was discussed and agreed upon in the collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->].   
**Probability:** 3  
A completely uniform level of ambition and work ethics is not likely. However, the team is in close communication, and the collaboration agreement should help minimize the issue.  
**Consequence:** 4  
The consequence depends on the severity of the issue. If the team developes a tendency to push the timeline for the project, or procrastinate important tasks, the quality of the final product can be affected. Furthermore, the timeline can be affected as well.  
**Risk Score:** 12   
**Mitigation Strategy:** The team needs to maintain proper communication, and address the issue if it should occur. The collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->] addresses the issue, and all team members have signed it. Furthermore, the role of Internal HR is assigned to a team member, who is responsible for handling such issues.   

\newpage

## Project Management
\refstepcounter{risk}\label{risk:requirement-changes}
**Risk ID:** \therisk\
**Description:** Requirement changes.  
Changes can happen due to lack of knowledge in the beginning of the project, as well as changes to the timeline, test and evaluation of the product at the end of iterations, etc.    
**Probability:** 3   
Changes in the requirements are likely to happen, especially in the beginning of the project. However, the process is iterative, and changes are expected to happen throughout the project.  
**Consequence:** 4  
The consequence depends on the severity of the changes. Minor changes can be implemented without affecting the timeline or quality of the final product. Major changes can affect both.  
Late changes in requirements can severely impact the project.  
**Risk Score:** 12   
**Mitigation Strategy:** The team needs to be in agreement regarding the requirements. The beginning of the project is used for this. Later changes have a bigger impact, and should be discussed and agreed upon by the entire team.  

\refstepcounter{risk}\label{risk:dependency-delays}
**Risk ID:** \therisk\
**Description:** Dependency delays.  
Delays can occur if a team member is waiting for another team member to finish a task, before they can start their own task.  
**Probability:** 4   
Some dependency delays are likely to happen, however, the probability of severe delays is low.    
**Consequence:** 4    
If severe delays should happen, the timeline for the project can be affected. Otherwise, delays can be minimized and managed with proper project management.  
**Risk Score:** 16   
**Mitigation Strategy:** Communicating the state of tasks on a regular basis is important. It is important that issues on the project board includes dependencies to other issues, and that the team members communicate with each other if they are blocked on a task.   

\refstepcounter{risk}\label{risk:scope}
**Risk ID:** \therisk\
**Description:** Initial scope of the project might not match a realistic time frame.    
**Probability:** 4    
The ambition level in the team is quite high, and the time frame is limited. The scope of the project might need to be adjusted.  
**Consequence:** 3   
If the scope is too ambitious, the timeline for the project can be affected. The quality of the final product can be affected as well, if the team is unable to finish all tasks in time.   
**Risk Score:** 12   
**Mitigation Strategy:** The timeline should be implemented as a focus point on the agenda for the scrum meetings. The scrum master should be aware of this risk, and allocate time accordingly, as well as delegate tasks to team members with relevant knowledge.     

\refstepcounter{risk}\label{risk:scrum-experience}
**Risk ID:**  \therisk\
**Description:** SCRUM experience.  
The experience with using SCRUM as a model for project management is limited amongst the team.   
**Probability:** 2   
It is very likely that unnecessary time are being spent on learning the SCRUM model, and the process of sprints. However, the process will be repeated several times during the project.  Therefore, the team will likely build routines, which can gradually decrease the time spent on project management.  
**Consequence:** 3     
Planning of sprints and task delegation can take up more time than necessary, since members of the team lack experience with the model.  
**Risk Score:** 6     

\newpage

\refstepcounter{risk}\label{risk:time-management}
**Risk ID:** \therisk\
**Description:** Time management.  
As mentioned in other risk items, the team will encounter several unfamiliar challenges during the project.  
**Probability:**  4  
There is a high probability of encountering new or unexpected tasks and challenges during the project, which can take up a lot of time. Time that could have been spent on development.   
**Consequence:**  4   
If the team is unable to effectively manage the available time, it will impact the project, and can affect the quality of the final product, as well as impair the teams ability to meet important deadlines.  
**Risk Score:** 16   
**Mitigation Strategy:** The team has a shared calendar for the project, as well as a clear timeline. The timeline is related to the issues on the project, and is found on the GitHub project board. The timeline and current state of the project is therefore clearly visible to all team members. The scrum master is responsible for maintaining the timeline, and allocating time accordingly, as well as delegate tasks to team members with relevant knowledge.   

\newpage

## External Risks    
\refstepcounter{risk}\label{risk:academic-deadlines}
**Risk ID:** \therisk\
**Description:** Academic Deadlines.  
Deadlines and assignments in other courses can affect the availability of team members.  
**Probability:** 4  
Deadline conflicts are very likely to happen. The semester is a bit more heavy on deadlines and assignments than the previous semesters, and team members are required to adjust to this.  
**Consequence:** 4  
If multiple deadlines happen close to each other, the team members will be otherwise occupied, resulting in less work on the project. The amount of hours that each team member can contribute per week might vary. An average hours per week estimate was made in the collaboration agreement. <!--bilag -->    
**Risk Score:** 16  
**Mitigation Strategy:** The team has a shared calendar for the project, and a team member is responsible for maintaining it [ref bilag samarbejdskontrakt]. In most of the other courses, members of the team are working in groups with other team members. Therefore, the team members can delegate tasks with respect to the academic deadlines.    

\refstepcounter{risk}\label{risk:ext-availability}
**Risk ID:** \therisk\
**Description:** Availability of supervisor and other external helpers.  
**Probability:** 3   
The supervisor appointed to the team can be unavailable due to illness, personal and private circumstances, etc. Furthermore, the supervisor are appointed to several teams, and therefore might not be available when the team needs help.   
External helpers and resources can have conflicting schedules as well.   
**Consequence:** 5    
If the supervisor or external helpers are unavailable at critical times, the timeline for the project can be affected, and important questions can go unanswered. Since the the project involves multiple new concepts [\ref{risk:sw-skills}], unanswered questions can severely impact the project.  
**Risk Score:** 15   
**Mitigation Strategy:** Deadlines and questions should be communicated to relevant external helpers in a timely manner, in order to avoid any conflicts, resulting in a critical impact on the project.  
In order to avoid the timeline to be critically affected, work on the project can be done in parallel where possible. This is best accomplished by clearly separating the product into modules, and by continuously working on the report, as well as supportive and administrative tasks. This way, less time is wasted when the team is awaiting answers.   
**Contingency Plan:** If the timeline is affected, the team needs to reprioritize the remaining tasks in the project. The project is iterative, so the team can help the issue by making a prototype meeting the basic requirements, and then improve on the existing prototype.  

\refstepcounter{risk}\label{risk:external-conflicts}
**Risk ID:** \therisk\
**Description:** External conflicts.  
This includes conflicting schedules and resources, which can impact the project timeline and deliverables.  
**Probability:** 4  
Conflicting schedules and resources are likely to happen, especially if the team is relying on multiple external resources [\ref{risk:ext-availability}].  
**Consequence:** 2  
Even though external conflicts can cause delays and force a change of strategy, the project is relying primarily on the team members involved. Therefore, the consequence is not likely to be severe.  
**Risk Score:** 8  

\newpage

\refstepcounter{risk}\label{risk:finance}
**Risk ID:** \therisk\
**Description:** Financial challenges.  
The project is primarily based on resources and components provided by Aarhus University. However, some components or additional items might need to be purchased externally.  
**Probability:** 2  
There is a low probability of financial challenges, since the project is primarily based on resources and components provided by Aarhus University.  
**Consequence:** 5   
If the team decides to purchase additional items, not provided by AU, the team members will need to cover the costs themselves. This can affect the ambition level of the project, as well as the quality of the final product.  
**Risk Score:** 10    
**Mitigation Strategy:** Should the team decide to purchase additional items, a budget should be made, and all team members should agree on it. The budget should be as low as possible, in order to minimize the risk of financial challenges.   


\newpage