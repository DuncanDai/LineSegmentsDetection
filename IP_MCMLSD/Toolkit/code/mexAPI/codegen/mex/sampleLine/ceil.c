/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ceil.c
 *
 * Code generation for function 'ceil'
 *
 */

/* Include files */
#include "ceil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sampleLine_data.h"
#include "sampleLine_types.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 11, /* lineNo */
  "ceil",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\ceil.m"/* pathName */
};

/* Function Definitions */
void b_ceil(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1];
  b_st.site = &bb_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    x->data[k] = muDoubleScalarCeil(x->data[k]);
  }
}

/* End of code generation (ceil.c) */
