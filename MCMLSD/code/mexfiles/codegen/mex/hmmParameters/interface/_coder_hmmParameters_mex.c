/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_hmmParameters_mex.c
 *
 * Code generation for function '_coder_hmmParameters_mex'
 *
 */

/* Include files */
#include "_coder_hmmParameters_mex.h"
#include "_coder_hmmParameters_api.h"
#include "hmmParameters_data.h"
#include "hmmParameters_initialize.h"
#include "hmmParameters_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void hmmParameters_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs,
  const mxArray *prhs[20])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[6];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 20) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 20, 4,
                        13, "hmmParameters");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "hmmParameters");
  }

  /* Call the function. */
  hmmParameters_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&hmmParameters_atexit);

  /* Module initialization. */
  hmmParameters_initialize();

  /* Dispatch the entry-point. */
  hmmParameters_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  hmmParameters_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_hmmParameters_mex.c) */
