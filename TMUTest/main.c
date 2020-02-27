#include <stdio.h>
#include "TimerStub.h"
#include "Tmu_cfg.h"
#include "std_types.h"
#include "Tmu.h"




int main()
{

/***********************Testing TMU_Dispatch FUNCTION for Empty Buffer***********************************/

/******************Test Case1*******************
************************************************
********* Expected Result is Buffer Empty ******/

   switch(TMU_Dispatch()){

   case E_OK:
       printf("No error Detected\t\t\t\t\t");
       printf("Test Case1 is Failed\n\n");
    break;

   case E_NOK:
       printf("General Error Detected\t\t\t\t\t");
       printf("Test Case1 is Failed\n\n");
    break;

   case EMPTY_BUFFER:
        printf("Empty Buffer\t\t\t\t\t\t");
        printf("Test Case1 is Passed\n\n");

   }




/************************Testing TMU_INITIALIZATON ***********************************/

/******************Test Case2******************
***********************************************
************* Expected Result is E_OK ********/

   switch(Tmu_Init(&ConfigPtr)){

   case E_OK:
       printf("Test Case2 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case2 is Failed\n\n");
    break;

   }


   /******************Test Case3******************
   ***********************************************
   ************* Expected Result is Passed *******/

   switch(Tmu_Init(&ConfigPtr1)){

   case E_OK:
       printf("Test Case3 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case3 is Failed\n\n");
    break;

   }

   /******************Test Case4******************
   ***********************************************
   ************* Expected Result is Passed *******/

   switch(Tmu_Init(&ConfigPtr2)){

   case E_OK:
       printf("Test Case4 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case4 is Failed\n\n");
    break;


   }

   /******************Test Case5******************
   ***********************************************
   ************* Expected Result is INVALID PARAMETERS *******/

   switch(Tmu_Init(&ConfigPtr3)){

   case E_OK:
       printf("Error not detected\t\t");
       printf("Test Case5 is Failed\n\n");
    break;

   case E_NOK:
       printf("General Error detected But not specified\t\t");
       printf("Test Case5 is Failed\n\n");
    break;

    case INVALID_PARAMETERS:
       printf("INVALID PARAMETER DETECTED\t\t");
       printf("Test Case5 is Passed\n\n");
    break;

   }

   /******************Test Case6******************
   ***********************************************
   ************* Expected Result is NULLPTR ******/
   switch(Tmu_Init(NULL)){

   case E_OK:
       printf("Test Case6 is Failed\n\n");
    break;


   case E_NOK:
       printf("Test Case6 is Failed\n\n");
    break;

   case NULL_PTR1:
       printf("NULLPTR ERROR Detected\t\t\t\t\t");
       printf("Test Case6 is passed\n\n");
    break;

   }

/************************Testing TMU_START FUNCTION ******************************************/

   switch(Tmu_Start(&TMU_Cfg_start_Fun1)){

   case E_OK:
       printf("Test Case7 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case7 is Failed\n\n");
    break;

   }


   /******************Test Case8******************
   ***********************************************
   ************* Expected Result is Passed *******/

   switch(Tmu_Start(&TMU_Cfg_start_Fun2)){

   case E_OK:
       printf("Test Case8 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case8 is Failed\n\n");
    break;

   }

   /******************Test Case9******************
   ***********************************************
   ************* Expected Result is Passed *******/

   switch(Tmu_Start(&TMU_Cfg_start_Fun3)){

   case E_OK:
       printf("Test Case 9 is passed\n\n");
    break;

   case E_NOK:
       printf("Test Case 9 is Failed\n\n");
    break;


   }

   /******************Test Case10******************
   ***********************************************
   ************* Expected Result is INVALID PARAMETERS *******/

   switch(Tmu_Start(&TMU_Cfg_start_Fun4)){

   case E_OK:
       printf("Error Not Detected\t\t\t\t\t");
       printf("Test Case10 is Failed\n\n");
    break;

   case E_NOK:
       printf("Test Case 10 is Failed\n\n");
    break;

    case INVALID_PARAMETERS:
       printf("INVALID PARAMETER DETECTED\t");
       printf("Test Case 10 is Passed\n\n");
    break;

   }

   /******************Test Case11******************
   ***********************************************
   ************* Expected Result is NULLPTR ******/
   switch(Tmu_Start(NULL)){

   case E_OK:
       printf("Test Case11 is Failed\n\n");
    break;


   case E_NOK:
       printf("Test Case11 is Failed\n\n");
    break;

   case NULL_PTR1:
       printf("NULLPTR ERROR Detected\t\t\t\t\t");
       printf("Test Case11 is passed\n\n");
    break;

   }

/******************Test Case12******************
***********************************************
************* Expected Result is NULLPTR ******/
   switch(Tmu_Start(&TMU_Cfg_start_Fun3)){

   case E_OK:
       printf("Test Case 12 is Failed\n\n");
    break;

   case E_NOK:
       printf("Test Case 12 is Failed\n\n");
    break;

   case NULL_PTR1:
       printf("NULLPTR ERROR Detected\t\t\t\t\t");
       printf("Test Case 12 is passed\n\n");
    break;

   }

/******************Test Case13******************
***********************************************
************* Expected Result is NULLPTR ******/
   switch(TMU_Dispatch()){

   case E_OK:
       printf("No error Detected\t\t\t\t\t");
       printf("Test Case 13 is Failed\n\n");
    break;

   case E_NOK:
       printf("General Error Detected\t\t\t\t\t");
       printf("Test Case 13 is Failed\n\n");
    break;

    case EMPTY_BUFFER:
        printf("Empty Buffer\t\t\t\t\t\t");
        printf("Test Case 13 is Failed\n\n");

   case FULL_BUFFER:
       printf("FULL Buffer\t\t\t\t\t\t");
       printf("Test Case 13 is passed\n\n");
    break;

   }

/*************Testing TMU_STOP FUNCTION for Empty Buffer***********************/


/******************Test Case14******************
***********************************************
************* Expected Result is NULLPTR ******/
   switch(TMU_Stop_Timer(NULL)){

   case E_OK:
       printf("No error Detected\t\t\t\t\t");
       printf("Test Case 14 is Failed\n\n");
    break;

   case E_NOK:
       printf("General Error Detected\t\t\t\t\t");
       printf("Test Case 14 is Failed\n\n");
    break;

    case EMPTY_BUFFER:
        printf("Empty Buffer\t\t\t\t\t\t");
        printf("Test Case 14 is Failed\n\n");

    case NULL_PTR1:
       printf("NULLPTR ERROR Detected\t\t\t\t\t");
       printf("Test Case11 is passed\n\n");
    break;

   case FULL_BUFFER:
       printf("FULL Buffer\t\t\t\t\t\t");
       printf("Test Case 13 is Failed\n\n");
    break;

   }




    return 0;
}
