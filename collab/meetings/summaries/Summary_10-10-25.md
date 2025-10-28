Referat

Længere projekt formulering, forklaring af problemet
rigt billede
forside til hvert bilag
indholdsfortegnelse


funktionelle krav:
goal og post er det samme
hvad venter 5 sekunder, specificer
overvej om ting skal slås sammen

Teknisk analyse:
hvad har vi valgt, hvor står det
sætte pris på ting hvor vi nævner det

Non functionel:
få styr på størrelsen af produktet

Risks:
R1 passer bedre under Team og Resources, da det vedrører jeres egne evner og ikke teknologien.
R20 er overflødig, da den er dækket af andre punkter bl.a. R14, R18 og R19.
overskrifter, indents


use case 3:
Hvilken knap, præsisere det hele




Deres noter:

Project Formulation
-	Hvor er den?
-	Der mangler en skitse over jeres ide. Vi savner det rige billede :(
-	Jeres introduktion er meget god, men jeres problemformulering er ikke koblet så godt sammen med introen. Lidt random at have en løsning med en bil på et rigtigt aktuelt problem. Her kunne en forklaring på hvorfor jeres løsning er den umiddelbart “bedste” løsning hjælpe med at gøre det relevant, og noget om hvordan bilen vil kunne nedsætte menneskelige fejl med at give korrekt medicin, og om den virkelig vil kunne nedsætte arbejdsmængden for personalet. 
-	Jeres projekt formulering burde være meget længere, 2 sider.
-	Efter at have læst jeres use case, lyder det til at fokuseret er på selve bilen, og at den skal kunne finde rundt. Ikke noget med hvilken medicin der skal med. Så er det lidt forvirrende, at jeres intro handler om en sygeplejerske der har brug for hjælp med at strukturere medicinudlevering. Det lyder ikke til, at bilen og systemet skal kunne hjælpe med det. Medmindre at serveren skal kunne finde den rigtige medicin ud fra hvilke rum der vælges? Det er bare ikke så beskrevet.
-	Overall super fed ide, kommer til at blive crazy.
Kunne generelt være en god ide at indføre en versionshistorik i jeres dokumenter. Og forside
01 - Functional Requirements
Hav noget mere forklarende tekst om hvad der skrives om. Fx er det forvirrende, at I starter direkte med korte forklaringer af hver use case, og så kommer der et tomt use case diagram?? Og til sidst har I åbenbart alligevel fully dressed use cases.
Er jeres korte beskrivelser af use cases i starten jeres egne noter?? I skriver ikke med store bogstaver.

Ville være bedre med mere forklaring. 😊 
Prøv at undgå afhængigheder imellem usecases. F.eks er usecase 3 afhængig af use case 2, samt er usecase 2 også afhængig af usecase 1 og 5.
 
"lots of expections?” - hvad referer det til?
Hvad hvis jeg nu går ind i bilen og sætter af kurs, hvad sker der så?
-	Aktør kontext diagram?
-	Use case diagram?

Generelt for fully dressed Use Cases:
Goal og postcondition siger præcist det samme bare med mere tekst i postcondition. 

Use case 1:
-	Det kan være lidt forvirrene hvorfor der er to punkt 1 så det kan være en ide at sætte dem sammen
-	Exception 1 hedder to forskellige ting ‘No power on battery’ og ‘No battery power’
-	Exception 2 og 3 gør det samme når der går noget galt så hvordan ved man hvilken exception den blinker for. 
-	Når den røde LED både skal være den der viser at bilen er tændt og exception hvordan ved i så om det er fordi bilen ikke er tændt eller en exception.
Use case 2:
-	Være mere klar omkring UI elementer og 
-	“7. Confirm and deny options appear,” hvor henne😊 
-	“18. Wait 5 seconds”, hvem eller hvad venter 5 sekunder. Er det user, bilen eller ui? 	
-	“6. A confirmation message saying "This is your chosen rooms" and a list of the rooms chosen appears” hvor appear de henne 😶? 
-	Nogle af punkterne med serveren er for detaljerede. Det er for teknisk hvad der skal ske på serveren. I skal fokusere mere på handlingerne. Måske punkter kan slås sammen. (Fx. UC2 og punkt 9 og 10).
Use case 3:
-	Exeption 1 er at pathfinding  ikke er gjort men postcondition for use case 2 er at det virker såååå?? Burde den ikke høre til i use case 2? Eller gør det til en precondition
-	Step 10 – hvilken knap bliver trykket?
Use case 4:
-	Navnet på use casen skal være en handling i bydeform. Så her kunne det være Shutdown car, ikke “of car”. 
Use case 5: mangler
Hvor er Moscow?
Generelt, overvej at slå nogle punkter sammen. Nogle af scenarierne er crazy lange
01 - Technical analysis
-	Kunne være rart hvis forklaringerne var med i tabellen for bedre overblik, så man kan se hvilke kandidater der er bedst på hvilke parametre og hvorfor, sammen. Hvilken har flest point samlet? Evt. Kan I ellers sætte punkterne op i punktform.
-	Gør det tydeligere hvilke kandidater der bliver valgt. Lige nu står jeres “konklusioner” under afsnittet om Developer cost.
-	Ved ikke om I bare ikke er færdige, men der skal være analyse af forskellige hardware komponenter som I vil vælge til bilen. Fx motor og LED’er mm.
-	For Price kunne I have nogle konkrete prduktforslag med en pris. “Pretty cheap”, “Significant cost”. Det er svært at få en fornemmelse af, hvad I sammenligner. Er det 50 kr eller 500 kr?
02 - Nonfunctional Requirements
Det ligner I tager udgangspunkt i FURPS. Hvor har I de andre punkter fra?
1.	Functionalitet:
a.	I skal være mere nøjagtige med størrelsen af bilen, lige nu står det bare rectangular box. 
2.	Usability:
a.	Systemet? Hvad indebærer der i systemet? Er det bilen og serveren.
b.	Cool Documentation.
c.	Jeres metrics, har lidt nogle syge tider. 
3.	Reliability:
a.	“1. The car must be operable for at least 1 hour of continuous driving without restart.”
i.	Kan være lidt bange for at det er meget højt sat, da i hverken har sat en variabel for hvor meget bilen skal kunne løfte. Da det kan have en effekt på batteriet.
4.	Performance:
a.	Variabler burde have værdier, men er måske en smule svært at finde ud af når i ikke har lavet en teknisk analyse af jeres komponenter.
5.	Safety and security:
a.	“The system must lock out for 1 minute after 3 failed code attempts.” Den kunne eventuelt være exponentiel.	
6.	Supportability:
a.	“The server software must be designed so new modules (e.g., path optimization, object detection) can be added without major rewrites.” huh ?
7.	Scalability:
a.	“The might integrate with external IT systems.” huh?
8.	Constraints:
9.	Compliance:
a.	Bare slet det her, hvordan kommer i til at teste det her?
Hvor er Moscow?
02 - Risk analysis
Overall goated. I burde måske genoverveje nogle af de risici der er, såsom SCRUM experience.
R1 passer bedre under Team og Resources, da det vedrører jeres egne evner og ikke teknologien.
R20 er overflødig, da den er dækket af andre punkter bl.a. R14, R18 og R19.
Måske brug overskrifter for hver R og hav mere rum mellem afsnit, og brug indents. Det ligner lidt en stor blok tekst lige nu, selvom det ikke er det.
Overvej om nogle punkter kan slås sammen. Der er MANGE. Fx kan R13, R15 og R17 måske slås sammen. De vedrører noget af det samme.
Acceptence test specification
Jeres overskrifter er vildt forvirrende. I er vist ikke færdige med dette dokument.
Mangler ikke-funktionelle krav
Use case 1:
-	
Use case 2:
-	Den er der 8 gange i dokumentet 
Use case 3:
-	Den har en titel men den har en ikke en accepttest ved sig. Den under er use case 2
Use case 4:
-	Under titlen for use cases er det use case 2 der står der

