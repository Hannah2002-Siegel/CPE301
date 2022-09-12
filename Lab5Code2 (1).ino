volatile unsigned char in_char;
volatile unsigned char *myTCCR1A = (unsigned char *) 0x80;
volatile unsigned char *myTCCR1B = (unsigned char *) 0x81;
volatile unsigned char *myTCCR1C = (unsigned char *) 0x82;
volatile unsigned char *myTIMSK1 = (unsigned char *) 0x6F;
volatile unsigned int  *myTCNT1  = (unsigned  int *) 0x84;
volatile unsigned char *myTIFR1 =  (unsigned char *) 0x36;
volatile unsigned char *portDDRB = (unsigned char *) 0x24;
volatile unsigned char *portB =    (unsigned char *) 0x25;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

 *myTCCR1A = 0x00;
 *myTCCR1B = 0x00;
 *myTCCR1C = 0x00;
 *portDDRB |= 0x40;
 *portB &= 0xBF;
 
}

void myDelay(unsigned int ticks) {
  *myTCCR1B &= 0xF8;
  *myTCNT1 = (unsigned int) (65536 - ticks);
  *myTCCR1B |= 0b00000001;
  while((*myTIFR1 & 0x01) == 0);
  *myTCCR1B &= 0xF8;
  *myTIFR1 |= 0x01;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    in_char = Serial.read();
    Serial.write(in_char);
  }
  if (in_char == 'a') 
  {
    *portB |= 0x40;
    myDelay(18182);
    *portB &= 0xBF;
    myDelay(18182);
    
  } else if (in_char == 'b') 
  {
    *portB |= 0x40;
    myDelay(16195);
    *portB &= 0xBF;
    myDelay(16195);
    
  } else  if (in_char == 'c') 
  {
    *portB |= 0x40;
    myDelay(15197);
    *portB &= 0xBF;
    myDelay(15197);
    
  } else  if (in_char == 'd') 
  {
    *portB |= 0x40;
    myDelay(13629);
    *portB &= 0xBF;
    myDelay(13629);
    
  } else  if (in_char == 'e') 
  {
    *portB |= 0x40;
    myDelay(12140);
    *portB &= 0xBF;
    myDelay(12140);
    
  } else  if (in_char == 'f') 
  {
    *portB |= 0x40;
    myDelay(11462);
    *portB &= 0xBF;
    myDelay(11462);
    
  } else  if (in_char == 'g') 
  {
    *portB |= 0x40;
    myDelay(10204);
    *portB &= 0xBF;
    myDelay(10204);
  } else {
    *portB &= 0xBF;
  }
  
}
