#ifndef RTW_HEADER_pendulum_h_
#define RTW_HEADER_pendulum_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef pendulum_COMMON_INCLUDES_
#define pendulum_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "pendulum_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME pendulum
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T dr4tmwxyco ; real_T ey3uaywzoc ; real_T csmfgwuwmg ;
real_T l2rabknamr ; real_T bwdwg2tsip [ 2 ] ; real_T h5ieqzncec ; } B ;
typedef struct { real_T o112dnv4au ; real_T aj2yaxzolc ; real_T nw543yv2lj ;
real_T muj3awamps ; struct { void * LoggedData ; } lggyldcif4 ; } DW ;
typedef struct { real_T dyp5lz2fxt [ 2 ] ; real_T lufhsw5bp3 [ 2 ] ; } X ;
typedef struct { real_T dyp5lz2fxt [ 2 ] ; real_T lufhsw5bp3 [ 2 ] ; } XDot ;
typedef struct { boolean_T dyp5lz2fxt [ 2 ] ; boolean_T lufhsw5bp3 [ 2 ] ; }
XDis ; typedef struct { real_T dyp5lz2fxt [ 2 ] ; real_T lufhsw5bp3 [ 2 ] ; }
CStateAbsTol ; typedef struct { real_T dyp5lz2fxt [ 2 ] ; real_T lufhsw5bp3 [
2 ] ; } CXPtMin ; typedef struct { real_T dyp5lz2fxt [ 2 ] ; real_T
lufhsw5bp3 [ 2 ] ; } CXPtMax ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T OutputSamplePoints_Value [ 101 ] ;
real_T TransferFcn_A [ 2 ] ; real_T TransferFcn_C [ 2 ] ; real_T Gain_Gain ;
real_T TransferFcn1_A [ 2 ] ; real_T TransferFcn1_C [ 2 ] ; real_T
Gain_Gain_cxkujzgfob ; real_T Constant_Value ; real_T Constant1_Value ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX
; extern DW rtDW ; extern P rtP ; extern mxArray * mr_pendulum_GetDWork ( ) ;
extern void mr_pendulum_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_pendulum_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * pendulum_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
