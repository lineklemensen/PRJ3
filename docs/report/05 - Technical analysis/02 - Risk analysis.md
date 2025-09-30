\newcounter{risk}
\renewcommand{\therisk}{R\arabic{risk}}


# Risk analysis
The risk analysis will contain all predictable risks, which can cause the project to be delayed, unfinished, or lack the expected quality. 

The identified risks will be categorized, and a risk score will be calculated for each item. The risk score is calculated by  
$$
\text{probability} \times \text{consequence}
$$

so the risk score will reflect the impact the risk item can have on the project.  

The probability and consequence of each risk item will be grated 1 to 5, where 1 is unlikely or low consequence, and 5 is very likely or a high consequence.  

The risk score will be used to prioritize the risk items, and to determine which risks need a mitigation strategy, and a contingency plan.  

\begin{figure}[h]
    \centering
    \includegraphics[width=0.5\textwidth]{docs/diagrams/out/technical analysis/risk-matrix.png}
    \caption{Risk matrix, showing the risk score based on probability and consequence \cite{haspod-2024} .}
    \label{fig:risk-matrix}
\end{figure}

Generally, the following actions will be taken based on the risk score:   

- **Low (1-9):** No immediate actions are taken.  
- **Medium (10-17):** A mitigation strategy is developed, in order to prevent the risk.  
- **High (18-25):** A mitigation strategy, as well as a contingency plan is developed. This way, there's a plan in place if the risk should occur.  

## Technical Risks
\refstepcounter{risk}\label{risk:tech-learning-curve}
**Risk ID:** \therisk\
**Description:** Technological learning curve.  
The project is based on knowledge and technological skills the team will get during the semester. The learning curve might not be as expected, resulting in a potential lack of important knowledge.  
**Probability:** 3  
Due to the limited time frame and other academic deadlines [\ref{risk:academic-deadlines}], team members might be otherwise occupied, and therefore not gain required knowledge as expected. Furthermore, other academic deadlines can cause team members to prioritize mandatory assignments, which can affect the quality of the knowledge gained, as well as steepen the learning curve.  
The team consists of eight people, which all contribute to the project. Not all team members need to know everything. The collective knowledge of the team can affect the project. The probability that no team member acquired the necessary knowledge, or have time to research the subject is low however.   
**Consequence:**  4  
Lack of knowledge can cause severe delays, since time will then be used to gain the knowledge required to accomplish a task.  
The quality of the final product can be affected as well.  
**Risk Score:**  12  
**Mitigation Strategy:**  Lack of time due to academic deadlines [\ref{risk:academic-deadlines}] cannot be prevented. However, the team can minimize the issue by different project management strategies, allowing a small group of team members to research subjects. The best way to prevent the issue is to treat research as tasks to do for the project. This is implemented on the project board on GitHub. <!-- Omformuler og/eller henvis til metode og proces afsnit -->  

\refstepcounter{risk}\label{risk:sw-skills}
**Risk ID:** \therisk\
**Description:** Software challenges in difficult parts of the project.  
Concepts such as pathfinding, deadreckoning, and PID regulation are new to the team.  
**Probability:**  5  
There is a high probability that the team encounters challenges in the development process, especially for these three aspects of the project.  
**Consequence:**  5
If one of these parts of the project are unfinished at the end of the project, the final product will have major flaws, and it will greatly impact the acceptance test for the project. The final product might end up unfinished as a direct result of this.  
**Risk Score:**  25  
**Mitigation Strategy:** The issue cannot be prevented, but it is possible to prevent the timeline for the project to be critically affected. Extra time can be allocated to research and development of these important and challenging parts of the project. The project board on GitHub contain all tasks for the project. The scrum master [ see roles in collaboration agreement ] should be aware of this risk, and allocate time accordingly, as well as delegate tasks to team members with relevant knowledge.  
**Contingency Plan:** If the timeline is affected despite of the mitigation strategy, the team needs to prioritize the remaining tasks in the project. Furthermore, team members not working on these areas can provide support by handling less time consuming tasks.   

\refstepcounter{risk}\label{risk:integrate-components}
**Risk ID:** \therisk\
**Description:** Integration challenges between components.   
This risk applies to both hardware and software components. The project will likely be split into smaller, more manageable parts, and assigned as tasks to members of the team during the project.  
**Probability:**  5  
Integration challenges are very common, especially considering that different team members will be in charge of different components.  
**Consequence:**  2  
Usually these kinds of challenges are fixed at some point, though it can be a time consuming process.  
**Risk Score:**  10  
**Mitigation Strategy:** Enough time needs to be allocated to integrating submodules. Proper project management is important.  

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
**Consequence:**  5  
The ability to meet the requirements for the project can be affected if components are not chosen carefully.    
**Risk Score:**  5  

