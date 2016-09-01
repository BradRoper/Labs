/* ###################################################################
**     Filename    : main.c
**     Project     : Lab6BR
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-01, 21:30, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Input.h"
#include "BitIoLdd1.h"
#include "TU1.h"
#include "Green.h"
#include "PwmLdd1.h"
#include "Red.h"
#include "PwmLdd2.h"
#include "Blue.h"
#include "BitIoLdd2.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
void updatePWM(uint8 r, uint8 g)
{
	Red_SetRatio8(r);
	Green_SetRatio8(g);

	Term1_SendStr("R=");
	Term1_SendNum(r);
	Term1_SendStr("\tG=");
	Term1_SendNum(g);
	Term1_SendStr("\r\n");
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  uint8 r = 0; // 0 to 0xFF
  uint8 g = 0; // 0 to 0xFF
  updatePWM(r, g);

#define STEP 5
	  char c;
	  if (Term1_KeyPressed()) {
		  Term1_ReadChar(&c);
		  switch (c) {
		  	  case 'R': r = (r < STEP) ? 0 : r-STEP; break;
		  	  case 'G': g = (g < STEP) ? 0 : g-STEP; break;
		  	  case 'r': r = (0xFF-r < STEP) ? 0xFF : r+STEP; break;
		  	  case 'g': g = (0xFF-g < STEP) ? 0xFF : g+STEP; break;
		  	  }
		  updatePWM(r, g);
	  }
  }



  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
