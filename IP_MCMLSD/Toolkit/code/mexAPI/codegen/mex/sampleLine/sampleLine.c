/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sampleLine.c
 *
 * Code generation for function 'sampleLine'
 *
 */

/* Include files */
#include "sampleLine.h"
#include "ceil.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "floor.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "sampleLine_data.h"
#include "sampleLine_emxutil.h"
#include "sampleLine_types.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 31,    /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 37,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 38,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 39,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 43,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 47,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 51,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 52,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 56,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 60,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 61,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 63,  /* lineNo */
  "sampleLine",                        /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 45,  /* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\mpower.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 70,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 28,  /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 103, /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 14,  /* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 31,  /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 67,  /* lineNo */
  "minimum2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 64,  /* lineNo */
  "binaryMinOrMax",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\binaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 66,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 174, /* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 14, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 29, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 58, /* lineNo */
  "maximum2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 22, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 102,/* lineNo */
  "cat_impl",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 40,  /* lineNo */
  13,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  25,                                  /* colNo */
  "yu",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  31,                                  /* colNo */
  "yl",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  35,                                  /* colNo */
  "yl",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  41,                                  /* colNo */
  "yu",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  25,                                  /* colNo */
  "xu",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  31,                                  /* colNo */
  "xl",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  35,                                  /* colNo */
  "xl",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  41,                                  /* colNo */
  "xu",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 42,    /* lineNo */
  12,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  12,                                  /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 42,  /* lineNo */
  16,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  16,                                  /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 56,  /* lineNo */
  12,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  12,                                  /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 56,  /* lineNo */
  16,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  16,                                  /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  56,                                  /* lineNo */
  9,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  9,                                   /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 60,  /* lineNo */
  11,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  11,                                  /* colNo */
  "xp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 43,  /* lineNo */
  12,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  12,                                  /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 43,  /* lineNo */
  16,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  16,                                  /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  43,                                  /* lineNo */
  9,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtDCInfo h_emlrtDCI = { 55,  /* lineNo */
  12,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  12,                                  /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 55,  /* lineNo */
  16,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  16,                                  /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  9,                                   /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 61,  /* lineNo */
  11,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  11,                                  /* colNo */
  "yp",                                /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 283,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtDCInfo k_emlrtDCI = { 33,  /* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 33,  /* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 33,  /* lineNo */
  22,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "x",                                 /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  9,                                   /* colNo */
  "y",                                 /* aName */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 33,/* lineNo */
  22,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 47,/* lineNo */
  5,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 38,/* lineNo */
  27,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 51,/* lineNo */
  26,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 46,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 39,/* lineNo */
  23,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 52,/* lineNo */
  24,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 60,/* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 61,/* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 63,/* lineNo */
  1,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 43,/* lineNo */
  32,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 56,/* lineNo */
  32,                                  /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 51,/* lineNo */
  5,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "sampleLine",                        /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\sampleLine.m"/* pName */
};

/* Function Definitions */
void sampleLine(const emlrtStack *sp, real_T rho, real_T theta, real_T m, real_T
                n, const real_T pp[2], emxArray_real_T *L)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_real_T *varargin_2;
  emxArray_real_T *xl;
  emxArray_real_T *xp;
  emxArray_real_T *xu;
  emxArray_real_T *y;
  emxArray_real_T *yp;
  real_T a_tmp;
  real_T b;
  real_T bottom;
  real_T d;
  real_T idx;
  real_T maxpts;
  real_T right;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &xp, 1, &h_emlrtRTEI, true);

  /* Returns locations of line samples together with the locations */
  /* of the associated pixels in the image. */
  /* (rho, theta) represents the line as per Fig. 1 of Tal (2012): */
  /* rho = x*cos(theta) + y*sin(theta) <--> ax + by + c = 0 where */
  /* a = cos(theta), b = sin(theta), c = -rho. */
  /* pp is the principal point, in pixels. */
  /* (m, n) is the width and height of the image in pixels. */
  /* The returned matrix L is N x 4, where N is the number of */
  /* samples on the line.  The 4 columns represent (x,y,xp,yp)  */
  /* where (x,y) indicates the real-valued location of the line */
  /* sample and (xp,yp) represents the integer-valued location */
  /* of the associated pixel.  Note that the y index increases down. */
  /* Translate to standard representation of line */
  a_tmp = muDoubleScalarCos(theta);
  b = muDoubleScalarSin(theta);

  /* Location of centre of image */
  /* Find image bounds */
  right = m - pp[0];
  bottom = n - pp[1];

  /* Identify pixels within 2 pixels of line */
  st.site = &emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  d = m * m + n * n;
  st.site = &emlrtRSI;
  if (d < 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  d = muDoubleScalarSqrt(d);
  maxpts = muDoubleScalarRound(5.0 * d);

  /* Pre-allocate for efficiency */
  if (!(maxpts >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxpts, &l_emlrtDCI, sp);
  }

  if (maxpts != (int32_T)maxpts) {
    emlrtIntegerCheckR2012b(maxpts, &k_emlrtDCI, sp);
  }

  i = xp->size[0];
  xp->size[0] = (int32_T)maxpts;
  emxEnsureCapacity_real_T(sp, xp, i, &h_emlrtRTEI);
  if (maxpts != (int32_T)maxpts) {
    emlrtIntegerCheckR2012b(maxpts, &k_emlrtDCI, sp);
  }

  loop_ub = (int32_T)maxpts;
  for (i = 0; i < loop_ub; i++) {
    xp->data[i] = 0.0;
  }

  emxInit_real_T(sp, &yp, 1, &i_emlrtRTEI, true);
  if (maxpts != (int32_T)maxpts) {
    emlrtIntegerCheckR2012b(maxpts, &m_emlrtDCI, sp);
  }

  i = yp->size[0];
  loop_ub = (int32_T)maxpts;
  yp->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, yp, i, &i_emlrtRTEI);
  if (loop_ub != (int32_T)maxpts) {
    emlrtIntegerCheckR2012b(maxpts, &m_emlrtDCI, sp);
  }

  for (i = 0; i < loop_ub; i++) {
    yp->data[i] = 0.0;
  }

  idx = 1.0;

  /* Closer to horizontal - march along x. */
  emxInit_real_T(sp, &y, 2, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &xu, 2, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &xl, 2, &w_emlrtRTEI, true);
  emxInit_real_T(sp, &varargin_2, 2, &m_emlrtRTEI, true);
  if ((theta > 0.78539816339744828) && (theta < 2.3561944901923448)) {
    st.site = &b_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if (muDoubleScalarIsNaN(1.0 - pp[0]) || muDoubleScalarIsNaN(right)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &j_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (right < 1.0 - pp[0]) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if ((muDoubleScalarIsInf(1.0 - pp[0]) || muDoubleScalarIsInf(right)) &&
               (1.0 - pp[0] == right)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &j_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (muDoubleScalarFloor(1.0 - pp[0]) == 1.0 - pp[0]) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor(right - (1.0 - pp[0]));
      y->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &j_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        y->data[i] = (1.0 - pp[0]) + (real_T)i;
      }
    } else {
      c_st.site = &p_emlrtRSI;
      eml_float_colon(&c_st, 1.0 - pp[0], right, y);
    }

    st.site = &c_emlrtRSI;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = y->size[1];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &l_emlrtRTEI);
    loop_ub = y->size[0] * y->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_2->data[i] = ((rho + 2.0) - y->data[i] * a_tmp) / b;
    }

    b_st.site = &t_emlrtRSI;
    c_st.site = &u_emlrtRSI;
    d_st.site = &v_emlrtRSI;
    e_st.site = &w_emlrtRSI;
    i = xu->size[0] * xu->size[1];
    xu->size[0] = 1;
    xu->size[1] = varargin_2->size[1];
    emxEnsureCapacity_real_T(&e_st, xu, i, &n_emlrtRTEI);
    f_st.site = &x_emlrtRSI;
    nx = varargin_2->size[1];
    g_st.site = &y_emlrtRSI;
    if ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646)) {
      h_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      xu->data[loop_ub] = muDoubleScalarMin(bottom, varargin_2->data[loop_ub]);
    }

    st.site = &c_emlrtRSI;
    b_floor(&st, xu);
    st.site = &d_emlrtRSI;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = y->size[1];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &o_emlrtRTEI);
    loop_ub = y->size[0] * y->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_2->data[i] = ((rho - 2.0) - y->data[i] * a_tmp) / b;
    }

    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    d_st.site = &eb_emlrtRSI;
    e_st.site = &w_emlrtRSI;
    i = xl->size[0] * xl->size[1];
    xl->size[0] = 1;
    xl->size[1] = varargin_2->size[1];
    emxEnsureCapacity_real_T(&e_st, xl, i, &n_emlrtRTEI);
    f_st.site = &x_emlrtRSI;
    nx = varargin_2->size[1];
    g_st.site = &y_emlrtRSI;
    if ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646)) {
      h_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      xl->data[loop_ub] = muDoubleScalarMax(1.0 - pp[1], varargin_2->
        data[loop_ub]);
    }

    st.site = &d_emlrtRSI;
    b_ceil(&st, xl);
    i = (int32_T)m;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, m, mxDOUBLE_CLASS, (int32_T)m,
      &emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > xu->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xu->size[1], &emlrtBCI, sp);
      }

      if (i1 > xl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xl->size[1], &b_emlrtBCI, sp);
      }

      maxpts = xu->data[b_i] - xl->data[b_i];
      d = idx + muDoubleScalarMax(0.0, maxpts + 1.0);
      if (idx > d - 1.0) {
        nx = -1;
        i2 = 0;
      } else {
        if (idx != (int32_T)muDoubleScalarFloor(idx)) {
          emlrtIntegerCheckR2012b(idx, &emlrtDCI, sp);
        }

        if (((int32_T)idx < 1) || ((int32_T)idx > xp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, xp->size[0],
            &i_emlrtBCI, sp);
        }

        nx = (int32_T)idx - 2;
        if (d - 1.0 != (int32_T)muDoubleScalarFloor(d - 1.0)) {
          emlrtIntegerCheckR2012b(d - 1.0, &b_emlrtDCI, sp);
        }

        if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > xp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, xp->size[0],
            &j_emlrtBCI, sp);
        }

        i2 = (int32_T)(d - 1.0);
      }

      loop_ub = (i2 - nx) - 1;
      for (i2 = 0; i2 < loop_ub; i2++) {
        if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > y->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, y->size[1],
            &u_emlrtBCI, sp);
        }

        xp->data[(nx + i2) + 1] = y->data[b_i];
      }

      if (idx > d - 1.0) {
        nx = 0;
        i2 = 0;
      } else {
        if (idx != (int32_T)muDoubleScalarFloor(idx)) {
          emlrtIntegerCheckR2012b(idx, &f_emlrtDCI, sp);
        }

        if (((int32_T)idx < 1) || ((int32_T)idx > yp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, yp->size[0],
            &o_emlrtBCI, sp);
        }

        nx = (int32_T)idx - 1;
        if (d - 1.0 != (int32_T)muDoubleScalarFloor(d - 1.0)) {
          emlrtIntegerCheckR2012b(d - 1.0, &g_emlrtDCI, sp);
        }

        if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > yp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, yp->size[0],
            &p_emlrtBCI, sp);
        }

        i2 = (int32_T)(d - 1.0);
      }

      st.site = &e_emlrtRSI;
      if (i1 > xl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xl->size[1], &c_emlrtBCI, &st);
      }

      if (i1 > xu->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xu->size[1], &d_emlrtBCI, &st);
      }

      b_st.site = &o_emlrtRSI;
      if (muDoubleScalarIsNaN(xl->data[b_i]) || muDoubleScalarIsNaN(xu->data[b_i]))
      {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &t_emlrtRTEI);
        varargin_2->data[0] = rtNaN;
      } else if (xu->data[b_i] < xl->data[b_i]) {
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 0;
      } else if ((muDoubleScalarIsInf(xl->data[b_i]) || muDoubleScalarIsInf
                  (xu->data[b_i])) && (xl->data[b_i] == xu->data[b_i])) {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &t_emlrtRTEI);
        varargin_2->data[0] = rtNaN;
      } else if (muDoubleScalarFloor(xl->data[b_i]) == xl->data[b_i]) {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        loop_ub = (int32_T)muDoubleScalarFloor(maxpts);
        varargin_2->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &t_emlrtRTEI);
        for (i1 = 0; i1 <= loop_ub; i1++) {
          varargin_2->data[i1] = xl->data[b_i] + (real_T)i1;
        }
      } else {
        c_st.site = &p_emlrtRSI;
        eml_float_colon(&c_st, xl->data[b_i], xu->data[b_i], varargin_2);
      }

      i1 = i2 - nx;
      if (i1 != varargin_2->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(i1, varargin_2->size[1], &b_emlrtECI, sp);
      }

      loop_ub = varargin_2->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        yp->data[nx + i1] = varargin_2->data[i1];
      }

      idx = d;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } else {
    /* Closer to vertical - march along y */
    st.site = &f_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    if (muDoubleScalarIsNaN(1.0 - pp[1]) || muDoubleScalarIsNaN(bottom)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &k_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (bottom < 1.0 - pp[1]) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if ((muDoubleScalarIsInf(1.0 - pp[1]) || muDoubleScalarIsInf(bottom))
               && (1.0 - pp[1] == bottom)) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &k_emlrtRTEI);
      y->data[0] = rtNaN;
    } else if (muDoubleScalarFloor(1.0 - pp[1]) == 1.0 - pp[1]) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      loop_ub = (int32_T)muDoubleScalarFloor(bottom - (1.0 - pp[1]));
      y->size[1] = loop_ub + 1;
      emxEnsureCapacity_real_T(&b_st, y, i, &k_emlrtRTEI);
      for (i = 0; i <= loop_ub; i++) {
        y->data[i] = (1.0 - pp[1]) + (real_T)i;
      }
    } else {
      c_st.site = &p_emlrtRSI;
      eml_float_colon(&c_st, 1.0 - pp[1], bottom, y);
    }

    /* if theta<pi/2, increasing rho increases x.   */
    /* Otherwise, decreasing rho increases x. */
    maxpts = muDoubleScalarSign(a_tmp);
    st.site = &g_emlrtRSI;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = y->size[1];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &m_emlrtRTEI);
    bottom = rho + 2.0 * maxpts;
    loop_ub = y->size[0] * y->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_2->data[i] = (bottom - y->data[i] * b) / a_tmp;
    }

    b_st.site = &t_emlrtRSI;
    c_st.site = &u_emlrtRSI;
    d_st.site = &v_emlrtRSI;
    e_st.site = &w_emlrtRSI;
    i = xu->size[0] * xu->size[1];
    xu->size[0] = 1;
    xu->size[1] = varargin_2->size[1];
    emxEnsureCapacity_real_T(&e_st, xu, i, &n_emlrtRTEI);
    f_st.site = &x_emlrtRSI;
    nx = varargin_2->size[1];
    g_st.site = &y_emlrtRSI;
    if ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646)) {
      h_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      xu->data[loop_ub] = muDoubleScalarMin(right, varargin_2->data[loop_ub]);
    }

    st.site = &g_emlrtRSI;
    b_floor(&st, xu);
    st.site = &h_emlrtRSI;
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = 1;
    varargin_2->size[1] = y->size[1];
    emxEnsureCapacity_real_T(&st, varargin_2, i, &p_emlrtRTEI);
    bottom = rho - 2.0 * maxpts;
    loop_ub = y->size[0] * y->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_2->data[i] = (bottom - y->data[i] * b) / a_tmp;
    }

    b_st.site = &cb_emlrtRSI;
    c_st.site = &db_emlrtRSI;
    d_st.site = &eb_emlrtRSI;
    e_st.site = &w_emlrtRSI;
    i = xl->size[0] * xl->size[1];
    xl->size[0] = 1;
    xl->size[1] = varargin_2->size[1];
    emxEnsureCapacity_real_T(&e_st, xl, i, &n_emlrtRTEI);
    f_st.site = &x_emlrtRSI;
    nx = varargin_2->size[1];
    g_st.site = &y_emlrtRSI;
    if ((1 <= varargin_2->size[1]) && (varargin_2->size[1] > 2147483646)) {
      h_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&h_st);
    }

    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      xl->data[loop_ub] = muDoubleScalarMax(1.0 - pp[0], varargin_2->
        data[loop_ub]);
    }

    st.site = &h_emlrtRSI;
    b_ceil(&st, xl);
    i = (int32_T)n;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
      &b_emlrtRTEI, sp);
    for (b_i = 0; b_i < i; b_i++) {
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > xu->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xu->size[1], &e_emlrtBCI, sp);
      }

      if (i1 > xl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xl->size[1], &f_emlrtBCI, sp);
      }

      maxpts = xu->data[b_i] - xl->data[b_i];
      d = idx + muDoubleScalarMax(0.0, maxpts + 1.0);
      if (idx > d - 1.0) {
        nx = -1;
        i2 = 0;
      } else {
        if (idx != (int32_T)muDoubleScalarFloor(idx)) {
          emlrtIntegerCheckR2012b(idx, &h_emlrtDCI, sp);
        }

        if (((int32_T)idx < 1) || ((int32_T)idx > yp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, yp->size[0],
            &q_emlrtBCI, sp);
        }

        nx = (int32_T)idx - 2;
        if (d - 1.0 != (int32_T)muDoubleScalarFloor(d - 1.0)) {
          emlrtIntegerCheckR2012b(d - 1.0, &i_emlrtDCI, sp);
        }

        if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > yp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, yp->size[0],
            &r_emlrtBCI, sp);
        }

        i2 = (int32_T)(d - 1.0);
      }

      loop_ub = (i2 - nx) - 1;
      for (i2 = 0; i2 < loop_ub; i2++) {
        if (((int32_T)(b_i + 1U) < 1) || ((int32_T)(b_i + 1U) > y->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i + 1U), 1, y->size[1],
            &v_emlrtBCI, sp);
        }

        yp->data[(nx + i2) + 1] = y->data[b_i];
      }

      if (idx > d - 1.0) {
        nx = 0;
        i2 = 0;
      } else {
        if (idx != (int32_T)muDoubleScalarFloor(idx)) {
          emlrtIntegerCheckR2012b(idx, &c_emlrtDCI, sp);
        }

        if (((int32_T)idx < 1) || ((int32_T)idx > xp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx, 1, xp->size[0],
            &k_emlrtBCI, sp);
        }

        nx = (int32_T)idx - 1;
        if (d - 1.0 != (int32_T)muDoubleScalarFloor(d - 1.0)) {
          emlrtIntegerCheckR2012b(d - 1.0, &d_emlrtDCI, sp);
        }

        if (((int32_T)(d - 1.0) < 1) || ((int32_T)(d - 1.0) > xp->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(d - 1.0), 1, xp->size[0],
            &l_emlrtBCI, sp);
        }

        i2 = (int32_T)(d - 1.0);
      }

      st.site = &i_emlrtRSI;
      if (i1 > xl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xl->size[1], &g_emlrtBCI, &st);
      }

      if (i1 > xu->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, xu->size[1], &h_emlrtBCI, &st);
      }

      b_st.site = &o_emlrtRSI;
      if (muDoubleScalarIsNaN(xl->data[b_i]) || muDoubleScalarIsNaN(xu->data[b_i]))
      {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &u_emlrtRTEI);
        varargin_2->data[0] = rtNaN;
      } else if (xu->data[b_i] < xl->data[b_i]) {
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 0;
      } else if ((muDoubleScalarIsInf(xl->data[b_i]) || muDoubleScalarIsInf
                  (xu->data[b_i])) && (xl->data[b_i] == xu->data[b_i])) {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        varargin_2->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &u_emlrtRTEI);
        varargin_2->data[0] = rtNaN;
      } else if (muDoubleScalarFloor(xl->data[b_i]) == xl->data[b_i]) {
        i1 = varargin_2->size[0] * varargin_2->size[1];
        varargin_2->size[0] = 1;
        loop_ub = (int32_T)muDoubleScalarFloor(maxpts);
        varargin_2->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, varargin_2, i1, &u_emlrtRTEI);
        for (i1 = 0; i1 <= loop_ub; i1++) {
          varargin_2->data[i1] = xl->data[b_i] + (real_T)i1;
        }
      } else {
        c_st.site = &p_emlrtRSI;
        eml_float_colon(&c_st, xl->data[b_i], xu->data[b_i], varargin_2);
      }

      i1 = i2 - nx;
      if (i1 != varargin_2->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(i1, varargin_2->size[1], &emlrtECI, sp);
      }

      loop_ub = varargin_2->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        xp->data[nx + i1] = varargin_2->data[i1];
      }

      idx = d;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emxFree_real_T(&varargin_2);
  emxFree_real_T(&xl);
  emxFree_real_T(&xu);
  emxFree_real_T(&y);
  if (1.0 > idx - 1.0) {
    loop_ub = 0;
  } else {
    if (1 > xp->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, xp->size[0], &m_emlrtBCI, sp);
    }

    if (idx - 1.0 != (int32_T)muDoubleScalarFloor(idx - 1.0)) {
      emlrtIntegerCheckR2012b(idx - 1.0, &e_emlrtDCI, sp);
    }

    if (((int32_T)(idx - 1.0) < 1) || ((int32_T)(idx - 1.0) > xp->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(idx - 1.0), 1, xp->size[0],
        &n_emlrtBCI, sp);
    }

    loop_ub = (int32_T)(idx - 1.0);
  }

  iv[0] = 1;
  iv[1] = loop_ub;
  st.site = &j_emlrtRSI;
  indexShapeCheck(&st, xp->size[0], iv);
  i = xp->size[0];
  xp->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, xp, i, &q_emlrtRTEI);
  if (1.0 > idx - 1.0) {
    nx = 0;
  } else {
    if (1 > yp->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, yp->size[0], &s_emlrtBCI, sp);
    }

    if (idx - 1.0 != (int32_T)muDoubleScalarFloor(idx - 1.0)) {
      emlrtIntegerCheckR2012b(idx - 1.0, &j_emlrtDCI, sp);
    }

    if (((int32_T)(idx - 1.0) < 1) || ((int32_T)(idx - 1.0) > yp->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(idx - 1.0), 1, yp->size[0],
        &t_emlrtBCI, sp);
    }

    nx = (int32_T)(idx - 1.0);
  }

  iv[0] = 1;
  iv[1] = nx;
  st.site = &k_emlrtRSI;
  indexShapeCheck(&st, yp->size[0], iv);
  i = yp->size[0];
  yp->size[0] = nx;
  emxEnsureCapacity_real_T(sp, yp, i, &r_emlrtRTEI);
  st.site = &l_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (nx != loop_ub) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = L->size[0] * L->size[1];
  L->size[0] = loop_ub;
  L->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, L, i, &s_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    L->data[i] = xp->data[i];
  }

  emxFree_real_T(&xp);
  for (i = 0; i < nx; i++) {
    L->data[i + L->size[0]] = yp->data[i];
  }

  emxFree_real_T(&yp);

  /*  %Find orthogonal projections to line */
  /*  x = b*(b*xp-a*yp)-a*c; */
  /*  y = a*(-b*xp+a*yp)-b*c; */
  /*   */
  /*  L = [x,y,xp,yp]; */
  /*  %Sort line samples */
  /*  if theta > pi/4 & theta < 3*pi/4 */
  /*      [x,idx] = sort(x); */
  /*  else */
  /*      [y,idx] = sort(y); */
  /*  end   */
  /*  L = L(idx,:); */
  /*  npts = size(L,1); */
  /*  npts; */
  /*  figure; */
  /*  eps = endpoints(rho,theta,left,right,top,bottom); */
  /*  plot(eps(:,1),eps(:,2),'r'); */
  /*  hold on; */
  /*  plot(xp,yp,'.'); */
  /*  axis ij; */
  /*  axis equal; */
  /*  axis([left,right,top,bottom]); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sampleLine.c) */
