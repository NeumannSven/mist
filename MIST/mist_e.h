/**
********************************************************************************
* @file     mist_e.h
* @author   Bachmann electronic GmbH
* @version  $Revision: 000 $ $LastChangedBy: BE $
* @date     $LastChangeDate: 2011-08-10 11:00:00 $
*
* @brief    This file contains all definitions and declarations which
*           are exported by the module to other modules on the same CPU.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2011
*******************************************************************************/

/* Avoid problems with multiple including */
#ifndef MIST_E__H
#define MIST_E__H


#include "mist.h"


/*--- Defines ---*/

/*
 * Project specific code for error source.
 * All error codes which are visible outside of the project must contain this
 * code as "error source". The error source for customer application projects
 * must be in the range 0x04000000 to 0x07FF0000.
 * The low word shall contain the error reason.
*/
#define M_ES_MIST  0x04000000




/*--- Structures ---*/


/*--- Function prototypes ---*/


/*--- Variable definitions ---*/


#endif
