/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * hmmParameters.c
 *
 * Code generation for function 'hmmParameters'
 *
 */

/* Include files */
#include "hmmParameters.h"
#include "hmmParameters_data.h"
#include "hmmParameters_emxutil.h"
#include "hmmParameters_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 13,    /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 24,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 25,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 46,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 47,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 69,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 80,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 81,  /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 109, /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 110, /* lineNo */
  "hmmParameters",                     /* fcnName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  8,                                   /* colNo */
  "y_h",                               /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  35,                                  /* colNo */
  "distances",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  33,                                  /* colNo */
  "ang_dev",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  14,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  25,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  7,                                   /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  35,                                  /* colNo */
  "distances",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  14,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  25,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  7,                                   /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  12,                                  /* colNo */
  "y_h",                               /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  16,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  16,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  16,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  16,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  18,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  15,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  54,                                  /* lineNo */
  15,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  37,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  29,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  19,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  113,                                 /* lineNo */
  18,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  114,                                 /* lineNo */
  37,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  29,                                  /* colNo */
  "obslik",                            /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  19,                                  /* colNo */
  "alpha_t",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  29,                                  /* colNo */
  "distances",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  29,                                  /* colNo */
  "distances",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  29,                                  /* colNo */
  "ang_dev",                           /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  48,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  100,                                 /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  10,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  25,                                  /* colNo */
  "aux_table",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  48,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  100,                                 /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  48,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  101,                                 /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  10,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  10,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "aux_table",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  110,                                 /* lineNo */
  25,                                  /* colNo */
  "aux_table",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  48,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  101,                                 /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  115,                                 /* lineNo */
  9,                                   /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  116,                                 /* lineNo */
  71,                                  /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  10,                                  /* colNo */
  "DP_table",                          /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  25,                                  /* colNo */
  "aux_table",                         /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  88,                                  /* lineNo */
  9,                                   /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  89,                                  /* lineNo */
  71,                                  /* colNo */
  "z",                                 /* aName */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 6, /* lineNo */
  1,                                   /* colNo */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 7, /* lineNo */
  1,                                   /* colNo */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 10,/* lineNo */
  1,                                   /* colNo */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "hmmParameters",                     /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\hmmParameters.m"/* pName */
};

