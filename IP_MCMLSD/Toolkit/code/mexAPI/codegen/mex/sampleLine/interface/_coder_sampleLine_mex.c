/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sampleLine_mex.c
 *
 * Code generation for function '_coder_sampleLine_mex'
 *
 */

/* Include files */
#include "_coder_sampleLine_mex.h"
#include "_coder_sampleLine_api.h"
#include "rt_nonfinite.h"
#include "sampleLine_data.h"
#include "sampleLine_initialize.h"
#include "sampleLine_terminate.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&sampleLine_atexit);

  /* Module initialization. */
  sampleLine_initialize();

  /* Dispatch the entry-point. */
  sampleLine_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  sampleLine_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

void sampleLine_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[5])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        10, "sampleLine");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "sampleLine");
  }

  /* Call the function. */
  sampleLine_api(prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/* End of code generation (_coder_sampleLine_mex.c) */
