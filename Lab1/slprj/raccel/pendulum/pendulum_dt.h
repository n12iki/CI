#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"struct_kOvam4EZKqTh3kXxqfWvz" , 15 , 128 } , {
"struct_RCP1oovUDF2zF6C9vcJmtG" , 16 , 48 } , {
"struct_OTlcYhhT3UxB0PEhAC2ANE" , 17 , 152 } , {
"struct_nDiNttezQ8pHMZv76leKsH" , 18 , 56 } , {
"struct_6VzYiVW2hAWQCI9jAYOVeF" , 19 , 176 } , {
"struct_agZOUJXeJgTB5OyDqBavsH" , 20 , 1656 } , { "uint64_T" , 21 , 8 } , {
"int64_T" , 22 , 8 } , { "char_T" , 23 , 8 } , { "uchar_T" , 24 , 8 } , {
"time_T" , 25 , 8 } } ; static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T
) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof (
int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) ,
sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof (
pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T ) , sizeof (
int32_T ) , sizeof ( struct_kOvam4EZKqTh3kXxqfWvz ) , sizeof (
struct_RCP1oovUDF2zF6C9vcJmtG ) , sizeof ( struct_OTlcYhhT3UxB0PEhAC2ANE ) ,
sizeof ( struct_nDiNttezQ8pHMZv76leKsH ) , sizeof (
struct_6VzYiVW2hAWQCI9jAYOVeF ) , sizeof ( struct_agZOUJXeJgTB5OyDqBavsH ) ,
sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( char_T ) , sizeof (
uchar_T ) , sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] =
{ "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "physical_connection" ,
"struct_kOvam4EZKqTh3kXxqfWvz" , "struct_RCP1oovUDF2zF6C9vcJmtG" ,
"struct_OTlcYhhT3UxB0PEhAC2ANE" , "struct_nDiNttezQ8pHMZv76leKsH" ,
"struct_6VzYiVW2hAWQCI9jAYOVeF" , "struct_agZOUJXeJgTB5OyDqBavsH" ,
"uint64_T" , "int64_T" , "char_T" , "uchar_T" , "time_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . dr4tmwxyco
) , 0 , 0 , 7 } , { ( char_T * ) ( & rtDW . o112dnv4au ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtDW . lggyldcif4 . LoggedData ) , 11 , 0 , 1 } } ; static
DataTypeTransitionTable rtBTransTable = { 3U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
OutputSamplePoints_Value [ 0 ] ) , 0 , 0 , 113 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
