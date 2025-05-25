/*
 * MATLAB Compiler: 8.2 (R2021a)
 * Date: Sun May 25 17:39:29 2025
 * Arguments:
 * "-B""macro_default""-W""lib:libMatdeconvlucy""-T""link:lib""Matdeconvlucy.m"
 */

#ifndef libMatdeconvlucy_h
#define libMatdeconvlucy_h 1

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
#ifndef LIB_libMatdeconvlucy_C_API 
#define LIB_libMatdeconvlucy_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_libMatdeconvlucy_C_API 
bool MW_CALL_CONV libMatdeconvlucyInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libMatdeconvlucy_C_API 
bool MW_CALL_CONV libMatdeconvlucyInitialize(void);

extern LIB_libMatdeconvlucy_C_API 
void MW_CALL_CONV libMatdeconvlucyTerminate(void);

extern LIB_libMatdeconvlucy_C_API 
void MW_CALL_CONV libMatdeconvlucyPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libMatdeconvlucy_C_API 
bool MW_CALL_CONV mlxMatdeconvlucy(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libMatdeconvlucy_C_API bool MW_CALL_CONV mlfMatdeconvlucy(int nargout, mxArray** dst, mxArray** Test, mxArray* src, mxArray* psf, mxArray* numpixelsx, mxArray* numpixelsy, mxArray* Nz);

#ifdef __cplusplus
}
#endif
/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#endif
