

 /*********************************************
 *				Includes  					 *
 ********************************************/
 #include "std_types.h"
 #include "Tmu.h"
/*********************************************
 *	   Function Implementation  	       	  *
 ********************************************/

void func1(void)
{

	//PORTA_DATA=0x01;
}

void func2(void)
{
	//PORTA_DATA=0x04;
}

void func3(void)
{
	//PORTA_DATA=0x02;
}

void func4(void)
{
	//PORTA_DATA=0x02;
}

/********************************************
*				CBK_Functions                *
*********************************************/

TMU_Cfg_start TMU_Cfg_start_Fun1 = {250,0,0,func1};

TMU_Cfg_start TMU_Cfg_start_Fun2 = {500,1,0,func2};

TMU_Cfg_start TMU_Cfg_start_Fun3 = {750,1,0,func3};

TMU_Cfg_start TMU_Cfg_start_Fun4 = {500,4,0,NULL};


/******static global Array of Call Back Structure functions*******/
 static TMU_Cfg_start TMU_CBK_Arr_Struct[No_of_CBK];

 /*{TMU_Cfg_start_Fun1,TMU_Cfg_start_Fun2,TMU_Cfg_start_Fun3};*/

 /*******TMU_Ch_TimerNo to store the channel timer********/
 static uint8_t TMU_Ch_TimerNo = 0;
 /************index of the array of structure***************/
 static uint8_t arr_counter=0;

 /********* TMU_FLag_Fun variable store no of timer ticks************/
 volatile uint16_t TMU_FLag_Fun = 1;
 /********* TMU_FLag_Fun Array store no of timer ticks************/
 volatile uint16_t TMU_Flag_Arr[No_of_CBK]={0};

 static uint8_t arr[No_of_CBK]={0};

 uint8_t x = 0;
 /********************************************
 *			  Function Implementation        *
 *********************************************/
 /**
 * Func			: Tmu_Init
 * Input		: Pointer to a structure of type Tmu_cfg_Init contains the Tmu channel timer and resolution
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: Initialize (timer channel ,resolution of the tmu)
 */
 uint8_t Tmu_Init(const TMU_ConfigType * ConfigPtr ){
	 uint8_t Err_status = 0;

	 if (ConfigPtr == NULL)
	 {
		 Err_status = NULL_PTR1;
	 }
	 else
	 {
		 //create an object for timer structure
		 Timer_Cfg_S Timer_Cfg;

		 //Declaring TMU_Ch_TimerNo to store timer channel
		 TMU_Ch_TimerNo  = ConfigPtr->Tmu_Ch_Timer;

		 //Definition of timer
		 Timer_Cfg.Timer_CH_NO = TMU_Ch_TimerNo;
		 Timer_Cfg.Timer_Mode  = 0;
		 Timer_Cfg.Timer_Polling_Or_Interrupt = 0x40;   //T2_INTERRUPT_NORMAL=0x40;
		 Timer_Cfg.Timer_Prescaler = T2_PRESCALER_64;

		 Err_status = Timer_Init(&Timer_Cfg);
	 }

	return Err_status;
 }


 /**
 * Func			: Tmu_Start
 * Input		: Pointer to a structure of type contains the Tmu_delay ,Tmu_periodicity and call back function
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: Start the TMU (one shot or period , delay time, call back function)
 */

uint8_t Tmu_Start(TMU_Cfg_start * TMUStartPtr){
	uint8_t Err_Status =E_OK;
	if (TMUStartPtr==NULL)
	{
		Err_Status=NULL_PTR1;

	}
	else
	{
	/*****Fill  the elements of the array to start the  tasks ******/
	TMU_CBK_Arr_Struct[arr_counter] = *TMUStartPtr;

	/*******Increment the arr_counter to move to the next elemnt of the array and reinitialized in Deinit function****/
	arr_counter++;

	//start timer to count delay
	Timer_Start(TMU_Ch_TimerNo,0);

	Err_Status=E_OK;
	}

	return Err_Status;
}
 /**
 * Func			: TMU_Dispatch
 * Input		: Pointer to a pointer to array of Call Back Structure functions
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	:
 */

uint8_t TMU_Dispatch(){
uint8_t Err_Status = E_OK;

		if (TMU_FLag_Fun == 1)
		{
			TMU_CBK_Arr_Struct[0].Tmu_Counter++;
			TMU_CBK_Arr_Struct[1].Tmu_Counter++;
			TMU_CBK_Arr_Struct[2].Tmu_Counter++;
			TMU_FLag_Fun=0;
		}
		else
		{
			//do Nothing
		}

		if (arr_counter==0)
		{
			Err_Status = EMPTY_BUFFER;

		}
		else
		{
		for (uint8_t i=0; i<arr_counter ; i++)
		{
			if (TMU_CBK_Arr_Struct[i].Tmu_Counter==TMU_CBK_Arr_Struct[i].Tmu_delay)
			{
				TMU_CBK_Arr_Struct[i].Tmu_Cbk_ptr();
				TMU_CBK_Arr_Struct[i].Tmu_Counter=0;

				if (TMU_CBK_Arr_Struct[i].Tmu_periodicity == 0)
				{
					TMU_Stop_Timer(TMU_CBK_Arr_Struct[i].Tmu_Cbk_ptr);
				}
				else
				{
					//do Nothing
				}
			}
			else
			{
				//do Nothing
			}
		}
			}
	  return Err_Status;

 }


/**
 * Func			: Tmu_Stop
 * Input		: Pointer to a structure of type  call back function
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: stop(call back function)
 */

uint8_t TMU_Stop_Timer (void(*ptr)(void)){


    uint8_t Err_Status = E_OK;

    if (ptr == NULL){
            Err_Status = NULL_PTR1;
    }else{
	/***********initialize arr_counter**********/
	 uint8_t S_Arr_counter;
	 //arr_counter
	 for(S_Arr_counter = 0;S_Arr_counter<arr_counter;S_Arr_counter++){

		if(TMU_CBK_Arr_Struct[S_Arr_counter].Tmu_Cbk_ptr==ptr){

			TMU_CBK_Arr_Struct[S_Arr_counter] = TMU_CBK_Arr_Struct[arr_counter-1];

			TMU_CBK_Arr_Struct[arr_counter-1].Tmu_Cbk_ptr = NULL;
			TMU_CBK_Arr_Struct[arr_counter-1].Tmu_delay = 0;
			TMU_CBK_Arr_Struct[arr_counter-1].Tmu_periodicity = 0;

			/*************Decrement the structures of the array*******************/
			arr_counter--;

		}
	 }
    }
	return  Err_Status;
 }

/**
 * Func			: Tmu_Deinit
 * Input		: Pointer to a structure of type Tmu_cfg_Init contains the Tmu channel timer and resolution
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: Deinitialize shall uninitialized the hardware timer module.
 */


uint8_t Tmu_DeInit( ){

    uint8_t Err_Status = E_OK;

	//Timer_Stop(TMU_Ch_TimerNo);
	 x=0;
	for(uint8_t i=0;i<arr_counter-1;i++){


		TMU_CBK_Arr_Struct[i].Tmu_delay = 0;
		TMU_CBK_Arr_Struct[i].Tmu_periodicity = 0;
		TMU_CBK_Arr_Struct[i].Tmu_Cbk_ptr = NULL;
	}

	return Err_Status;
 }



ISR(TIMER2_OVF_vect){

	TMU_FLag_Fun++;

	for(uint8_t i=0;i<arr_counter;i++){

		TMU_Flag_Arr[i] = TMU_FLag_Fun %(TMU_CBK_Arr_Struct[i].Tmu_delay);
	}
}

