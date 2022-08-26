/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sampleLine_initialize.c
 *
 * Code generation for function 'sampleLine_initialize'
 *
 */

/* Include files */
#include "sampleLine_initialize.h"
#include "_coder_sampleLine_mex.h"
#include "rt_nonfinite.h"
#include "sampleLine_data.h"

/* Function Definitions */
void sampleLine_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (sampleLine_initialize.c) */
