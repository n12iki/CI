#include "rt_logging_mmi.h"
#include "pendulum_capi.h"
#include <math.h>
#include "pendulum.h"
#include "pendulum_private.h"
#include "pendulum_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.6 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T osl3exmghn ( real_T x , const real_T params [ 2 ] )
; static real_T de04x4wknr ( real_T x , const real_T params [ 3 ] ) ; static
real_T osl3exmghnk ( real_T x , const real_T params [ 2 ] ) ; static void
fgif5hwjdq ( const real_T x [ 101 ] , const real_T params [ 4 ] , real_T y [
101 ] ) ; static real_T osl3exmghn ( real_T x , const real_T params [ 2 ] ) {
real_T value ; real_T y ; y = 0.0 ; if ( x <= params [ 0 ] ) { y = 1.0 ; } if
( ( params [ 0 ] < x ) && ( x <= ( params [ 0 ] + params [ 1 ] ) / 2.0 ) ) {
value = 1.0 / ( params [ 0 ] - params [ 1 ] ) * ( x - params [ 0 ] ) ; y =
1.0 - 2.0 * value * value ; } if ( ( ( params [ 0 ] + params [ 1 ] ) / 2.0 <
x ) && ( x <= params [ 1 ] ) ) { value = 1.0 / ( params [ 0 ] - params [ 1 ]
) * ( params [ 1 ] - x ) ; y = 2.0 * value * value ; } if ( params [ 1 ] <= x
) { y = 0.0 ; } return y ; } static real_T de04x4wknr ( real_T x , const
real_T params [ 3 ] ) { real_T y ; y = 0.0 ; if ( ( params [ 0 ] < x ) && ( x
< 0.0 ) ) { y = 1.0 / ( 0.0 - params [ 0 ] ) * ( x - params [ 0 ] ) ; } if (
( 0.0 < x ) && ( x < params [ 2 ] ) ) { y = ( params [ 2 ] - x ) * ( 1.0 /
params [ 2 ] ) ; } if ( x == 0.0 ) { y = 1.0 ; } return y ; } static real_T
osl3exmghnk ( real_T x , const real_T params [ 2 ] ) { real_T value ; real_T
y ; y = 0.0 ; if ( ( params [ 0 ] < x ) && ( x <= ( params [ 0 ] + params [ 1
] ) / 2.0 ) ) { value = 1.0 / ( params [ 1 ] - params [ 0 ] ) * ( x - params
[ 0 ] ) ; y = 2.0 * value * value ; } if ( ( ( params [ 0 ] + params [ 1 ] )
/ 2.0 < x ) && ( x <= params [ 1 ] ) ) { value = 1.0 / ( params [ 1 ] -
params [ 0 ] ) * ( params [ 1 ] - x ) ; y = 1.0 - 2.0 * value * value ; } if
( params [ 1 ] <= x ) { y = 1.0 ; } return y ; } static void fgif5hwjdq (
const real_T x [ 101 ] , const real_T params [ 4 ] , real_T y [ 101 ] ) {
real_T a ; real_T b ; real_T b_y1 ; real_T c ; real_T d ; real_T x_p ; real_T
y2 ; int32_T i ; a = params [ 0 ] ; b = params [ 1 ] ; c = params [ 2 ] ; d =
params [ 3 ] ; for ( i = 0 ; i < 101 ; i ++ ) { x_p = x [ i ] ; b_y1 = 0.0 ;
y2 = 0.0 ; if ( x_p >= b ) { b_y1 = 1.0 ; } if ( x_p < a ) { b_y1 = 0.0 ; }
if ( ( a <= x_p ) && ( x_p < b ) ) { b_y1 = 1.0 / ( b - a ) * ( x_p - a ) ; }
if ( x_p <= c ) { y2 = 1.0 ; } if ( x_p > d ) { y2 = 0.0 ; } if ( ( c < x_p )
&& ( x_p <= d ) ) { y2 = 1.0 / ( d - c ) * ( d - x_p ) ; } y [ i ] =
muDoubleScalarMin ( b_y1 , y2 ) ; } } void MdlInitialize ( void ) { rtX .
dyp5lz2fxt [ 0 ] = 0.0 ; rtX . lufhsw5bp3 [ 0 ] = 0.0 ; rtX . dyp5lz2fxt [ 1
] = 0.0 ; rtX . lufhsw5bp3 [ 1 ] = 0.0 ; rtDW . o112dnv4au = ( rtInf ) ; rtDW
. nw543yv2lj = ( rtInf ) ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T outputMFCache
[ 303 ] ; real_T cnodaj4xbu [ 101 ] ; real_T tmp_e [ 101 ] ; real_T tmp_i [
101 ] ; real_T inputMFCache [ 6 ] ; real_T op4hyjkc4a [ 5 ] ; real_T tmp_p [
3 ] ; real_T tmp [ 2 ] ; real_T adj1ybmzos ; real_T agmrgi4ydo ; real_T
ktvbvsiykv_idx_0 ; real_T ktvbvsiykv_idx_1 ; real_T * lastU ; int32_T i ;
int32_T inputID ; int8_T c ; static const real_T b [ 2 ] = { - 1.8 , - 0.2 }
; static const real_T b_p [ 4 ] = { - 25.0 , - 22.3 , - 10.6481481481481 , -
0.5 } ; static const int8_T c_p [ 10 ] = { 1 , 2 , 3 , 0 , 0 , 0 , 0 , 0 , 1
, 3 } ; static const real_T c_e [ 4 ] = { 0.5 , 11.1772486772487 , 21.0 ,
25.0 } ; static const int8_T d [ 5 ] = { 1 , 2 , 3 , 1 , 3 } ; rtB .
dr4tmwxyco = ( rtP . TransferFcn_C [ 0 ] * rtX . dyp5lz2fxt [ 0 ] + rtP .
TransferFcn_C [ 1 ] * rtX . dyp5lz2fxt [ 1 ] ) * rtP . Gain_Gain ; rtB .
ey3uaywzoc = ( rtP . TransferFcn1_C [ 0 ] * rtX . lufhsw5bp3 [ 0 ] + rtP .
TransferFcn1_C [ 1 ] * rtX . lufhsw5bp3 [ 1 ] ) * rtP . Gain_Gain_cxkujzgfob
; rtB . csmfgwuwmg = rtP . Constant_Value - rtB . dr4tmwxyco ; if ( ( rtDW .
o112dnv4au >= ssGetT ( rtS ) ) && ( rtDW . nw543yv2lj >= ssGetT ( rtS ) ) ) {
rtB . l2rabknamr = 0.0 ; } else { agmrgi4ydo = rtDW . o112dnv4au ; lastU = &
rtDW . aj2yaxzolc ; if ( rtDW . o112dnv4au < rtDW . nw543yv2lj ) { if ( rtDW
. nw543yv2lj < ssGetT ( rtS ) ) { agmrgi4ydo = rtDW . nw543yv2lj ; lastU = &
rtDW . muj3awamps ; } } else if ( rtDW . o112dnv4au >= ssGetT ( rtS ) ) {
agmrgi4ydo = rtDW . nw543yv2lj ; lastU = & rtDW . muj3awamps ; } rtB .
l2rabknamr = ( rtB . csmfgwuwmg - * lastU ) / ( ssGetT ( rtS ) - agmrgi4ydo )
; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } agmrgi4ydo = 0.0 ; tmp [ 0 ] = -
40.0 ; tmp [ 1 ] = 0.0 ; inputMFCache [ 0 ] = osl3exmghn ( rtB . csmfgwuwmg ,
tmp ) ; tmp_p [ 0 ] = - 40.0 ; tmp_p [ 1 ] = 0.0 ; tmp_p [ 2 ] = 40.0 ;
inputMFCache [ 1 ] = de04x4wknr ( rtB . csmfgwuwmg , tmp_p ) ; tmp [ 0 ] =
0.0 ; tmp [ 1 ] = 44.0 ; inputMFCache [ 2 ] = osl3exmghnk ( rtB . csmfgwuwmg
, tmp ) ; inputMFCache [ 3 ] = osl3exmghn ( rtB . l2rabknamr , b ) ; tmp_p [
0 ] = - 2.5 ; tmp_p [ 1 ] = 0.0 ; tmp_p [ 2 ] = 2.5 ; inputMFCache [ 4 ] =
de04x4wknr ( rtB . l2rabknamr , tmp_p ) ; tmp [ 0 ] = 0.2 ; tmp [ 1 ] = 1.8 ;
inputMFCache [ 5 ] = osl3exmghnk ( rtB . l2rabknamr , tmp ) ; for ( i = 0 ; i
< 5 ; i ++ ) { adj1ybmzos = 1.0 ; c = c_p [ i ] ; if ( c != 0 ) {
ktvbvsiykv_idx_1 = inputMFCache [ c - 1 ] ; if ( 1.0 > ktvbvsiykv_idx_1 ) {
adj1ybmzos = ktvbvsiykv_idx_1 ; } } c = c_p [ i + 5 ] ; if ( c != 0 ) {
ktvbvsiykv_idx_1 = inputMFCache [ c + 2 ] ; if ( adj1ybmzos >
ktvbvsiykv_idx_1 ) { adj1ybmzos = ktvbvsiykv_idx_1 ; } } agmrgi4ydo +=
adj1ybmzos ; op4hyjkc4a [ i ] = adj1ybmzos ; } fgif5hwjdq ( rtP .
OutputSamplePoints_Value , b_p , tmp_e ) ; fgif5hwjdq ( rtP .
OutputSamplePoints_Value , c_e , tmp_i ) ; for ( i = 0 ; i < 101 ; i ++ ) {
cnodaj4xbu [ i ] = 0.0 ; outputMFCache [ 3 * i ] = tmp_e [ i ] ;
outputMFCache [ 3 * i + 1 ] = 0.0 ; if ( ( - 2.0 < rtP .
OutputSamplePoints_Value [ i ] ) && ( rtP . OutputSamplePoints_Value [ i ] <
0.0 ) ) { outputMFCache [ 3 * i + 1 ] = ( rtP . OutputSamplePoints_Value [ i
] - - 2.0 ) * 0.5 ; } if ( ( 0.0 < rtP . OutputSamplePoints_Value [ i ] ) &&
( rtP . OutputSamplePoints_Value [ i ] < 2.0 ) ) { outputMFCache [ 3 * i + 1
] = ( 2.0 - rtP . OutputSamplePoints_Value [ i ] ) * 0.5 ; } if ( rtP .
OutputSamplePoints_Value [ i ] == 0.0 ) { outputMFCache [ 3 * i + 1 ] = 1.0 ;
} outputMFCache [ 3 * i + 2 ] = tmp_i [ i ] ; } for ( i = 0 ; i < 5 ; i ++ )
{ ktvbvsiykv_idx_1 = op4hyjkc4a [ i ] ; for ( inputID = 0 ; inputID < 101 ;
inputID ++ ) { adj1ybmzos = cnodaj4xbu [ inputID ] ; ktvbvsiykv_idx_0 =
outputMFCache [ ( 3 * inputID + d [ i ] ) - 1 ] ; if ( ( ktvbvsiykv_idx_0 >
ktvbvsiykv_idx_1 ) || muDoubleScalarIsNaN ( ktvbvsiykv_idx_0 ) ) {
ktvbvsiykv_idx_0 = ktvbvsiykv_idx_1 ; } if ( ( adj1ybmzos < ktvbvsiykv_idx_0
) || ( muDoubleScalarIsNaN ( adj1ybmzos ) && ( ! muDoubleScalarIsNaN (
ktvbvsiykv_idx_0 ) ) ) ) { adj1ybmzos = ktvbvsiykv_idx_0 ; } cnodaj4xbu [
inputID ] = adj1ybmzos ; } } if ( agmrgi4ydo == 0.0 ) { rtB . h5ieqzncec =
0.0 ; } else { agmrgi4ydo = 0.0 ; ktvbvsiykv_idx_0 = 0.0 ; for ( i = 0 ; i <
101 ; i ++ ) { ktvbvsiykv_idx_0 += cnodaj4xbu [ i ] ; } if ( ktvbvsiykv_idx_0
== 0.0 ) { rtB . h5ieqzncec = ( rtP . OutputSamplePoints_Value [ 0 ] + rtP .
OutputSamplePoints_Value [ 100 ] ) / 2.0 ; } else { for ( i = 0 ; i < 101 ; i
++ ) { agmrgi4ydo += rtP . OutputSamplePoints_Value [ i ] * cnodaj4xbu [ i ]
; } rtB . h5ieqzncec = 1.0 / ktvbvsiykv_idx_0 * agmrgi4ydo ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . bwdwg2tsip [ 0 ] = rtB . csmfgwuwmg ;
rtB . bwdwg2tsip [ 1 ] = rtB . l2rabknamr ; } UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { real_T * lastU ; if ( rtDW . o112dnv4au == ( rtInf
) ) { rtDW . o112dnv4au = ssGetT ( rtS ) ; lastU = & rtDW . aj2yaxzolc ; }
else if ( rtDW . nw543yv2lj == ( rtInf ) ) { rtDW . nw543yv2lj = ssGetT ( rtS
) ; lastU = & rtDW . muj3awamps ; } else if ( rtDW . o112dnv4au < rtDW .
nw543yv2lj ) { rtDW . o112dnv4au = ssGetT ( rtS ) ; lastU = & rtDW .
aj2yaxzolc ; } else { rtDW . nw543yv2lj = ssGetT ( rtS ) ; lastU = & rtDW .
muj3awamps ; } * lastU = rtB . csmfgwuwmg ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> dyp5lz2fxt [ 0 ] = 0.0
; _rtXdot -> dyp5lz2fxt [ 0 ] += rtP . TransferFcn_A [ 0 ] * rtX . dyp5lz2fxt
[ 0 ] ; _rtXdot -> dyp5lz2fxt [ 1 ] = 0.0 ; _rtXdot -> dyp5lz2fxt [ 0 ] +=
rtP . TransferFcn_A [ 1 ] * rtX . dyp5lz2fxt [ 1 ] ; _rtXdot -> dyp5lz2fxt [
1 ] += rtX . dyp5lz2fxt [ 0 ] ; _rtXdot -> dyp5lz2fxt [ 0 ] += rtB .
h5ieqzncec ; _rtXdot -> lufhsw5bp3 [ 0 ] = 0.0 ; _rtXdot -> lufhsw5bp3 [ 0 ]
+= rtP . TransferFcn1_A [ 0 ] * rtX . lufhsw5bp3 [ 0 ] ; _rtXdot ->
lufhsw5bp3 [ 1 ] = 0.0 ; _rtXdot -> lufhsw5bp3 [ 0 ] += rtP . TransferFcn1_A
[ 1 ] * rtX . lufhsw5bp3 [ 1 ] ; _rtXdot -> lufhsw5bp3 [ 1 ] += rtX .
lufhsw5bp3 [ 0 ] ; _rtXdot -> lufhsw5bp3 [ 0 ] += rtP . Constant1_Value ; }
void MdlProjection ( void ) { } void MdlTerminate ( void ) { } static void
mr_pendulum_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_pendulum_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_pendulum_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_pendulum_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_pendulum_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_pendulum_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_pendulum_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_pendulum_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_pendulum_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_pendulum_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_pendulum_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_pendulum_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_pendulum_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_pendulum_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_pendulum_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_pendulum_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_pendulum_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_pendulum_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 4 ] = {
"rtDW.o112dnv4au" , "rtDW.aj2yaxzolc" , "rtDW.nw543yv2lj" , "rtDW.muj3awamps"
, } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 4 ,
rtdwDataFieldNames ) ; mr_pendulum_cacheDataAsMxArray ( rtdwData , 0 , 0 , (
const void * ) & ( rtDW . o112dnv4au ) , sizeof ( rtDW . o112dnv4au ) ) ;
mr_pendulum_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. aj2yaxzolc ) , sizeof ( rtDW . aj2yaxzolc ) ) ;
mr_pendulum_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. nw543yv2lj ) , sizeof ( rtDW . nw543yv2lj ) ) ;
mr_pendulum_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. muj3awamps ) , sizeof ( rtDW . muj3awamps ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_pendulum_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_pendulum_restoreDataFromMxArray ( (
void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_pendulum_restoreDataFromMxArray ( ( void * ) & ( rtDW . o112dnv4au ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . o112dnv4au ) ) ;
mr_pendulum_restoreDataFromMxArray ( ( void * ) & ( rtDW . aj2yaxzolc ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . aj2yaxzolc ) ) ;
mr_pendulum_restoreDataFromMxArray ( ( void * ) & ( rtDW . nw543yv2lj ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . nw543yv2lj ) ) ;
mr_pendulum_restoreDataFromMxArray ( ( void * ) & ( rtDW . muj3awamps ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . muj3awamps ) ) ; } } mxArray *
mr_pendulum_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 1 ] = { "Scope" , } ; static const char * blockPath [ 1 ]
= { "pendulum/Scope" , } ; static const int reason [ 1 ] = { 0 , } ; for (
subs [ 0 ] = 0 ; subs [ 0 ] < 1 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
4 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 21 ) ;
ssSetNumBlockIO ( rtS , 6 ) ; ssSetNumBlockParams ( rtS , 113 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 57340289U ) ; ssSetChecksumVal ( rtS , 1 ,
548068569U ) ; ssSetChecksumVal ( rtS , 2 , 332534865U ) ; ssSetChecksumVal (
rtS , 3 , 1656845506U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 26 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
pendulum_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "pendulum" ) ; ssSetPath
( rtS , "pendulum" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 80.0 )
; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 2 , 2 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = { "pendulum/Transfer Fcn" ,
"pendulum/Transfer Fcn1" } ; static const char_T * rt_LoggedStateNames [ ] =
{ "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1
} ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . dyp5lz2fxt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lufhsw5bp3 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 4 ] ;
static real_T absTol [ 4 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static
uint8_T absTolControl [ 4 ] = { 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 4 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 4 ] ; { int i ; for ( i = 0 ; i < 4 ; ++ i )
{ contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [
i ] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.6 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 57340289U ) ; ssSetChecksumVal ( rtS , 1 ,
548068569U ) ; ssSetChecksumVal ( rtS , 2 , 332534865U ) ; ssSetChecksumVal (
rtS , 3 , 1656845506U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 5 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_pendulum_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_pendulum_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_pendulum_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
