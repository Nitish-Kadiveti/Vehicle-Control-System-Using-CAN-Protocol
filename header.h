#include <LPC21xx.H>
#include<string.h>
//#define sw1 ((IOPIN0>>14)&1)
//#define sw2 ((IOPIN0>>15)&1)


extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);

extern void lcd_cmd(unsigned char);
extern void lcd_data(unsigned char);
extern void lcd_init(void);

extern void lcd_string(char *);

extern void lcd_int(int);
extern void lcd_float(double);
extern void lcd_cgram(char *);

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short int u16;

extern void uart0_init(u32);
extern void uart0_tx(u8); 
extern u8 uart0_rx(void);
extern void uart0_tx_string(s8 *);
extern  void uart0_tx_integer(s32 );

extern void adc_init(void);
extern int adc_read(u8);


extern void en_uart0_interrupt(void);
extern void config_vic_for_uart0(void);
extern void uart0_Handler(void) __irq;


typedef struct CAN_MSG
{
 u32 id;
 u32 byteA;
 u32 byteB;
 u8 dlc;
 u8 rtr;
 }CAN2;


extern void can2_init(void);
extern void can2_tx(CAN2);
extern void can2_rx(CAN2 *ptr);





