/*
 * MATLAB Compiler: 8.2 (R2021a)
 * Date: Sun May 25 12:50:17 2025
 * Arguments: "-B""macro_default""-W""lib:libCalMCNR""-T""link:lib""Cal_MCNR.m"
 */

#ifndef libCalMCNR_h
#define libCalMCNR_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libCalMCNR_C_API 
#define LIB_libCalMCNR_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_libCalMCNR_C_API 
bool MW_CALL_CONV libCalMCNRInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libCalMCNR_C_API 
bool MW_CALL_CONV libCalMCNRInitialize(void);

extern LIB_libCalMCNR_C_API 
void MW_CALL_CONV libCalMCNRTerminate(void);

extern LIB_libCalMCNR_C_API 
void MW_CALL_CONV libCalMCNRPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libCalMCNR_C_API 
bool MW_CALL_CONV mlxCal_MCNR(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libCalMCNR_C_API bool MW_CALL_CONV mlfCal_MCNR(int nargout, mxArray** MCNR, mxArray* src, mxArray* numpixelsx, mxArray* numpixelsy, mxArray* Nz);

#ifdef __cplusplus
}
#endif
/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#endif
