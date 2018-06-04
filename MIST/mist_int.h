/**
********************************************************************************
* @file     mist_int.h
* @author   Bachmann electronic GmbH
* @version  $Revision: 3.90 $ $LastChangedBy: BE $
* @date     $LastChangeDate: 2013-06-10 11:00:00 $
*
* @brief    This file contains all definitions and declarations,
*           which are global within the SW-module.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2013
*******************************************************************************/

/* Avoid problems with multiple including */
#ifndef MIST_INT__H
#define MIST_INT__H

/* Defines: SMI server */
#define MIST_MINVERS     2        /* min. version number */
#define MIST_MAXVERS     2        /* max. version number */
#define MIST_PROTVERS    2        /* Version number */

/* Structure for module base configuration values */
typedef struct MIST_BASE_PARMS
{
    CHAR    CfgFileName[M_PATHLEN_A];   /* Path/Name of config file, NULL = MCONFIG.INI */
    CHAR    AppName[M_MODNAMELEN_A];    /* Instance name of module */
    SINT32  CfgLine;                    /* Start line number in mconfig file */
    SINT32  DebugMode;                  /* Debug mode from mconfig parameters */
    UINT32  DefaultPriority;            /* Default priority for all worker tasks */
} MIST_BASE_PARMS;

/* Logging macros (single line, so that it does not need parentheses in the code */
#define LOG_I(Level, FuncName, Text, Args...) (mist_Debug >= Level) ? log_Info("%s: %s: " Text, "mist", FuncName, ## Args) : 0
#define LOG_W(Level, FuncName, Text, Args...) (mist_Debug >= Level) ? log_Wrn ("%s: %s: " Text, "mist", FuncName, ## Args) : 0
#define LOG_E(Level, FuncName, Text, Args...) (mist_Debug >= Level) ? log_Err ("%s: %s: " Text, "mist", FuncName, ## Args) : 0
#define LOG_U(Level, FuncName, Text, Args...) (mist_Debug >= Level) ? log_User("%s: %s: " Text, "mist", FuncName, ## Args) : 0

/* Structure for task settings and actual data */
typedef struct TASK_PROPERTIES
{
    /* set values, to be specified */
    CHAR    Name[M_TSKNAMELEN_A];       /* unique visible name for task */
    CHAR    CfgGroup[PF_KEYLEN_A];      /* configuration group name in mconfig */
    VOIDFUNCPTR pMainFunc;              /* function pointer to main function of this task */
    UINT32  Priority;                   /* priority for this task */
    REAL32  CycleTime_ms;               /* cycle time for this task in ms */
    UINT32  TimeBase;                   /* selection of time base */
    UINT32  WDogRatio;                  /* WDogTime = CycleTime * WDogMultiple */
    UINT32  StackSize;                  /* stack size of this task in bytes */
    UINT32  UseFPU;                     /* this task uses the FPU */
    /* actual data, calculated by application */
    UINT32  TaskId;                     /* id returned by task spawn */
    UINT32  WdogId;                     /* watchdog id returned by create wdog */
    UINT32  CycleTime;                  /* cycle time in ticks or syncs */
    UINT32  NextCycleStart;             /* tick/sync counter for next cycle start */
    UINT32  PrevCycleStart;             /* tick/sync counter for next cycle start */
    SINT32  UnitsToWait;                /* number of ticks/syncs to wait (delay) */
    SEM_ID  CycleSema;                  /* semaphore for cycle timing */
    SINT32  SyncSessionId;              /* session id in case of using sync */
    UINT32  SyncEdge;                   /* sync edge selection */
    UINT32  Quit;                       /* task deinit is requested */
    UINT32  NbOfCycleBacklogs;          /* total nb of cycles within a backlog */
    UINT32  NbOfSkippedCycles;          /* total nb of cycles skipped due to backlog */
} TASK_PROPERTIES;

/* SVI parameter function defines */
typedef SINT32(*SVIFKPTSTART) (SVI_VAR * pVar, UINT32 UserParam);
typedef VOID(*SVIFKPTEND) (SVI_VAR * pVar, UINT32 UserParam);

/* Settings for a single global SVI variable */
typedef struct SVI_GLOBVAR
{
    CHAR   *VarName;                    /* Visible name of exported variable */
    UINT32  Format;                     /* Format and access type, use defines SVI_F_xxx */
    UINT32  Size;                       /* Size of exported variable in bytes */
    UINT32 *pVar;                       /* Pointer to exported variable */
    UINT32  UserParam;                  /* User parameter for pSviStart and pSviEnd */
    SVIFKPTSTART pSviStart;             /* Function pointer to lock the access to the variable */
    SVIFKPTEND pSviEnd;                 /* Function pointer to release the lock function */
} SVI_GLOBVAR;

/*--- Variables ---*/

/* Variable definitions: general */
EXTERN SMI_ID *mist_pSmiId;       /* Id for standard module interface */
EXTERN UINT32 mist_ModState;      /* Module state */
EXTERN SEM_ID mist_StateSema;     /* Semaphore for halting tasks */
EXTERN CHAR mist_Version[M_VERSTRGLEN_A]; /* Module version string */

/* Function pointer to application specific smi server */
EXTERN  SINT32(*mist_fpAppSmiSvr) (SMI_MSG * pMsg, UINT32 SessionId);

/* Variable definitions: module parameters */
EXTERN MIST_BASE_PARMS mist_BaseParams;
EXTERN UINT32 mist_CfgLine;       /* Line number in config file to start searching */
EXTERN CHAR mist_ProfileName[M_PATHLEN_A];        /* Path/Name of config file; NULL =
                                                         * mconfig.ini */
EXTERN CHAR mist_AppName[M_MODNAMELEN_A]; /* Instance name of module */
EXTERN SINT32 mist_AppPrio;
EXTERN SINT32 mist_Debug;
EXTERN CHAR8 mist_ModuleInfoDesc[SMI_DESCLEN_A];

/* Variable definitions: SVI server */
EXTERN UINT32 mist_SviHandle;

/* Functions: system global, defined in mist_app.c */
EXTERN SINT32 mist_AppEOI(VOID);
EXTERN VOID mist_AppDeinit(VOID);
EXTERN SINT32 mist_CfgRead(VOID);
EXTERN SINT32 mist_SviSrvInit(VOID);
EXTERN VOID mist_SviSrvDeinit(VOID);

#endif /* Avoid problems with multiple include */
