#include<lpc21xx.h>
void delay_sec(unsigned int sec)
{
int a[]={15,60,30,15,15};
unsigned int pclk;
pclk=a[VPBDIV]*1000000*-1;
T0PC=0;
T0PR=pclk;
T0TC=0;
T0TCR=1;
while(T0TC<sec);
T0TCR=0;
}
void delay_ms(unsigned int ms)
{
int a[]={15,60,30,15,15};
unsigned int pclk;
pclk=a[VPBDIV]*1000-1;
T0PC=0;
T0PR=pclk;
T0TC=0;
T0TCR=1;
while(T0TC<ms);
T0TCR=0;
}
