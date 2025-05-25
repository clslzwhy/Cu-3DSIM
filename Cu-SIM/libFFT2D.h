/*
 * MATLAB Compiler: 8.2 (R2021a)
 * Date: Mon May 26 03:17:54 2025
 * Arguments: "-B""macro_default""-W""lib:libFFT2D""-T""link:lib""Mat_FFT2D_1.m"
 */

#ifndef libFFT2D_h
#define libFFT2D_h 1

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
#ifndef LIB_libFFT2D_C_API 
#define LIB_libFFT2D_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_libFFT2D_C_API 
bool MW_CALL_CONV libFFT2DInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libFFT2D_C_API 
bool MW_CALL_CONV libFFT2DInitialize(void);

extern LIB_libFFT2D_C_API 
void MW_CALL_CONV libFFT2DTerminate(void);

extern LIB_libFFT2D_C_API 
void MW_CALL_CONV libFFT2DPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libFFT2D_C_API 
bool MW_CALL_CONV mlxMat_FFT2D_1(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libFFT2D_C_API bool MW_CALL_CONV mlfMat_FFT2D_1(int nargout, mxArray** out_real, mxArray** out_imag, mxArray* in_real, mxArray* in_imag);

#ifdef __cplusplus
}
#endif
/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#endif
