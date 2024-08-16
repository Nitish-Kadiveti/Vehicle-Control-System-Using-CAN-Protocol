#include<lpc21xx.h>
#include "header.h"
unsigned char temp;
extern u32 flag;
unsigned int tx_cnt,rx_cnt;

void uart0_Handler(void) __irq
{

//flag=0;

int r=U0IIR;
flag=0;
//u8 dummy;

if(((r>>1)&7)==2)
   {
  temp=U0RBR;
   flag=1;
   rx_cnt++;
   }

   if(((r>>1)&7)==1)
   tx_cnt++;

VICVectAddr=0;
}


void config_vic_for_uart0(void)
{
  VICIntSelect=0;
  VICVectCntl0=6|(1<<5);
  VICVectAddr0=(unsigned int)uart0_Handler;
  VICIntEnable|=(1<<6);  
}

void en_uart0_interrupt(void)
{
	U0IER=3;
	//U0IER=1;
} 




















