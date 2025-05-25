/*
 * MATLAB Compiler: 8.2 (R2021a)
 * Date: Mon May 26 06:03:03 2025
 * Arguments: "-B""macro_default""-W""lib:libGenHilo""-T""link:lib""GenHilo.m"
 */

#ifndef libGenHilo_h
#define libGenHilo_h 1

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
#ifndef LIB_libGenHilo_C_API 
#define LIB_libGenHilo_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_libGenHilo_C_API 
bool MW_CALL_CONV libGenHiloInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libGenHilo_C_API 
bool MW_CALL_CONV libGenHiloInitialize(void);

extern LIB_libGenHilo_C_API 
void MW_CALL_CONV libGenHiloTerminate(void);

extern LIB_libGenHilo_C_API 
void MW_CALL_CONV libGenHiloPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libGenHilo_C_API 
bool MW_CALL_CONV mlxGenHilo(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_libGenHilo_C_API bool MW_CALL_CONV mlfGenHilo(int nargout, mxArray** Hilo, mxArray* allimages_in0, mxArray* numpixelsx1, mxArray* Nz, mxArray* Na, mxArray* emwavelength, mxArray* rawpixelsize);

#ifdef __cplusplus
}
#endif
/* C INTERFACE -- MLF WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#endif
