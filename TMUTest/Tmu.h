#ifndef TMU_H_
#define TMU_H_
/*
 * File		: Tmu.h
 * Author	: M.Ramadan
 */

/*********************************************
 *				Includes  					 *
 ********************************************/
 #include "TimerStub.h"
 #include "Tmu_cfg.h"


/*********************************************
 *				Defines  					 *
 ********************************************/
 #define No_of_CBK    3

 #define E_OK    0
 #define E_NOK   1

 #define NULL_PTR1					2
 #define MODULES_UNITIALIZED		3
 #define MULTIPLES_INIYIALIZATION	4
 #define STOP_WITH_START			5
 #define INVALID_PARAMETERS			6
 #define MULTIPLES_STOP				7
 #define MULTIPLE_START				8
 #define FULL_BUFFER				9
 #define EMPTY_BUFFER				10



/************************************************************************/
/*			  Structures Declaration		                            */
/************************************************************************/
typedef struct Tmu_cfg_start
{
	uint16_t Tmu_delay;
	uint16_t Tmu_periodicity;
	uint16_t Tmu_Counter;
	void (*Tmu_Cbk_ptr)(void);
}TMU_Cfg_start;

/************************************************************************/
/*			  Structures Definitions		                            */
/************************************************************************/
extern TMU_Cfg_start TMU_Cfg_start_Fun1;
extern TMU_Cfg_start TMU_Cfg_start_Fun2;
extern TMU_Cfg_start TMU_Cfg_start_Fun3;
extern TMU_Cfg_start TMU_Cfg_start_Fun4;

typedef enum EnmTMUError_t{
	Null_ptr=0, Module_Not_Initialized = 1, Multiple_Initialization = 2, Stop_Without_start =3, Invalid_Parameter = 4, Multiple_Stop =5, Multiple_Start =6, Full_Buffer= 7
}EnmTMUError_t;



 /*********************************************
 *	  	   Function prototypes				 *
 ********************************************/

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


 uint8_t Tmu_Init(const TMU_ConfigType * ConfigPtr );

/**
 * Func			: Tmu_Start
 * Input		: Pointer to a structure of type contains the Tmu_delay ,Tmu_periodicity and call back function
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: Initialize (timer channel ,resolution of the tmu)
 */

uint8_t Tmu_Start(TMU_Cfg_start * TMUStartPtr);


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

 uint8_t TMU_Stop_Timer ();

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

 uint8_t TMU_Dispatch();

 /**
 * Func			: Tmu_Deinit
 * Input		: Pointer to a structure of type Tmu_cfg_Init contains the Tmu channel timer and resolution
 * Output
 * Return 		: value of type ERROR_STATUS							   *
 * 				  which is one of the following values:					   *
 * 				  - E_OK : successful									   *
 *				  - E_NOK : not successful
 *
 * Description	: Deinitialize (timer channel ,resolution of the tmu)
 */


 uint8_t Tmu_DeInit(void);


 #endif
