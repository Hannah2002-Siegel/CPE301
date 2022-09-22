CPE 301 Final Project -- Swamp Cooler

Overview:
  In this team project we constructed a fan mechanism which used two arduino megas, a motor, fan, water sensor, and temperature and humidity sensor to detect, record, and display the temperature and humidity and control the fan depending on this recorded data. If the temperature and humidity was too high the system moved into a state, signified by an led turning on, and the fan would turn on and begin blowing. If the temperature or humidity was below a threshold amount the system would move into an idle state, again signified by a new led turning on and the previous truning off, where the fan turned off and the temperature and humidity displayed on the lcd changes to reflect the present meaurements. For every state in the console a real time clock can be viewed to keep regard of the real time running of the system as a whole. 
  
Problems/Bugs:
  There is an issue with the dispribution of current when the system is running for an extended duration of time. After several minutes of high temperature and humidity along with a high water level detected by the water sensor, the system begins to overheat and the system is unable to handle the increasingly exorbident amount of voltage and current being demanded by the system. Another noted issue in system design is that after hours of operation the real time clock display begins to stray from the actual time by an increasingly factor of error. After approximately 3 hours of run time the displayed real time will be around an hour and a half off from reality. This issue can be explained by our decision to use the arduino clock module which acts as a physical clock on the system. This issue would proabably be most easily resolved if we just pull the clock data from the clock on the computer, but we opted for a physical impimentation of a real time clock module. 

Lab 5

Lab 6

Lab 7

EE120 Final Project
