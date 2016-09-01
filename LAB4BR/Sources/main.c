/* ###################################################################
**     Filename    : main.c
**     Project     : LAB4BR
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-01, 20:49, # CodeGen: 0
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
#include "Red.h"
#include "BitIoLdd1.h"
#include "Blue.h"
#include "BitIoLdd2.h"
#include "Green.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdlib.h>
#include <string.h>


void send_string(char *str)
{
	size_t i, len;
	len = strlen(str);
	byte err;
	for (i = 0; i < len; i++) {
		// send this char
		do {
			err = AS1_SendChar(str[i]);
		} while (err != ERR_OK);
	}
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
  char *mess;

  	// Turn on the LEDs
  	Red_ClrVal();
  	Green_ClrVal();
  	Blue_ClrVal();

  	// Send Startup Message
  	send_string("\r\n\r\nWelcome!\r\nProgram Start\r\n");

  	// Check for character
  	byte c, err;
  	for (;;) {
  		do {
  			err = AS1_RecvChar(&c);
  		} while (err != ERR_OK);

  		switch (c) {
  		case 'r': //Check if user inputs a character and check the case
  			Red_NegVal();
  			mess = "Toggle RED\r\n";
  			break;
  		case 'g':
  			Green_NegVal();
  			mess = "Toggle GREEN\r\n";
  			break;
  		case 'b':
  			Blue_NegVal();
  			mess = "Toggle BLUE\r\n";
  			break;
  		default:
  			mess = "ERROR\r\n";
  		}

  		send_string(mess);

  	}
  /* For example: for(;;) { } */

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
