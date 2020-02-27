#ifndef TMU_CFG_H_
#define	TMU_CFG_H_

#include "std_types.h"

#define TMU_TIMER_CH0	(0)			 /* defines Timer 0 */
#define TMU_TIMER_CH1	(1)			 /* defines Timer 1 */
#define TMU_TIMER_CH2	(2)			 /* defines Timer 2 */

#define Res1			(1)
#define Res2			(2)
#define Res3			(3)

typedef struct Tmu_cfg_Init{
	uint8_t  Tmu_Ch_Timer;			 /* To choose the Timer number */
	uint8_t  Tmu_Res;      			 /*To choose the resolution we work with*/
}TMU_ConfigType;


extern TMU_ConfigType ConfigPtr;
extern TMU_ConfigType ConfigPtr1;
extern TMU_ConfigType ConfigPtr2;
extern TMU_ConfigType ConfigPtr3;
//extern TMU_ConfigType ConfigPtr4;




#endif