/* Function Definitions */
void hmmParameters(const emlrtStack *sp, const real_T exist_edge_on[40], const
                   real_T exist_edge_off[40], const real_T ang_dev_on[181],
                   const real_T ang_dev_off[181], const emxArray_real_T
                   *node_idx, const real_T Psi_t[4], const real_T pi_var[2],
                   const emxArray_real_T *y_h, const emxArray_real_T *distances,
                   const real_T range_dis[40], const real_T nexist_edge_on[40],
                   const real_T nexist_edge_off[40], real_T prob_on, real_T
                   prob_off, real_T prob_stay_on, real_T prob_leave_off, real_T
                   prob_leave_on, real_T prob_stay_off, const emxArray_real_T
                   *ang_dev, const real_T range_ang[181], emxArray_real_T
                   *alpha_t, emxArray_real_T *obslik, real_T *T, emxArray_real_T
                   *DP_table, emxArray_real_T *aux_table, emxArray_real_T *z)
{
  emlrtStack st;
  real_T b_varargin_1[181];
  real_T varargin_1[40];
  real_T d;
  real_T loc_off;
  real_T loc_on;
  real_T predict_idx_0;
  real_T x_idx_0;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T iindx;
  int32_T k;
  int32_T loop_ub;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  i = DP_table->size[0] * DP_table->size[1];
  DP_table->size[0] = 2;
  DP_table->size[1] = node_idx->size[0];
  emxEnsureCapacity_real_T(sp, DP_table, i, &c_emlrtRTEI);
  loop_ub = node_idx->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    DP_table->data[i] = 0.0;
  }

  i = aux_table->size[0] * aux_table->size[1];
  aux_table->size[0] = 2;
  aux_table->size[1] = node_idx->size[0];
  emxEnsureCapacity_real_T(sp, aux_table, i, &d_emlrtRTEI);
  loop_ub = node_idx->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    aux_table->data[i] = 0.0;
  }

  /*  aux_table(1,1) = -Inf; */
  /*  aux_table(2,1) = -Inf; */
  i = z->size[0];
  z->size[0] = node_idx->size[0];
  emxEnsureCapacity_real_T(sp, z, i, &e_emlrtRTEI);
  loop_ub = node_idx->size[0];
  for (i = 0; i < loop_ub; i++) {
    z->data[i] = 0.0;
  }

  /*  E.A. List of log evidences: sum(log(z)) from 1:t. */
  i = alpha_t->size[0] * alpha_t->size[1];
  alpha_t->size[0] = 2;
  alpha_t->size[1] = node_idx->size[0];
  emxEnsureCapacity_real_T(sp, alpha_t, i, &f_emlrtRTEI);
  loop_ub = node_idx->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    alpha_t->data[i] = 0.0;
  }

  /* E.A. 2x1 vector (on/off) of posterior prob.: e.g. alpha_1 = [p(x=on|x); p(x=off|x)] */
  i = obslik->size[0] * obslik->size[1];
  obslik->size[0] = 2;
  obslik->size[1] = node_idx->size[0];
  emxEnsureCapacity_real_T(sp, obslik, i, &g_emlrtRTEI);
  loop_ub = node_idx->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    obslik->data[i] = 0.0;
  }

  /* E.A. 2x1 observation likelihood */
  if (1 > y_h->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, y_h->size[0], &emlrtBCI, sp);
  }

  st.site = &emlrtRSI;
  if (muDoubleScalarIsNaN(y_h->data[0])) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
      "MATLAB:nologicalnan", 0);
  }

  if (y_h->data[0] != 0.0) {
    if (1 > distances->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, distances->size[0], &b_emlrtBCI, sp);
    }

    for (k = 0; k < 40; k++) {
      varargin_1[k] = muDoubleScalarAbs(distances->data[0] - range_dis[k]);
    }

    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 41)) {
        if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      predict_idx_0 = varargin_1[idx - 1];
      i = idx + 1;
      for (k = i; k < 41; k++) {
        d = varargin_1[k - 1];
        if (predict_idx_0 > d) {
          predict_idx_0 = d;
          idx = k;
        }
      }
    }

    if (1 > ang_dev->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, ang_dev->size[0], &c_emlrtBCI, sp);
    }

    for (k = 0; k < 181; k++) {
      b_varargin_1[k] = muDoubleScalarAbs(ang_dev->data[0] - range_ang[k]);
    }

    if (!muDoubleScalarIsNaN(b_varargin_1[0])) {
      loop_ub = 1;
    } else {
      loop_ub = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 182)) {
        if (!muDoubleScalarIsNaN(b_varargin_1[k - 1])) {
          loop_ub = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (loop_ub == 0) {
      loop_ub = 1;
    } else {
      predict_idx_0 = b_varargin_1[loop_ub - 1];
      i = loop_ub + 1;
      for (k = i; k < 182; k++) {
        d = b_varargin_1[k - 1];
        if (predict_idx_0 > d) {
          predict_idx_0 = d;
          loop_ub = k;
        }
      }
    }

    loc_on = exist_edge_on[idx - 1] * ang_dev_on[loop_ub - 1];

    /* likelihood of y given x = on */
    loc_off = exist_edge_off[idx - 1] * ang_dev_off[loop_ub - 1];

    /* likelihood of y given x = off */
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &l_emlrtBCI, sp);
    }

    st.site = &b_emlrtRSI;
    if (loc_on < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    st.site = &b_emlrtRSI;
    if (prob_on < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    DP_table->data[0] = muDoubleScalarLog(loc_on) + muDoubleScalarLog(prob_on);
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &m_emlrtBCI, sp);
    }

    st.site = &c_emlrtRSI;
    if (loc_off < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    st.site = &c_emlrtRSI;
    if (prob_off < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    DP_table->data[1] = muDoubleScalarLog(loc_off) + muDoubleScalarLog(prob_off);

    /* Compute prob. of the evidence. E.A. */
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &d_emlrtBCI, sp);
    }

    obslik->data[0] = loc_on;
    obslik->data[1] = loc_off;
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &f_emlrtBCI, sp);
    }

    if (1 > obslik->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, obslik->size[1], &e_emlrtBCI, sp);
    }

    z->data[0] = obslik->data[0] * pi_var[0] + obslik->data[1] * pi_var[1];
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &q_emlrtBCI, sp);
    }

    alpha_t->data[0] = loc_on * pi_var[0] / z->data[0];
    alpha_t->data[1] = loc_off * pi_var[1] / z->data[0];

    /*      if (round(sum(alpha_t(:,1))) ~= 1) */
    /*          display('Error'); */
    /*      end */
    /*  Compute log likelihood ration and evidenct -- E.A              */
    /*              log_like_ratio_list(1) = log((p_y_on_1*p_t_on_1)/(p_y_off_1*p_t_off_1)); %E.A. log likelihood ratio (1st position, edge) */
    /*              evidence(1) = log(p_y_on_1*p_t_on_1*prob_on + p_y_off_1*p_t_off_1*prob_off); */
    /*        */
  } else {
    if (1 > distances->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, distances->size[0], &g_emlrtBCI, sp);
    }

    for (k = 0; k < 40; k++) {
      varargin_1[k] = muDoubleScalarAbs(distances->data[0] - range_dis[k]);
    }

    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 41)) {
        if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      iindx = 0;
    } else {
      predict_idx_0 = varargin_1[idx - 1];
      iindx = idx - 1;
      i = idx + 1;
      for (k = i; k < 41; k++) {
        d = varargin_1[k - 1];
        if (predict_idx_0 > d) {
          predict_idx_0 = d;
          iindx = k - 1;
        }
      }
    }

    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &n_emlrtBCI, sp);
    }

    d = nexist_edge_on[iindx];
    st.site = &d_emlrtRSI;
    if (d < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    d = muDoubleScalarLog(d);
    st.site = &d_emlrtRSI;
    if (prob_on < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    DP_table->data[0] = d + muDoubleScalarLog(prob_on);
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &o_emlrtBCI, sp);
    }

    d = nexist_edge_off[iindx];
    st.site = &e_emlrtRSI;
    if (d < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    d = muDoubleScalarLog(d);
    st.site = &e_emlrtRSI;
    if (prob_off < 0.0) {
      emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        3, "log");
    }

    DP_table->data[1] = d + muDoubleScalarLog(prob_off);

    /* Compute prob. of the evidence. E.A. */
    /* psi = [loc_on; loc_off]; */
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &h_emlrtBCI, sp);
    }

    obslik->data[0] = nexist_edge_on[iindx];
    obslik->data[1] = nexist_edge_off[iindx];
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &j_emlrtBCI, sp);
    }

    if (1 > obslik->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, obslik->size[1], &i_emlrtBCI, sp);
    }

    z->data[0] = obslik->data[0] * pi_var[0] + obslik->data[1] * pi_var[1];
    if (1 > node_idx->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, node_idx->size[0], &r_emlrtBCI, sp);
    }

    alpha_t->data[0] = nexist_edge_on[iindx] * pi_var[0] / z->data[0];
    alpha_t->data[1] = nexist_edge_off[iindx] * pi_var[1] / z->data[0];

    /* obslik(:,1) = [loc_on; loc_off]; */
    /*      if (round(sum(alpha_t(:,1))) ~= 1) */
    /*          display('Error'); */
    /*      end            */
    /*               */
    /*  Compute log likelihood ration and evidenct -- E.A              */
    /*              log_like_ratio_list(1) = log(p_y_on_1/p_y_off_1); %E.A. log likelihood ratio (1st position, no edge)   */
    /*              evidence(1) = log(p_y_on_1*prob_on + p_y_off_1*prob_off); */
    /*        */
  }

  /*  LOOP THROUGH */
  i = node_idx->size[0];
  for (b_i = 0; b_i <= i - 2; b_i++) {
    if ((b_i + 2 < 1) || (b_i + 2 > y_h->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, y_h->size[0], &k_emlrtBCI, sp);
    }

    st.site = &f_emlrtRSI;
    d = y_h->data[b_i + 1];
    if (muDoubleScalarIsNaN(d)) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:nologicalnan",
        "MATLAB:nologicalnan", 0);
    }

    if (d != 0.0) {
      if ((b_i + 2 < 1) || (b_i + 2 > distances->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, distances->size[0],
          &ab_emlrtBCI, sp);
      }

      for (k = 0; k < 40; k++) {
        varargin_1[k] = muDoubleScalarAbs(distances->data[b_i + 1] - range_dis[k]);
      }

      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 41)) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        idx = 1;
      } else {
        predict_idx_0 = varargin_1[idx - 1];
        i1 = idx + 1;
        for (k = i1; k < 41; k++) {
          d = varargin_1[k - 1];
          if (predict_idx_0 > d) {
            predict_idx_0 = d;
            idx = k;
          }
        }
      }

      if ((b_i + 2 < 1) || (b_i + 2 > ang_dev->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ang_dev->size[0], &cb_emlrtBCI,
          sp);
      }

      for (k = 0; k < 181; k++) {
        b_varargin_1[k] = muDoubleScalarAbs(ang_dev->data[b_i + 1] - range_ang[k]);
      }

      if (!muDoubleScalarIsNaN(b_varargin_1[0])) {
        loop_ub = 1;
      } else {
        loop_ub = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 182)) {
          if (!muDoubleScalarIsNaN(b_varargin_1[k - 1])) {
            loop_ub = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (loop_ub == 0) {
        loop_ub = 1;
      } else {
        predict_idx_0 = b_varargin_1[loop_ub - 1];
        i1 = loop_ub + 1;
        for (k = i1; k < 182; k++) {
          d = b_varargin_1[k - 1];
          if (predict_idx_0 > d) {
            predict_idx_0 = d;
            loop_ub = k;
          }
        }
      }

      loc_on = exist_edge_on[idx - 1] * ang_dev_on[loop_ub - 1];

      /* likelihood of y given x = on */
      loc_off = exist_edge_off[idx - 1] * ang_dev_off[loop_ub - 1];

      /* likelihood of y given x = off */
      st.site = &g_emlrtRSI;
      if (loc_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &g_emlrtRSI;
      if (prob_stay_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &g_emlrtRSI;
      if (loc_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &g_emlrtRSI;
      if (prob_leave_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &hb_emlrtBCI, sp);
      }

      x_idx_0 = (muDoubleScalarLog(loc_on) + muDoubleScalarLog(prob_stay_on)) +
        DP_table->data[2 * b_i];
      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &ib_emlrtBCI, sp);
      }

      loop_ub = 2 * b_i + 1;
      predict_idx_0 = (muDoubleScalarLog(loc_on) + muDoubleScalarLog
                       (prob_leave_off)) + DP_table->data[loop_ub];
      if ((x_idx_0 < predict_idx_0) || (muDoubleScalarIsNaN(x_idx_0) &&
           (!muDoubleScalarIsNaN(predict_idx_0)))) {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &lb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1)] = predict_idx_0;
        iindx = 2;
      } else {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &lb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1)] = x_idx_0;
        iindx = 1;
      }

      if ((b_i + 2 < 1) || (b_i + 2 > aux_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, aux_table->size[1],
          &nb_emlrtBCI, sp);
      }

      i1 = 2 * (b_i + 1);
      aux_table->data[i1] = iindx;
      st.site = &h_emlrtRSI;
      if (loc_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &h_emlrtRSI;
      if (prob_leave_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &h_emlrtRSI;
      if (loc_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      st.site = &h_emlrtRSI;
      if (prob_stay_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &pb_emlrtBCI, sp);
      }

      x_idx_0 = (muDoubleScalarLog(loc_off) + muDoubleScalarLog(prob_leave_on))
        + DP_table->data[2 * b_i];
      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &qb_emlrtBCI, sp);
      }

      predict_idx_0 = (muDoubleScalarLog(loc_off) + muDoubleScalarLog
                       (prob_stay_off)) + DP_table->data[loop_ub];
      if ((x_idx_0 < predict_idx_0) || (muDoubleScalarIsNaN(x_idx_0) &&
           (!muDoubleScalarIsNaN(predict_idx_0)))) {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &tb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1) + 1] = predict_idx_0;
        iindx = 2;
      } else {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &tb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1) + 1] = x_idx_0;
        iindx = 1;
      }

      if ((b_i + 2 < 1) || (b_i + 2 > aux_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, aux_table->size[1],
          &ub_emlrtBCI, sp);
      }

      k = 2 * (b_i + 1) + 1;
      aux_table->data[k] = iindx;

      /* Compute prob. of the evidence. E.A.             */
      /* psi = [loc_on; loc_off]; */
      if ((b_i + 2 < 1) || (b_i + 2 > obslik->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, obslik->size[1], &p_emlrtBCI,
          sp);
      }

      obslik->data[i1] = loc_on;
      obslik->data[k] = loc_off;
      if (((int32_T)(((real_T)b_i + 2.0) - 1.0) < 1) || ((int32_T)(((real_T)b_i
             + 2.0) - 1.0) > alpha_t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(((real_T)b_i + 2.0) - 1.0), 1,
          alpha_t->size[1], &s_emlrtBCI, sp);
      }

      predict_idx_0 = Psi_t[0] * alpha_t->data[2 * b_i] + Psi_t[2] *
        alpha_t->data[loop_ub];
      d = Psi_t[1] * alpha_t->data[2 * b_i] + Psi_t[3] * alpha_t->data[loop_ub];
      if ((b_i + 2 < 1) || (b_i + 2 > obslik->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, obslik->size[1], &t_emlrtBCI,
          sp);
      }

      if ((b_i + 2 < 1) || (b_i + 2 > z->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, z->size[0], &vb_emlrtBCI, sp);
      }

      z->data[b_i + 1] = obslik->data[i1] * predict_idx_0 + obslik->data[k] * d;
      if ((b_i + 2 < 1) || (b_i + 2 > z->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, z->size[0], &wb_emlrtBCI, sp);
      }

      if ((b_i + 2 < 1) || (b_i + 2 > alpha_t->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, alpha_t->size[1], &u_emlrtBCI,
          sp);
      }

      x_idx_0 = z->data[b_i + 1];
      alpha_t->data[i1] = loc_on * predict_idx_0 / x_idx_0;
      alpha_t->data[k] = loc_off * d / x_idx_0;

      /* obslik(:,i) = [loc_on; loc_off]; */
      /*          if (round(sum(alpha_t(:,1))) ~= 1) */
      /*              display('Error'); */
      /*          end                 */
      /*  Compute log likelihood ration and evidenct -- E.A                  */
      /*                  log_like_ratio_list(i) = log((p_y_on_1*p_t_on_1)/(p_y_off_1*p_t_off_1)); %E.A. store likelihood               */
      /*                  evidence(i) = evidence(i-1) + log(p_y_on_1*p_t_on_1*prob_stay_on + p_y_on_1*p_t_on_1*prob_stay_off + ... */
      /*                      p_y_off_1*p_t_off_1*prob_leave_on +  p_y_off_1*p_t_off_1*prob_stay_off); %E.A. log evidence 1..i */
    } else {
      /*  */
      if ((b_i + 2 < 1) || (b_i + 2 > distances->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, distances->size[0],
          &bb_emlrtBCI, sp);
      }

      for (k = 0; k < 40; k++) {
        varargin_1[k] = muDoubleScalarAbs(distances->data[b_i + 1] - range_dis[k]);
      }

      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        idx = 1;
      } else {
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 41)) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (idx == 0) {
        iindx = 0;
      } else {
        predict_idx_0 = varargin_1[idx - 1];
        iindx = idx - 1;
        i1 = idx + 1;
        for (k = i1; k < 41; k++) {
          d = varargin_1[k - 1];
          if (predict_idx_0 > d) {
            predict_idx_0 = d;
            iindx = k - 1;
          }
        }
      }

      d = nexist_edge_on[iindx];
      st.site = &i_emlrtRSI;
      if (d < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      d = muDoubleScalarLog(d);
      st.site = &i_emlrtRSI;
      if (prob_stay_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      predict_idx_0 = nexist_edge_on[iindx];
      st.site = &i_emlrtRSI;
      if (predict_idx_0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      predict_idx_0 = muDoubleScalarLog(predict_idx_0);
      st.site = &i_emlrtRSI;
      if (prob_leave_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &db_emlrtBCI, sp);
      }

      x_idx_0 = (d + muDoubleScalarLog(prob_stay_on)) + DP_table->data[2 * b_i];
      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &eb_emlrtBCI, sp);
      }

      loop_ub = 2 * b_i + 1;
      predict_idx_0 = (predict_idx_0 + muDoubleScalarLog(prob_leave_off)) +
        DP_table->data[loop_ub];
      if ((x_idx_0 < predict_idx_0) || (muDoubleScalarIsNaN(x_idx_0) &&
           (!muDoubleScalarIsNaN(predict_idx_0)))) {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &fb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1)] = predict_idx_0;
        idx = 2;
      } else {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &fb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1)] = x_idx_0;
        idx = 1;
      }

      if ((b_i + 2 < 1) || (b_i + 2 > aux_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, aux_table->size[1],
          &gb_emlrtBCI, sp);
      }

      i1 = 2 * (b_i + 1);
      aux_table->data[i1] = idx;
      d = nexist_edge_off[iindx];
      st.site = &j_emlrtRSI;
      if (d < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      d = muDoubleScalarLog(d);
      st.site = &j_emlrtRSI;
      if (prob_leave_on < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      predict_idx_0 = nexist_edge_off[iindx];
      st.site = &j_emlrtRSI;
      if (predict_idx_0 < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      predict_idx_0 = muDoubleScalarLog(predict_idx_0);
      st.site = &j_emlrtRSI;
      if (prob_stay_off < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &jb_emlrtBCI, sp);
      }

      x_idx_0 = (d + muDoubleScalarLog(prob_leave_on)) + DP_table->data[2 * b_i];
      if ((b_i + 1 < 1) || (b_i + 1 > DP_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, DP_table->size[1],
          &kb_emlrtBCI, sp);
      }

      predict_idx_0 = (predict_idx_0 + muDoubleScalarLog(prob_stay_off)) +
        DP_table->data[loop_ub];
      if ((x_idx_0 < predict_idx_0) || (muDoubleScalarIsNaN(x_idx_0) &&
           (!muDoubleScalarIsNaN(predict_idx_0)))) {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &mb_emlrtBCI, sp);
        }

        DP_table->data[i1 + 1] = predict_idx_0;
        idx = 2;
      } else {
        if ((b_i + 2 < 1) || (b_i + 2 > DP_table->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, DP_table->size[1],
            &mb_emlrtBCI, sp);
        }

        DP_table->data[2 * (b_i + 1) + 1] = x_idx_0;
        idx = 1;
      }

      if ((b_i + 2 < 1) || (b_i + 2 > aux_table->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, aux_table->size[1],
          &ob_emlrtBCI, sp);
      }

      k = 2 * (b_i + 1) + 1;
      aux_table->data[k] = idx;

      /* Compute prob. of the evidence. E.A. */
      if ((b_i + 2 < 1) || (b_i + 2 > obslik->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, obslik->size[1], &v_emlrtBCI,
          sp);
      }

      obslik->data[i1] = nexist_edge_on[iindx];
      obslik->data[k] = nexist_edge_off[iindx];
      if (((int32_T)(((real_T)b_i + 2.0) - 1.0) < 1) || ((int32_T)(((real_T)b_i
             + 2.0) - 1.0) > alpha_t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(((real_T)b_i + 2.0) - 1.0), 1,
          alpha_t->size[1], &w_emlrtBCI, sp);
      }

      predict_idx_0 = Psi_t[0] * alpha_t->data[2 * b_i] + Psi_t[2] *
        alpha_t->data[loop_ub];
      d = Psi_t[1] * alpha_t->data[2 * b_i] + Psi_t[3] * alpha_t->data[loop_ub];
      if ((b_i + 2 < 1) || (b_i + 2 > obslik->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, obslik->size[1], &x_emlrtBCI,
          sp);
      }

      if ((b_i + 2 < 1) || (b_i + 2 > z->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, z->size[0], &rb_emlrtBCI, sp);
      }

      z->data[b_i + 1] = obslik->data[i1] * predict_idx_0 + obslik->data[k] * d;
      if ((b_i + 2 < 1) || (b_i + 2 > z->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, z->size[0], &sb_emlrtBCI, sp);
      }

      if ((b_i + 2 < 1) || (b_i + 2 > alpha_t->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, alpha_t->size[1], &y_emlrtBCI,
          sp);
      }

      x_idx_0 = z->data[b_i + 1];
      alpha_t->data[i1] = nexist_edge_on[iindx] * predict_idx_0 / x_idx_0;
      alpha_t->data[k] = nexist_edge_off[iindx] * d / x_idx_0;

      /*          if (round(sum(alpha_t(:,1))) ~= 1) */
      /*              display('Error'); */
      /*          end */
      /*  Compute log likelihood ration and evidence --  E.A                  */
      /*                  log_like_ratio_list(i) = log(p_y_on_1/p_y_off_1); %E.A. store likelihood */
      /*                  evidence(i) = evidence(i-1) + log(p_y_on_1*prob_stay_on + p_y_on_1*prob_leave_off + ... */
      /*                      p_y_off_1*prob_leave_on + p_y_off_1*prob_stay_off); %E.A. log evidence 1..i */
      /*                  */
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  loop_ub = DP_table->size[1];
  *T = loop_ub;
}

/* End of code generation (hmmParameters.c) */
