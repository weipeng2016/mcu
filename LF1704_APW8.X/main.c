// PIC16LF1704 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = SWDTEN    // Watchdog Timer Enable (WDT controlled by the SWDTEN bit in the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCDDIS = ON      // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


#include <pic.h> 
#include "main.h"
#include "FVR.h"
#include "ADC.h"
#include "DAC.h"
#include "OPA.h"
#include "IIC.h"
#include "TIMER.h"
#include "PWM.h"
// work with __delay_ms __delay_us
#define _XTAL_FREQ 16000000

#if 0
#include "uart.h"
//#include "Flash.h"
//#include "HEFlash.h"

// global err
#define GERR_UART_MAGIC	0x01
#define GERR_UART_HSIZE	0x02
int g_err = 0;

// array for master to write to, reserved
volatile unsigned char I2C_Array_Rx[RX_ELMNTS] = 0;
//unsigned char I2C_Array_Rx[RX_ELMNTS] = 0;	
#endif
//slave IIC variable
unsigned char index_i2c = 0;     // index pointer
unsigned char junk = 0;          // used to place unnecessary data
unsigned char first = 1;               // used to determine whether data address 
                                       // location or actual data
#if 0

//to be added
unsigned char iic_write_data;
unsigned char iic_reg_addr;
unsigned char iic_read_data;
unsigned char iic_dev_addr;

unsigned char LED_Status = 0;
unsigned long int Sencond_Count = 0;
//unsigned long int MEM_write = 0x1234ABCD;
char MEM_write[4] = {0x12,0x34,0xAB,0xCD};
char MEM_read[4];
//char MEM_p[4];
int r1, r2;

#define UART_CMD_MAGIC 0x4D42
// uart ret
#define ERR_UART_OK		0x00
#define ERR_UART_CMD	0x01
typedef struct 
uart_cmd_t
{
	unsigned short	magic;	//"BM"	// 0x42 0x4D //0x4D42
	unsigned short	hlen;	// head len 0x0C
	unsigned short	mark;	//	ret cmd same as request cmd
	unsigned char	cmd;	//	
	unsigned char	ret;	//	cmd respond 0 success
	unsigned short	value;	// 
	unsigned short	dlen;	//	data len
	//unsigned char	data[0];	//
}uart_cmd;
int needfanspeed = 0;
int needpowerup = 0;
int needbite = 0;

unsigned long int	last_feed_time	= 0;
static char			watch_dog_run	= 0;
int watch_dog_isrun()
{
	return watch_dog_run;
}
int watch_dog_isbite()
{
	return Sencond_Count-last_feed_time >  I2C_Array[INDEX_DOG_TIME_OUT];
}
void watch_dog_stop()
{
	I2C_Array[INDEX_DOG_TIME_OUT] = 0;
	watch_dog_run = 0;
}
void watch_dog_start(unsigned char time)
{
	I2C_Array[INDEX_DOG_TIME_OUT] = time;
	last_feed_time = Sencond_Count;
	watch_dog_run = 1;
}
void watch_dog_feed()
{
	last_feed_time = Sencond_Count;
}

