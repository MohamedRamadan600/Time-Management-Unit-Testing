/*
 * Timer.h
 *
 *  Created on: Feb 17, 2020
 *  Author : Mohamed Ramadan
 */

#ifndef TIMER_STUB_H_
#define TIMER_STUB_H_

/************************************************************************/
/*				 INCLUDES			        */
/************************************************************************/

#include "std_types.h"
#include "registers.h"

/************************************************************************/
/*				 DEFINES			        */
/************************************************************************/


#define		TIMER_CH0						 0
#define		TIMER_CH1						 1
#define		TIMER_CH2						 2

#define		TIMER_MODE					     0
#define		COUNTER_RISING_MODE		      	 1
#define		COUNTER_FALLING_MODE		     2

#define		TIMER_POLLING_MODE				 0
#define		TIMER_INTERRUPT_MODE			 1

#define		T0_NO_CLOCK						 0
#define		T0_PRESCALER_NO					0x01
#define		T0_PRESCALER_8					0x02
#define		T0_PRESCALER_64                 0x03
#define		T0_PRESCALER_256                0x04
#define		T0_PRESCALER_1024               0x05

#define		T1_NO_CLOCK						0x0000
#define		T1_PRESCALER_NO					0x0001
#define		T1_PRESCALER_8					0x0002
#define		T1_PRESCALER_64                 0x0003
#define		T1_PRESCALER_256                0x0004
#define		T1_PRESCALER_1024               0x0005

#define		T2_NO_CLOCK						 0
#define		T2_PRESCALER_NO					0x01
#define		T2_PRESCALER_8					0x02
#define		T2_PRESCALER_32                 0x03
#define		T2_PRESCALER_64                 0x04
#define		T2_PRESCALER_128                 0x05
#define		T2_PRESCALER_256                0x06
#define		T2_PRESCALER_1024               0x07



#define  NULL_PTR					-1
#define MODULE_UNITIALIZED			-2
#define MULTIPLE_INIYIALIZATION	    -3
#define INVALID_PARAMETER			-4
#define MULTIPLE_STOP				-5
/************************************************************************/
/*						PINS/BITS defines                               */
/************************************************************************/

#define PIN0  0			// defines BIT0 in a register
#define PIN1  1			// defines BIT1 in a register
#define PIN2  2			// defines BIT2 in a register
#define PIN3  3			// defines BIT3 in a register
#define PIN4  4			// defines BIT4 in a register
#define PIN5  5			// defines BIT5 in a register
#define PIN6  6			// defines BIT6 in a register
#define PIN7  7			// defines BIT7 in a register

#define BIT0  0x01		// defines BIT0 in a register
#define BIT1  0x02		// defines BIT1 in a register
#define BIT2  0x04		// defines BIT2 in a register
#define BIT3  0x08		// defines BIT3 in a register
#define BIT4  0x10		// defines BIT4 in a register
#define BIT5  0x20		// defines BIT5 in a register
#define BIT6  0x40		// defines BIT6 in a register
#define BIT7  0x80		// defines BIT7 in a register

#define	True    1
#define	False   0

#define Clr_Bit(PORT,PIN)  (PORT &=~(1<<PIN))
#define Set_Bit(PORT,PIN)  (PORT|=(1<<PIN))

/************************************************************************/
/*			  Structures Definitions		                            */
/************************************************************************/

typedef struct Timer_cfg_s
{
	uint8_t Timer_CH_NO;
	uint8_t Timer_Mode;
	uint8_t Timer_Polling_Or_Interrupt;
	uint8_t Timer_Prescaler;
	//void (*Timer_Cbk_ptr)(void);
}Timer_Cfg_S;



/************************************************************************/
/*		         TIMER FUNCTIONS' PROTOTYPES		        */
/************************************************************************/


/**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */
uint8_t Timer_Init(Timer_Cfg_S* Timer_Cfg);

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be started.
 *	Timer_Count: The start value of the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function starts the needed timer.
 *
 */
uint8_t Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count);

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
uint8_t Timer_Stop(uint8_t Timer_CH_NO);

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Timer_Status: A pointer is used to return the status of the flag of the timer.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return if the flag of the timer is raised or not.
 * 	ERROR_STATUS
 */
 uint8_t Timer_GetStatus(uint8_t Timer_CH_NO, uint8_t* Timer_Status);

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Timer_Value: This is an pointer that catch the address of the variable which store the value of TCNT register (counter value)
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
uint8_t Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Timer_Value);

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to set its value.
 * 	Timer_Value: This is the value that you will set the timer by it.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to set the value of the timer.
 *
 */
uint8_t Timer_SetValue(uint8_t Timer_CH_NO, uint16_t Timer_Value);




//Delay function to test only not involved in static code
void timer2DelayMs(uint16_t u16_delay_in_ms);

//Delay function to test only not involved in static code
void timer0DelayMs(uint16_t u16_delay_in_ms);






#endif /* TIMER_H_ */
