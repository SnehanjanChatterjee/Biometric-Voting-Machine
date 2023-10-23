# Biometric-Voting-Machine

## Demo

https://github.com/SnehanjanChatterjee/Biometric-Voting-Machine/assets/41839617/32bc210b-4915-464b-9871-faf6bc616799

<p align="center">
      <img height="400" width="500" src="https://github.com/SnehanjanChatterjee/Biometric-Voting-Machine/blob/master/IMG_20180424_094026.jpg?raw=true" alt="Model"/>
</p>

Electronic Voting Machines (EVM) are being used  in Indian General and State Elections to implement electronic voting in part from 1989 elections and recently in 2017 state elections held in five states across India. EVMs have replaced paper ballots in local state and general (parliamentary) elections in India.
      Voting Machine consists of two units – a Control unit and a Balloting unit. The control unit is with the presiding officer or a polling officer and the balloting Unit is placed inside the voting compartment. The balloting unit presents the voter with blue buttons (momentary switch) horizontally labelled with corresponding party symbol and candidate names. The Control Unit on the other hand provides the officer in-charge with a "Ballot" marked button to proceed to the next voter, instead of issuing a ballot paper to them.But in our case,the machine serves the purpose of both Control Unit and a Balloting Unit. Presiding Officer would not have any control over the machine.

DISADVANTAGES  OF  COMMON  EVMs:

1. COMMON EVMs ARE VULNERABLE TO MALICIOUS PROGRAMMING.
2. COMMON EVMs DO NOT HAVE ANY MECHANISM BY WHICH THE VOTER CAN VERIFY THEIR IDENTITY BEFORE CASTING THE VOTE DUE TO WHICH FAKE VOTERS CAN CAST NUMEROUS FAKE VOTES.

AUTONOMOUS  BIOMETRIC VOTING MACHINE:

THIS VOTING MACHINE IS COMPLETELY INDEPENDENT AND HENCE THE PRESIDING OFFICER CANNOT BE FORCED IN ANY WAY.THIS WOULD PREVENT RIGGING(election rigging is the act of dishonestly organizing an election to get a particular result. it is an electoral fraud and an interference with the election process). 
VOTERS CAN SUBMIT THEIR VOTES AND BE REASONABLY CONFIDENT THAT THEIR VOTE WILL COUNT.A PARTICULAR VOTER CANNOT CAST HIS VOTE MULTIPLE TIMES AS THE SYSTEM DOES NOT PERMIT HIM TO DO SO.A PARTICULAR CANDIDATE CAN VOTE ONLY IF HE IS A REGISTERED VOTER AND ONLY IF HIS ADHAR NUMBER MATCHES WITH HIS FINGERPRINT OTHERWISE A REPORT WILL BE SENT TO THE PRESIDING OFFICER IN EACH CASE.
METHODOLOGY : 
1. A PARTICULAR CANDIDATE ENTERS HIS/HER 12 DIGIT ADHAAR NUMBER.
2. ONCE HE/SHE REGISTERS THE ADHAAR NUMBER , THEREAFTER HE/SHE NEEDS TO PLACE HIS/HER FINGER ON THE FINGERPRINT SCANNER.
3. IF THE FINGERPRINT MATCHES WITH THE CORRESPONDING ADHAAR NUMBER , THE FLAP OPENS.
4. THE VOTER CAN NOW CAST HIS VOTE!!
5. IF VOTING IS DONE MULTIPLE TIMES BY THE SAME CANDIDATE , THEN A REPORT WILL BE SENT TO THE PRESIDING OFFICER IN CHARGE AND THESE MULTIPLE VOTES WILL NOT BE REGISTERED(SINGLE CANDIDATE CAN CAST A SINGLE VOTE).
6. IF THE FINGERPRINT DOES NOT MATCH WITH THE CORRESPONDING ADHAAR NUMBER , THEN ALSO A REPORT WILL BE SENT TO THE PRESIDING OFFICER.

## BLOCK DIAGRAM
<p align="center">
  <img src="https://github.com/SnehanjanChatterjee/Biometric-Voting-Machine/blob/master/Block%20Diagram.png?raw=true" alt="Block Diagram"/>
</p>

## CIRCUIT DIAGRAM
<p align="center">
  <img src="https://github.com/SnehanjanChatterjee/Biometric-Voting-Machine/blob/master/Circuit%20Diagram.png?raw=true" alt="Circuit Diagram"/>
</p>

## TECHNOLOGY STACK

### HARDWARE USED :

1. ARDUINO UNO MICROCONTROLLER
2. I2C
3. 16X2 LCD DISPLAY
4. 4X4 MATRIX KEYPAD
5. SERVO MOTOR
6. FINGERPRINT SCANNER
7. BREADBOARD
8. JUMPER WIRES
9. RESISTORS
10. MOMENTARY PUSH BUTTON
11. POWER SOURCE(ADAPTOR)

### SOFTWARE USED :

1. ARDUINO COMPILER
2. FRITZING
3. LUCIDCHART
4. DRAW.IO
5. MS WORD
 
## SHOW STOPPERS

1. In practical applications Aadhaar information has to be fetched. This may lead to misplacement of confidential governmental information.
2. Improper handling of information may cause abrupt changes in the total vote count.
3. Chapter VI of the Aadhaar bill addresses the issue of privacy. It has the clauses that protect the biometric and personal data with the CIDR. However when public and private agencies collect and transmit personal information, including biometrics, it would always be possible for them to also retain a copy. Experience shows that such personal data quickly turn into a commodity, freely available for purchase.
