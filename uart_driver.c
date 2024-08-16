///uart0_driver///
#include<lpc21xx.h>
#include "header.h"
void uart0_init(u32 baud) //unsigned 32bit
{
u32 result=0;
int a[]={15,60,30,0,15};
unsigned int pclk=0;  //or u32 pclk=0;
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud); //calculate U0DLL
PINSEL0|=5;
U0LCR=0X83; //8-> setting DLAB(7th bit=1)  3-> setting WORD LENGTH and STOP BIT ( 1 1 )
U0DLL=result&0xff;       //LSB of DLL stored in LSB
U0DLM=(result>>8)&0xff;    //MSB of DLL shifted to MSB and stored
U0LCR^=(1<<7); ///shifted to DLAB 
}
#define THRE ((U0LSR>>5)&1)   
void uart0_tx(u8 data)
{
U0THR=data;
while(THRE==0);
}

void uart0_tx_string(s8 *ptr)
{
while(*ptr)
{
U0THR=*ptr;
while(THRE==0);
ptr++;
}
}

#define RDR (U0LSR&1)
u8 uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}

void uart0_rx_string(s8 *ptr,u8 len)
{
    u8 i;
    for(i=0;i<len;i++)
    {
        while(RDR==0);
        ptr[i]=U0RBR;
        if(ptr[i]=='\r')
        break;
    }
    ptr[i]='\0';
}

/*void uart0_tx_integer(s32 num)
{
    char buf[15];
    sprintf(buf,"%d",num);
    uart0_tx_string(buf);
}

void uart0_tx_float(s32 num)
{
    char buf[15];
    sprintf(buf,"%f",num);
    uart0_tx_string(buf);
}

*/
