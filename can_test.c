#include<lpc21xx.h>
#include"header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
CAN2 V1,V2,V3;
unsigned int flag,HL,LI,RI;

main()
{
 can2_init();
 uart0_init(9600);
 //lcd_init();


 V1.id=0x200;
 V1.rtr=0;
 V1.dlc=8;
 V1.byteA=0x00000011;
 V1.byteB=0x00000012;
  
 V2.id=0x201;
 V2.rtr=0;
 V2.dlc=8;
 V2.byteA=0x00000011;
 V2.byteB=0x00000012;


 V3.id=0x202;
 V3.rtr=0;
 V3.dlc=8;
 V3.byteA=0x00000011;
 V3.byteB=0x00000012;

 
 uart0_tx_string("nodeA\r\n");
 while(1)
 {

 //HEADLIGHT//
  if(sw1==0)
  {
  while(sw1==0);
   HL=~HL;
   uart0_tx_string("Headlight is ON\n\r");
   can2_tx(V1);
  }

  //LEFT INDICATOR//
  if(sw2==0)
  {
  while(sw2==0);
 
  LI=~LI;
  uart0_tx_string("LEFT INDICATOR IS ON\n\r");
  can2_tx(V2);
  }
  flag=0;		   

  //RIGHT INDICATOR//
  if(sw3==0)
  {
   LI=0;
  while(sw3==0);
  
  RI=~RI;
  uart0_tx_string("RIGHT INDICATOR IS ON\n\r");
  can2_tx(V3);	  
  }
  flag=0;

}
}
