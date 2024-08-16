#include<lpc21xx.c>
#include "header.h"
extern u32 flag;
extern CAN V1;

void CAN2_Rx_Handler(void) __irq
{
	V1.id=C2RID;
	V1.dlc=(C2RFS>>16)&0x07;
	V1.rtr=(C2RFS>>30)&1;
	if(V1.rtr==0){
		V1.byteA=C2RDA;//first data byte
		V1.byteB=C2RDB;
	}
	C2CMR=(1<<2);
	flag=1;
	VICVectAddr=0;
}

void config_vic_for_can2(void)
{
	VICIntSelect=0;
	VICVectCntl2=26|(1<<5);
	VICVectAddr12=(u32)CAN2_Rx_Handler;
	VICIntEnable|=(1<<26);
}

void en_can2_interuppt(void)
{
	C2IER=1;
}