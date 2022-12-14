 // Authors: Hannah, Huy, Cameron, Kenneth
 // Date: Feb 28th, 2022
 // Section: 301.1104
 // Lab: 6
 #define RDA 0x80
 #define TBE 0x20  
 volatile unsigned char *myUCSR0A = (unsigned char *)0x00C0;
 volatile unsigned char *myUCSR0B = (unsigned char *)0x00C1;
 volatile unsigned char *myUCSR0C = (unsigned char *)0x00C2;
 volatile unsigned int  *myUBRR0  = (unsigned int *) 0x00C4;
 volatile unsigned char *myUDR0   = (unsigned char *)0x00C6;
//
// main()
//
void setup()
{
 // initialize the serial port on USART0:
 U0init(9600);
}
void loop()
{
  unsigned char cs1;
  unsigned char convert;
  unsigned char mod_convert;
  
  while (U0kbhit()==0){}; // wait for RDA = true
  cs1 = U0getchar();    // read character
  
  int check1 = (cs1 / 16);
  int check2 = (cs1 % 16);
  
//Conversions to Hex
  if(check1>9)
  convert = (check1 + ('A' - 10));
  else
  convert = (check1 + '0');

  if(check2>9)
  mod_convert = (check2 + ('A' - 10));
  else
  mod_convert = (check2 + '0');

//Prints to screen  
  U0putchar('0');     //0
  U0putchar('x');     //0x
  
  U0putchar(convert);     // 0x<1>
  U0putchar(mod_convert);     // 0x<1><2>
  
  U0putchar('\n');     // \n <--- Prints 0x0A  
}

//
// function to initialize USART0 to "int" Baud, 8 data bits,
// no parity, and one stop bit. Assume FCPU = 16MHz.
//
void U0init(unsigned long U0baud)
{
//  Students are responsible for understanding
//  this initialization code for the ATmega2560 USART0
//  and will be expected to be able to intialize
//  the USART in differrent modes.
//
 unsigned long FCPU = 16000000;
 unsigned int tbaud;
 tbaud = (FCPU / 16 / U0baud - 1);
 // Same as (FCPU / (16 * U0baud)) - 1;
 *myUCSR0A = 0x20;
 *myUCSR0B = 0x18;
 *myUCSR0C = 0x06;
 *myUBRR0  = tbaud;
}
//
// Read USART0 RDA status bit and return non-zero true if set
//
unsigned char U0kbhit()
{
  return (RDA & *myUCSR0A);
}
//
// Read input character from USART0 input buffer
//
unsigned char U0getchar()
{
  return *myUDR0;
}
//
// Wait for USART0 TBE to be set then write character to
// transmit buffer
//
void U0putchar(unsigned char U0pdata)
{
  while(!(TBE & *myUCSR0A));
  *myUDR0 = U0pdata;
}
