#ifndef RTW_HEADER_pendulum_types_h_
#define RTW_HEADER_pendulum_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_kOvam4EZKqTh3kXxqfWvz_
#define DEFINED_TYPEDEF_FOR_struct_kOvam4EZKqTh3kXxqfWvz_
typedef struct { uint8_T SimulinkDiagnostic ; uint8_T Model [ 49 ] ; uint8_T
Block [ 72 ] ; uint8_T OutOfRangeInputValue ; uint8_T NoRuleFired ; uint8_T
EmptyOutputFuzzySet ; uint8_T sl_padding0 [ 3 ] ; }
struct_kOvam4EZKqTh3kXxqfWvz ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
#define DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
typedef struct { uint8_T type [ 5 ] ; uint8_T sl_padding0 [ 3 ] ; int32_T
origTypeLength ; uint8_T sl_padding1 [ 4 ] ; real_T params [ 3 ] ; int32_T
origParamLength ; uint8_T sl_padding2 [ 4 ] ; } struct_RCP1oovUDF2zF6C9vcJmtG
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_
#define DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_
typedef struct { struct_RCP1oovUDF2zF6C9vcJmtG mf [ 3 ] ; int32_T origNumMF ;
uint8_T sl_padding0 [ 4 ] ; } struct_OTlcYhhT3UxB0PEhAC2ANE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_
#define DEFINED_TYPEDEF_FOR_struct_nDiNttezQ8pHMZv76leKsH_
typedef struct { uint8_T type [ 6 ] ; uint8_T sl_padding0 [ 2 ] ; int32_T
origTypeLength ; uint8_T sl_padding1 [ 4 ] ; real_T params [ 4 ] ; int32_T
origParamLength ; uint8_T sl_padding2 [ 4 ] ; } struct_nDiNttezQ8pHMZv76leKsH
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_6VzYiVW2hAWQCI9jAYOVeF_
#define DEFINED_TYPEDEF_FOR_struct_6VzYiVW2hAWQCI9jAYOVeF_
typedef struct { struct_nDiNttezQ8pHMZv76leKsH mf [ 3 ] ; int32_T origNumMF ;
uint8_T sl_padding0 [ 4 ] ; } struct_6VzYiVW2hAWQCI9jAYOVeF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_agZOUJXeJgTB5OyDqBavsH_
#define DEFINED_TYPEDEF_FOR_struct_agZOUJXeJgTB5OyDqBavsH_
typedef struct { uint8_T type [ 7 ] ; uint8_T andMethod [ 3 ] ; uint8_T
orMethod [ 3 ] ; uint8_T defuzzMethod [ 8 ] ; uint8_T impMethod [ 3 ] ;
uint8_T aggMethod [ 3 ] ; uint8_T sl_padding0 [ 5 ] ; real_T inputRange [ 4 ]
; real_T outputRange [ 2 ] ; struct_OTlcYhhT3UxB0PEhAC2ANE inputMF [ 2 ] ;
struct_6VzYiVW2hAWQCI9jAYOVeF outputMF ; real_T antecedent [ 10 ] ; real_T
consequent [ 5 ] ; real_T connection [ 5 ] ; real_T weight [ 5 ] ; int32_T
numSamples ; int32_T numInputs ; int32_T numOutputs ; int32_T numRules ;
int32_T numInputMFs [ 2 ] ; int32_T numCumInputMFs [ 2 ] ; int32_T
numOutputMFs ; int32_T numCumOutputMFs ; real_T outputSamplePoints [ 101 ] ;
int32_T orrSize [ 2 ] ; int32_T aggSize [ 2 ] ; int32_T irrSize [ 2 ] ;
int32_T rfsSize [ 2 ] ; int32_T sumSize [ 2 ] ; int32_T inputFuzzySetType ;
uint8_T sl_padding1 [ 4 ] ; } struct_agZOUJXeJgTB5OyDqBavsH ;
#endif
typedef struct P_ P ;
#endif
