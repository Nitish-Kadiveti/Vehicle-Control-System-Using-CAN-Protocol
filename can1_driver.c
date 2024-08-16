#include<lpc21xx.h>
#include "header.h"
u32 *ptr=(u32*)0xE0038000;
#define TCS ((C2GSR>>3)&1)
#define RBS (C2GSR&1)

void can2_init(void)
{
   PINSEL1|=0x00014000;
   VPBDIV=1; //pclk=60mhz
   C2MOD=1;		//select reset mode
   C2BTR=0x001C001D;  //1252kbps baudrate
   AFMR=2;	  //accept all incoming msgs
   C2MOD=0;	  //ancel reset mode
}

void can2_tx(CAN2 V)
{
   C2TFI1=(V.dlc<<16);  //set dlc & set rtr value
   C2TID1=V.id;
   if(V.rtr==0)
 	{
 	 C2TDA1=V.byteA;
 	 C2TDB1=V.byteB;
 	}

else //if remote frame
	{
 	 C2TFI1=(1<<30); //rtr=1
 	}
 	 C2CMR=1|(1<<5);//start xmission &select txbuf
 	 while(TCS==0);	//monitor flag
    }

void can2_rx(CAN2 *ptr)
{
	while(RBS==0);
	ptr->id=C2RID;
	ptr->dlc=(C2RFS>>16)&0x0F;
	ptr->rtr=(C2RFS>>30)&1;

	if(ptr->rtr==0)	 //if dataframe
	{
	ptr->byteA=C2RDA;
	ptr->byteB=C2RDB;
	}
	C2CMR=(1<<2);//release RX buf
}