void doreboot()
{
	GIE = 0;
	IOCIE = 0;
	Power_Down();
	delayms(1000);
	Power_Up();
	delayms(200);
	GIE = 1;
	IOCIE = 1;
}
void doreset()
{
	GIE = 0;
	IOCIE = 0;
	Reset();
	GIE = 1;
	IOCIE = 1;
}
void dopowerdown()
{
	GIE = 0;
	IOCIE = 0;
	Power_Down();
	GIE = 1;
	IOCIE = 1;
}
void mcu_watch_dog_start()
{
	//Watchdog Timer Clock Select bits
	WDTCON1bits.WDTCS	= 0b001;//INTOSC/16 (31.25 kHz)
	// Watchdog Timer Prescale Select bits
	WDTCON0bits.WDTPS	= 0b01100;//Interval 4s nominal

	WDTCON0bits.SEN		= 1;//active watch dog

}
void mcu_watch_dog_feed()
{
	asm("CLRWDT");
}
#endif
/**************************** MAIN ROUTINE ************************************/
volatile unsigned char I2C_Array[RX_ELMNTS] =
{VERSION,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define STATUS_POWERUP		1
#define STATUS_POWERDOWN	0
int status_cur = 0;
int status_need = 0;

#define MV_DEF 9550
void delay5us(int time)
//delay about 5us @ 16MHz CLK
{ 
    long int i=0;
    for(i=0;i<time ; i++) ; 
}
void delayms(int time)
//delay about 5us @ 16MHz CLK
{ 
    long int i,j;
    for(i=0;i<time;i++)
        for(j=0; j<79; j++);
}

void power_change(unsigned int mv_cur,	unsigned int mv_need)
{
	unsigned int dacset;
	unsigned int pwmset;
    if (mv_need < 9550)// < 9.55V
    {
        mv_need = 9550;
    }
    if (mv_need > 10880)// > 10.88V
    {
        mv_need = 10880;
    }
	dacset = 2082.7125-191.325*mv_need/1000;
	pwmset = (256-dacset)*1.5625;//pwmset = (256-dacset)/256*400

	if (mv_cur < mv_need)
	{
		PWM_set(pwmset);//max 400
		__delay_ms(200);
		DAC1_set(dacset);//max 255
	}
	else
	{
		DAC1_set(dacset);//max 255
		__delay_ms(200);
		PWM_set(pwmset);//max 400
	}
}
void power_on()
{
	PIC_EN = 1;
	status_cur = STATUS_POWERUP;
}
void power_off()
{
	
	status_cur = STATUS_POWERDOWN;
	PIC_EN = 0;
}


void main(void)
{
	int ret;
	int adcret;
	unsigned int tmp1,tmp2;
	unsigned int mv_check;
	unsigned int mv_cur;
	unsigned int mv_need;
	power_off();
    Initial_sys();
	IIC1_slave_init(I2C_slave_address);

	//set FVR_BUFFER2 2.048v
	FVR_set(FVR_OFF,FVR_2048);
	
	DAC1_init(DAC_PSEL_FVR_BUF2, DAC_NSEl_VSS);

	OPA_set(OPA_PSEL_DAC_OUT,OPA_NSEL_OUT);

	ADC_init(ADC_PSEL_VDD,ADC_NSEL_VSS);

	TIMER2_set();
	TIMER_PWM_sel();

	mv_cur	= 0;//
	mv_need = MV_DEF;//
    //PWM_set(200);
	while(1)
	{
		switch(I2C_Array[1])
		{
			case(0x13)://set mv_need
			{
				mv_need  = I2C_Array[2] + (I2C_Array[3]<<8);
				I2C_Array[1] = 0;
				break;
			}
		}
	//*
		//func 2 temperature protection
		adcret = ADC_run(ADC_CHN_AN3);
		tmp1 = adcret*3.27;//*3350/1024
		I2C_Array[0x10] = tmp1 & 0xFF;
		I2C_Array[0x11] = (tmp1>>8)&0xff;

		adcret = ADC_run(ADC_CHN_AN7);
		tmp2 = adcret*3.27;//*3350/1024;//mv
		I2C_Array[0x12] = tmp2 & 0xFF;
		I2C_Array[0x13] = (tmp2>>8)&0xff;

		if (PORTCbits.RC4 == 0)
		{
			if ((tmp1 > 1650) || (tmp2 > 1650))
			{
				status_need = STATUS_POWERDOWN;
			}
			else if ((tmp1 < 800) && (tmp2 < 800))
			{
				status_need = STATUS_POWERUP;
			}
		}
		else
		{
			status_need = STATUS_POWERDOWN;
		}
		if (status_cur != status_need)
		{
			if (status_need == STATUS_POWERUP)
			{
				power_on();
			}
			else
			{
				power_off();
			}
			status_cur = status_need;
		}

		//func 5 Voltage calibration
		adcret = ADC_run(ADC_CHN_AN2);
		mv_check = adcret*3.27;//*3350/1024;	//mv
		mv_check = mv_check*201/51;		//12V check point mv
		
		//func 4
		//mv_cur = I2C_Array[8] + (I2C_Array[9]<<8);
		if (mv_need < 9550)// < 9.55V
		{
			mv_need = 9550;
		}
		if (mv_need > 10800)// > 10.8V
		{
			mv_need = 10800;
		}

		if (mv_cur != mv_need)
		{
			power_change(mv_cur,mv_need);
			mv_cur = mv_need;
		}
		
		// update status
		I2C_Array[0x0F] = status_cur;
		I2C_Array[0x14] = mv_cur & 0xFF;
		I2C_Array[0x15] = (mv_cur>>8)&0xff;
		I2C_Array[0x16] = mv_check & 0xFF;
		I2C_Array[0x17] = (mv_check>>8)&0xff;
		//*/
	}
}

void interrupt ISR(void) 
{
    //*
	// fun3 IIC
    if (SSP1IF)                              // check to see if SSP interrupt I2C
    {
    	// fix IIC stuck bug
    	if (SSP1CON1bits.SSPOV)
    	{
    		SSP1CON1bits.SSPOV = 0;
    	}
        if (SSP1STATbits.R_nW)               // Master read (R_nW = 1)
        {
            if (!SSP1STATbits.D_nA)        // Last byte was an address (D_nA = 0)
            {
                SSP1BUF = I2C_Array[index_i2c++]; // load with value from array
                SSP1CON1bits.CKP = 1;             // Release CLK
            }
            else//if (SSP1STATbits.D_nA)               // Last byte was data (D_nA = 1)
            {
                SSP1BUF = I2C_Array[index_i2c++]; // load with value from array
                SSP1CON1bits.CKP = 1;             // Release CLK
            }

        }
        else //if (!SSP1STATbits.R_nW) //  Master write (R_nW = 0)
        {
            if (!SSP1STATbits.D_nA) // Last byte was an address (D_nA = 0)
            {
                first = 1; //last byte was address, next will be data location
                junk = SSP1BUF;                  // read buffer to clear BF
                SSP1CON1bits.CKP = 1;            // Release CLK
            }
            else//if (SSP1STATbits.D_nA)               // Last byte was data (D_nA = 1)
            {
                if (first) 
                {
                    index_i2c = SSP1BUF;      // load index with array location
                    first = 0;               // now clear this since we have 
                }                            //location to read from/write to
                else
                {
                    if (index_i2c < RX_ELMNTS)       // make sure index is not
                    {                                //out of range of array
                        I2C_Array[index_i2c++] = SSP1BUF; //load array with data
                    }
                    else
                    {
                        junk = SSP1BUF; //array location not valid, discard data
                    }
                }
                if (SSP1CON1bits.WCOL)           // Did a write collision occur?
                {
                    SSP1CON1bits.WCOL = 0;       //  clear WCOL
                    junk = SSP1BUF;              // dummy read to clear BF bit
                }
                SSP1CON1bits.CKP = 1;            // Release CLK
            }
        }
         SSP1IF = 0;                              // clear SSP1IF flag bit
    }
    if (BCL1IF)                                  // Did a bus collision occur?
    {
        junk = SSP1BUF;                      // dummy read SSP1BUF to clear BF bit
        BCL1IF = 0;                          // clear bus collision Int Flag bit
        SSP1CON1bits.CKP = 1;                // Release CLK
    }

	//Interrupt-on-Change Interrupt Flag bit
	if (IOCIF)
	{
		if (IOCAF)
		{
			
		}
		if (IOCCF)
		{
			if (IOCCFbits.IOCCF4)
			{
				// func 1 power on
				if (PORTCbits.RC4 == 0)
				{
					
					//PIC_EN = 1;//
				}
				else
				{
					//PIC_EN = 0;//
				}
				IOCCFbits.IOCCF4 = 0;
			}
		}
	}
    //*/
}// end of ISR 
