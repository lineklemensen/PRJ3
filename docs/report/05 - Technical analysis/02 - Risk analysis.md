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
\includegraphics[width=0.7\textwidth]{C:/Users/danie/Desktop/PRJ3/docs/diagrams/out/technical analysis/risk-matrix.png}
\caption{Risk matrix, showing the risk score based on probability and consequence}
\end{center}
\end{figure}

Image source from Haspod.com [@haspod2024].

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
    R1 & Technological learning curve & 3 & 3 & 9  \\
    \hline
    R2 & Software challenges in difficult parts of the project & 4 & 5 & 20 \\
    \hline
    R3 & Integration challenges between components & 3 & 2 & 6 \\
    \hline
    R4 & Hardware failures & 3 & 3 & 9 \\
    \hline
    R5 & Lack of knowledge to choose proper components & 1 & 3 & 3 \\
    \hline
    R6 & Version control breakdown & 3 & 3 & 9 \\
    \hline
    R7 & Lack of knowledge or skills necessary to assemble the frame for the vehicle & 4 & 2 & 8 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{Team and Resources}} \\
    \hline
    \textbf{Risk ID} & \textbf{Description} & \textbf{Prob.} & \textbf{Cons.} & \textbf{Score} \\
    \hline
    R8 & Internal conflicts & 2 & 5 & 10 \\
    \hline
    R9 & Availability of team members & 3 & 3 & 9 \\
    \hline
    R10 & Complete or partial loss of team members & 1 & 5 & 5 \\
    \hline
    R11 & Skill gap amongst team members, as well as in comparison to the ambition levels & 2 & 3 & 6 \\
    \hline
    R12 & Work ethics & 3 & 4 & 12 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{Project Management}} \\
    \hline
    \textbf{Risk ID} & \textbf{Description} & \textbf{Prob.} & \textbf{Cons.} & \textbf{Score} \\
    \hline
    R13 & Requirement changes & 3 & 4 & 12 \\
    \hline
    R14 & Dependency delays & 4 & 4 & 16 \\
    \hline
    R15 & Initial scope of the project might not match a realistic time frame & 4 & 3 & 12 \\
    \hline
    R16 & SCRUM experience & 2 & 3 & 6 \\
    \hline
    R17 & Time management & 4 & 4 & 16 \\
    \hline
    \multicolumn{5}{|c|}{\textbf{External Risks}} \\
    \hline
    R18 & Academic Deadlines & 4 & 4 & 16 \\
    \hline
    R19 & Availability of supervisor and other external helpers & 3 & 5 & 15 \\
    \hline
    R20 & External conflicts & 2 & 4 & 8 \\
    \hline
    R21 & Financial issues & 2 & 5 & 10 \\
    \hline
\end{tabularx}

\newpage
## Technical Risks
R\label{risk:tech-learning-curve}
**Risk ID:** \therisk\
**Description:** Technological learning curve.  
The project is based on knowledge and technological skills the team will get during the semester. The learning curve might not be as expected, resulting in a potential lack of important knowledge.  
**Probability:** 3  
Due to the limited time frame and other academic deadlines [R], team members might be otherwise occupied, and therefore not gain required knowledge as expected. Furthermore, other academic deadlines can cause team members to prioritize mandatory assignments, which can affect the quality of the knowledge gained, as well as steepen the learning curve.  
The team consists of eight people, which all contribute to the project. Not all team members need to know everything. The collective knowledge of the team can affect the project. The probability that no team member acquired the necessary knowledge, or have time to research the subject is low however.   
**Consequence:** 3    
Lack of knowledge can cause severe delays, since time will then be used to gain the knowledge required to accomplish a task.  
The quality of the final product can be affected as well.  
**Risk Score:** 9  
**Mitigation Strategy:** Lack of time due to academic deadlines [R] cannot be prevented. However, the team can minimize the issue by different project management strategies, allowing a small group of team members to research subjects. The best way to prevent the issue is to treat research as tasks to do for the project. This is implemented on the project board on GitHub. <!-- Omformuler og/eller henvis til metode og proces afsnit -->  

R\label{risk:sw-skills}
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

R\label{risk:integrate-components}
**Risk ID:** \therisk\
**Description:** Integration challenges between components.   
This risk applies to both hardware and software components. The project will likely be split into smaller, more manageable parts, and assigned as tasks to members of the team during the project.  
**Probability:** 3    
Integration challenges are very common, especially considering that different team members will be in charge of different components.  
**Consequence:** 2  
Usually these kinds of challenges are fixed at some point, though it can be a time consuming process.  
**Risk Score:** 6   
**Mitigation Strategy:** Enough time needs to be allocated to integrating submodules. Proper project management is important.  

The full risk analysis can be found in the appendices.  

\newpage