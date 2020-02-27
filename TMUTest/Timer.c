/************************************************************************/
/*				 INCLUDES			        */
/************************************************************************/
#include "Timer.h"


uint16_t prescaler_Timer0;    //global variable to store the prescaler
uint16_t prescaler_Timer1;
uint16_t prescaler_Timer2;
/************************************************************************/
/*		         TIMER FUNCTIONS' Implementations		        */
/************************************************************************/

/**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */

uint8_t Timer_Init(Timer_Cfg_S* Timer_Cfg){
	uint8_t Er_Status =0;

	if (Timer_Cfg == NULL){
		Er_Status = NULL_PTR;
	}else
	{
	uint8_t CH_NO = 0;
	CH_NO = Timer_Cfg->Timer_CH_NO;
	switch (CH_NO)
	{
	case TIMER_CH0:
		Er_Status=E_OK;
		break;
	case TIMER_CH1:
		Er_Status=E_OK;
		break;
	case TIMER_CH2:
		Er_Status=E_OK;
		break;
	default:
		Er_Status=E_NOK;
	}
	}
	return	Er_Status;
}

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
uint8_t Timer_Start(uint8_t Timer_CH_NO, uint16_t Timer_Count){

	uint8_t Er_Status =0;

	switch (Timer_CH_NO)
	{
		case TIMER_CH0:
			Er_Status = E_OK;
			break;
		case TIMER_CH1:
			Er_Status = E_OK;
			break;
		case TIMER_CH2:
			Er_Status = E_OK;
			break;
		default:
			Er_Status = E_NOK;
	}
return Er_Status;
}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
uint8_t Timer_Stop(uint8_t Timer_CH_NO){
	uint8_t Er_Status =0;
	switch (Timer_CH_NO)
	{
		case TIMER_CH0:
			Er_Status = E_OK;
			break;
		case TIMER_CH1:
			Er_Status = E_OK;
			break;
		case TIMER_CH2:
			Er_Status = E_OK;
			break;
		default:
			Er_Status = E_NOK;
	}
return Er_Status;

}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Data: A variable of type bool returns if the flag of the timer is raised or not.
 * Return: The error status of the function.
 * Description: This function is used to return if the flag of the timer is raised or not.
 * 	ERROR_STATUS
 */
uint8_t Timer_GetStatus(uint8_t Timer_CH_NO, uint8_t* Timer_Status){

	uint8_t Er_Status =0;

	switch (Timer_CH_NO)
	{
		case TIMER_CH0:
			Er_Status = E_OK;
			break;
		case TIMER_CH1:
			Er_Status = E_OK;
			break;
		case TIMER_CH2:
			Er_Status = E_OK;
			break;
		default:
			Er_Status = E_NOK;

	}

	return Er_Status;
 }

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
uint8_t Timer_GetValue(uint8_t Timer_CH_NO, uint16_t* Timer_Value){

		uint8_t Er_Status =0;

		switch (Timer_CH_NO)
		{
			case TIMER_CH0:
				Er_Status = E_OK;
				break;
			case TIMER_CH1:
				Er_Status = E_OK;
				break;
			case TIMER_CH2:
				Er_Status = E_OK;
				break;
			default:
				Er_Status = E_NOK;
		}
	return	Er_Status;

}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to set its value.
 * 	Timer_Value: This is the value that you will set the timer by it.
 * Return: The error status of the function.
 * Description: This function is used to set the value of the timer.
 *
 */
uint8_t Timer_SetValue(uint8_t Timer_CH_NO, uint16_t Timer_Value){

	uint8_t Er_Status =0;

	switch (Timer_CH_NO)
	{
		case TIMER_CH0:
			Er_Status = E_OK;
			break;
		case TIMER_CH1:
			Er_Status = E_OK;
			break;
		case TIMER_CH2:
			Er_Status = E_OK;
			break;
		default:
			Er_Status = E_NOK;
	}
	return	Er_Status;
}