\refstepcounter{risk}\label{risk:vc-break}
**Risk ID:**  \therisk\
**Description:** Version control breakdown.   
**Probability:**  4  
The team have some knowledge of version control through a course on a previous semester. The experience with using it for projects on a larger scale varies amongst the team members.  
**Consequence:**  4  
The risk of a complete breakdown of the version control is improbable. A server breakdown is unlikely, but can happen, in which case there is a risk of a few commits being lost. Recovering lost commits can be time consuming. A bigger risk is the teams limited experience with using version control on a project shared with other team members. Building routines, protecting the work, etc. can be time consuming in the beginning of the project, but will improve as the project moves forward.  
**Risk Score:**  16   
**Mitigation Strategy:** One of the roles mentioned in the collaboration agreement is a GitMaster. This team member is responsible for proper use of version control for the project. This includes making sure that all team members are using version control properly, and that the work is protected. Furthermore, the GitMaster should help team members with any issues regarding version control.   
**Contingency Plan:** If the strategies for version control fails, the team needs to be prepared to spend time recovering any lost work, as well as implementing relevant strategies to prevent it from happening again.  

\refstepcounter{risk}\label{risk:ph}
**Risk ID:**  \therisk\
**Description:** Lack of knowledge or skills necessary to assemble the frame for the vehicle.
**Probability:** 4   
Designing and assembling the frame of the car is not within the scope of the education. Any knowledge and experience required should be sought through external sources.  
**Consequence:** 2  
If a frame is not properly designed and assembled, the final product will still be a prototype and a proof of concept. Even though it might not meet the teams level of ambition, the project can still be a success.   
**Risk Score:** 8   

## Team and Resources
\refstepcounter{risk}\label{risk:internal-conflicts}
**Risk ID:** \therisk\
**Description:**  Internal conflicts.  
**Probability:**  4  
Since the team consists of eight people, all dedicated to the project, the probability of conflicts are quite high. Furthermore, personal conflicts can occur, which will have the same consequence as professional conflicts.  
**Consequence:**  5  
Any time spend on conflicts will result in less time for working on the project. The timeline can be greatly impacted by this, which can interfere with the quality of the final product. 
Furthermore, personal conflicts can create a bad work environment. Motivation and ambition level can drop amongst the team members, which can cause work to be slower and of less quality.  
**Risk Score:**  20  
**Mitigation Strategy:**  Conflicts can be prevented by proper and clear communication, to avoid any misunderstandings.  
The team made a collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->] adressing the issue.    
**Contingency Plan:**  All team members have an assigned role, which they are responsible for. One role is Internal HR. If conflicts occour, and cannot be solved by the involved parties, the Internal HR is tasked with solving the conflict, or seek help from external sources. More details in the collaboration agreement. <!-- Indsæt reference til bilag: Samarbejdskontract -->  

\refstepcounter{risk}\label{risk:team-availability}
**Risk ID:**  \therisk\
**Description:**  Availability of team members.  
Members of rhe team can be unavailable due to illness, personal and private circumstances, etc. The academic deadlines [\ref{risk:academic-deadlines}] can cause unavailability as well, especially since members of the team are working in different groups across courses.  
**Probability:** 3   
It is likely that availability will vary throughout the semester. However, the probability that all team members are unavailable at the same time is low.  
**Consequence:**  3
Unavailable team members can cause delays, and a bigger workload for the remaining team members. However, if proper communication is maintained, the impact can be minimized.  
**Risk Score:** 9   

\refstepcounter{risk}\label{risk:drop}
**Risk ID:** \therisk\
**Description:** Complete or partial loss of team members.  
Members of the team can get severely ill, or drop out completely.  
**Probability:** 1   
Complete loss of team members is not likely, especially considering that this is a 3. semester project. However, there is a risk that a team member can get severely ill, resulting in a lot of sick days, or even partial leave.   
**Consequence:**  5  
If a team member is suddenly on part time, or drops out completely, the team needs to compensate for the lost member. The work this member could have contributed are missing, and the rest of the team is required to contribute extra to the project in order to reach the goals set in the beginning of the project.  
**Risk Score:** 5   

