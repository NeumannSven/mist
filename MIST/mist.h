/**
********************************************************************************
* @file     mist.h
* @author   Bachmann electronic GmbH
* @version  $Revision: 3.90 $ $LastChangedBy: BE $
* @date     $LastChangeDate: 2013-06-10 11:00:00 $
*
* @brief    This file contains all definitions and declarations which are
*           exported by the module and can be used by other modules
*           on other CPUs.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2013
*******************************************************************************/

/* Avoid problems with multiple including */
#ifndef MIST__H
#define MIST__H


/*--- Defines ---*/

/* Possible SMI's and SVI's (ATTENTION: SMI numbers must be even!) */
#define MIST_PROC_APPSTAT    100  /* SVI example */
#define MIST_PROC_DEMOCALL   102  /* SMI example */

/* Possible error codes of software module */
#define MIST_E_OK            0    /* Everything ok */
#define MIST_E_FAILED       -1    /* General error */


/*--- Structures ---*/

/* Structure for SVI-call MIST_PROC_APPSTAT */
typedef struct
{
    BOOL8   Stop;                       /* Stop application ? */
}
MIST_APPSTAT_C;

/* Structure for SVI-Reply MIST_PROC_APPSTAT */
typedef struct
{
    UINT32  RetCode;                    /* Return code */
    UINT32  EventCount;                 /* Event counter */
    UINT32  DelayTime;                  /* Delay for chaser light */
    BOOL8   Stop;                       /* Stop chaser light */
}
MIST_APPSTAT_R;

/* Structure for SVI-call MIST_DEMOCALL */
typedef struct
{
    UINT32  Spare;                      /* Not used, 0 for now */
}
MIST_DEMOCALL_C;

/* Structure for SVI-Reply MIST_DEMOCALL */
typedef struct
{
    SINT32  RetCode;                    /* OK or error code */
    UINT32  CallCount;                  /* Number of calls */
    CHAR    String[128];                /* String */
}
MIST_DEMOCALL_R;


/*--- Function prototyping ---*/


/*--- Variable definitions ---*/


#endif