\refstepcounter{risk}\label{risk:skill-gap}
**Risk ID:** \therisk\
**Description:** Skill gap amongst team members, as well as in comparison to the ambition levels.  
If the collective knowledge in the team is insufficient to reach the goal set, and meet the level of ambition agreed upon in the collaboration agreement [], a skill gap occurs.   
**Probability:** 2  
Since the concept of the project was developed in the beginning of the semester, the basic idea of the project was made before the team had any experience with some of the concepts involved in the project. <!--ref til Rx pathfinding -->  
**Consequence:**  3
If the collective knowledge is insufficient, the quality of the final product can be affected. The timeline can be affected as well, since time will be used to research subjects necessary to gain the knowledge required. However, if there is a skill gap between the team and the ambition level, the goals can be adjusted.  
**Risk Score:** 6  

\refstepcounter{risk}\label{risk:work-ethics}
**Risk ID:**  \therisk\
**Description:** Work ethics.  
The members of the team can have different work ethics and level of ambition. The collective level of ambition was discussed and agreed upon in the collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->].   
**Probability:** 3  
A completely uniform level of ambition and work ethics is not likely. However, the team is in close communication, and the collaboration agreement should help minimize the issue.  
**Consequence:** 4 
The consequence depends on the severity of the issue. If the team developes a tendency to push the timeline for the project, or procrastinate important tasks, the quality of the final product can be affected. Furthermore, the timeline can be affected as well.  
**Risk Score:** 12   
**Mitigation Strategy:** The team needs to maintain proper communication, and adress the issue if it should occur. The collaboration agreement [<!-- Indsæt reference til bilag: Samarbejdskontract -->] adresses the issue, and all team members have signed it. Furthermore, the role of Internal HR is assigned to a team member, who is responsible for handling such issues.   

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
**Risk ID:**  \therisk\
**Description:** Dependency delays.  
Delays can occur if a team member is waiting for another team member to finish a task, before they can start their own task.  
**Probability:**  
Some dependency delays are likely to happen, however, the probability of severe delays is low.  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:scope}
**Risk ID:**  \therisk\
**Description:** Initial scope of the project might not match a realistic time frame.  
**Probability:**  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

## External Risks
\refstepcounter{risk}\label{risk:academic-deadlines}
**Risk ID:**  \therisk\
**Description:**  Academic Deadlines.  
Deadlines and assignments in other courses can affect the availability of team members.  
**Probability:**  4  
Deacline conflicts are very likely to happen. The semester is a bit more heavy on deadlines and assignments than the previous semesters, and team members are required to adjust to this.  
**Consequence:**  4  
If multiple deadlines happen close to each other, the team members will be otherwise occupied, resulting in less work on the project. The amount of hours that each team member can contribute per week might vary. An average hours per week estimate was made in the collaboration agreement. <!--bilag -->  
**Risk Score:**  16  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:ext-availability}
**Risk ID:**  \therisk\
**Description:** Availability of supervisor and other external helpers.  
**Probability:**  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:scrum-experience}
**Risk ID:**  \therisk\
**Description:** SCRUM experience.  
The experience with using SCRUM as a model for project management is limited amongst the team. 
**Probability:**  2
It is very likely that unnecessary time are being spent on learning the SCRUM model, and the process of sprints. However, the process will be repeated several times during the project.  Therefore, the team will likely build routines, which can gradually decrease the time spent on project management.  
**Consequence:**  3
Planning of sprints and task delegation can take up more time than necessary, since members of the team lack experience with the model.  
**Risk Score:**  6   
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:time-management}
**Risk ID:**  \therisk\
**Description:** Time management.  
As mentioned in other risk items, the team will encounter several unfamiliar challenges during the project. 
**Probability:**  4  
There is a high probability of encountering new or unexpected tasks and challenges during the project, which can take up a lot of time. Time that could have been spent on development.  
**Consequence:**  5  
If the team is unable to effectively manage the available time, it will impact the project, and can affect the quality of the final product, as well as impair the teams ability to meet important deadlines.  
**Risk Score:**  20  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:external-conflicts}
**Risk ID:**  \therisk\
**Description:** External conflicts.  
This includes conflicting schedules and resources, which   
**Probability:**  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:finance}
**Risk ID:**  \therisk\
**Description:** Financial challenges.  
**Probability:**  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

\refstepcounter{risk}\label{risk:ph}
**Risk ID:**  \therisk\
**Description:**  
**Probability:**  
**Consequence:**  
**Risk Score:**  
**Mitigation Strategy:**  
**Contingency Plan:**

\newpage