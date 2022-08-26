/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * returnLines.c
 *
 * Code generation for function 'returnLines'
 *
 */

/* Include files */
#include "returnLines.h"
#include "returnLines_data.h"
#include "returnLines_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  20,                                  /* iLast */
  50,                                  /* lineNo */
  31,                                  /* colNo */
  "endpositionsT",                     /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  38,                                  /* lineNo */
  22,                                  /* colNo */
  "endpositionsT",                     /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  30,                                  /* lineNo */
  22,                                  /* colNo */
  "endpositionsT",                     /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  49,                                  /* lineNo */
  35,                                  /* colNo */
  "startpositionsT",                   /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "startpositionsT",                   /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  48,                                  /* lineNo */
  23,                                  /* colNo */
  "lslengthT",                         /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  40,                                  /* lineNo */
  18,                                  /* colNo */
  "lslengthT",                         /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  32,                                  /* lineNo */
  18,                                  /* colNo */
  "lslengthT",                         /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  47,                                  /* lineNo */
  27,                                  /* colNo */
  "end_pointsT",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  36,                                  /* lineNo */
  20,                                  /* colNo */
  "end_pointsT",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  28,                                  /* lineNo */
  20,                                  /* colNo */
  "end_pointsT",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  46,                                  /* lineNo */
  32,                                  /* colNo */
  "begin_pointsT",                     /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  20,                                  /* iLast */
  19,                                  /* lineNo */
  26,                                  /* colNo */
  "begin_pointsT",                     /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  56,                                  /* colNo */
  "points_proj",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  55,                                  /* colNo */
  "points_proj",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  62,                                  /* colNo */
  "points_proj",                       /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  11,                                  /* colNo */
  "final_labels",                      /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  11,                                  /* colNo */
  "final_labels",                      /* aName */
  "returnLines",                       /* fName */
  "U:\\my_projs\\LineSegmentsDetection\\MCMLSD\\code\\mexfiles\\returnLines.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void returnLines(const emlrtStack *sp, const emxArray_real_T *points_proj, const
                 emxArray_real_T *final_labels, real_T begin_points_data[],
                 int32_T begin_points_size[2], real_T end_points_data[], int32_T
                 end_points_size[2], real_T lslength_data[], int32_T
                 lslength_size[1], real_T startpositions_data[], int32_T
                 startpositions_size[1], real_T endpositions_data[], int32_T
                 endpositions_size[1])
{
  real_T begin_pointsT[40];
  real_T end_pointsT[40];
  int32_T lslengthT[20];
  int32_T b_i;
  int32_T counter_begin_points;
  int32_T counter_end_points;
  int32_T counter_endpositions;
  int32_T counter_lslength;
  int32_T counter_startpositions;
  int32_T i;
  int32_T startpos;
  uint32_T endpositionsT[20];
  uint32_T startpositionsT[20];
  boolean_T on_seg;
  on_seg = false;
  counter_begin_points = 0;
  memset(&begin_pointsT[0], 0, 40U * sizeof(real_T));
  memset(&end_pointsT[0], 0, 40U * sizeof(real_T));
  counter_end_points = 1;
  counter_lslength = 1;
  startpos = -1;
  counter_startpositions = 1;
  memset(&lslengthT[0], 0, 20U * sizeof(int32_T));
  memset(&startpositionsT[0], 0, 20U * sizeof(uint32_T));
  memset(&endpositionsT[0], 0, 20U * sizeof(uint32_T));
  counter_endpositions = 1;
  i = final_labels->size[1];
  for (b_i = 0; b_i < i; b_i++) {
    if (!on_seg) {
      if ((b_i + 1 < 1) || (b_i + 1 > final_labels->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, final_labels->size[1],
          &q_emlrtBCI, sp);
      }

      if (final_labels->data[b_i] == 1.0) {
        if ((b_i + 1 < 1) || (b_i + 1 > points_proj->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, points_proj->size[0],
            &p_emlrtBCI, sp);
        }

        if ((counter_begin_points + 1 < 1) || (counter_begin_points + 1 > 20)) {
          emlrtDynamicBoundsCheckR2012b(counter_begin_points + 1, 1, 20,
            &m_emlrtBCI, sp);
        }

        begin_pointsT[counter_begin_points] = points_proj->data[b_i];
        begin_pointsT[counter_begin_points + 20] = points_proj->data[b_i +
          points_proj->size[0]];
        counter_begin_points++;
        if (counter_startpositions > 20) {
          emlrtDynamicBoundsCheckR2012b(21, 1, 20, &e_emlrtBCI, sp);
        }

        startpositionsT[counter_startpositions - 1] = (uint32_T)(b_i + 1);
        counter_startpositions++;
        startpos = b_i;
        on_seg = true;
      }
    } else if (b_i + 1 == final_labels->size[1]) {
      if ((b_i + 1 < 1) || (b_i + 1 > points_proj->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, points_proj->size[0],
          &o_emlrtBCI, sp);
      }

      if (counter_end_points > 20) {
        emlrtDynamicBoundsCheckR2012b(21, 1, 20, &k_emlrtBCI, sp);
      }

      end_pointsT[counter_end_points - 1] = points_proj->data[b_i];
      end_pointsT[counter_end_points + 19] = points_proj->data[b_i +
        points_proj->size[0]];
      counter_end_points++;
      if (counter_endpositions > 20) {
        emlrtDynamicBoundsCheckR2012b(21, 1, 20, &c_emlrtBCI, sp);
      }

      endpositionsT[counter_endpositions - 1] = (uint32_T)(b_i + 1);
      counter_endpositions++;
      if (counter_lslength > 20) {
        emlrtDynamicBoundsCheckR2012b(21, 1, 20, &h_emlrtBCI, sp);
      }

      lslengthT[counter_lslength - 1] = b_i - startpos;
      counter_lslength++;
      on_seg = false;
    } else {
      if ((b_i + 1 < 1) || (b_i + 1 > final_labels->size[1])) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, final_labels->size[1],
          &r_emlrtBCI, sp);
      }

      if (final_labels->data[b_i] == 0.0) {
        if ((b_i < 1) || (b_i > points_proj->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, points_proj->size[0],
            &n_emlrtBCI, sp);
        }

        if (counter_end_points > 20) {
          emlrtDynamicBoundsCheckR2012b(21, 1, 20, &j_emlrtBCI, sp);
        }

        end_pointsT[counter_end_points - 1] = points_proj->data[b_i - 1];
        end_pointsT[counter_end_points + 19] = points_proj->data[(b_i +
          points_proj->size[0]) - 1];
        counter_end_points++;
        if (counter_endpositions > 20) {
          emlrtDynamicBoundsCheckR2012b(21, 1, 20, &b_emlrtBCI, sp);
        }

        endpositionsT[counter_endpositions - 1] = (uint32_T)b_i;
        counter_endpositions++;
        if (counter_lslength > 20) {
          emlrtDynamicBoundsCheckR2012b(21, 1, 20, &g_emlrtBCI, sp);
        }

        lslengthT[counter_lslength - 1] = b_i - startpos;
        counter_lslength++;
        on_seg = false;
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (1 > counter_begin_points) {
    counter_begin_points = 0;
  } else {
    if (counter_begin_points > 20) {
      emlrtDynamicBoundsCheckR2012b(counter_begin_points, 1, 20, &l_emlrtBCI, sp);
    }
  }

  begin_points_size[0] = counter_begin_points;
  begin_points_size[1] = 2;
  if (0 <= counter_begin_points - 1) {
    memcpy(&begin_points_data[0], &begin_pointsT[0], counter_begin_points *
           sizeof(real_T));
  }

  for (i = 0; i < counter_begin_points; i++) {
    begin_points_data[i + counter_begin_points] = begin_pointsT[i + 20];
  }

  if (1 > counter_end_points - 1) {
    counter_begin_points = 0;
  } else {
    if (counter_end_points - 1 < 1) {
      emlrtDynamicBoundsCheckR2012b(counter_end_points - 1, 1, 20, &i_emlrtBCI,
        sp);
    }

    counter_begin_points = counter_end_points - 1;
  }

  end_points_size[0] = counter_begin_points;
  end_points_size[1] = 2;
  if (0 <= counter_begin_points - 1) {
    memcpy(&end_points_data[0], &end_pointsT[0], counter_begin_points * sizeof
           (real_T));
  }

  for (i = 0; i < counter_begin_points; i++) {
    end_points_data[i + counter_begin_points] = end_pointsT[i + 20];
  }

  if (1 > counter_lslength - 1) {
    counter_begin_points = 0;
  } else {
    if (counter_lslength - 1 < 1) {
      emlrtDynamicBoundsCheckR2012b(counter_lslength - 1, 1, 20, &f_emlrtBCI, sp);
    }

    counter_begin_points = counter_lslength - 1;
  }

  lslength_size[0] = counter_begin_points;
  for (i = 0; i < counter_begin_points; i++) {
    lslength_data[i] = lslengthT[i];
  }

  if (counter_startpositions > 20) {
    emlrtDynamicBoundsCheckR2012b(21, 1, 20, &d_emlrtBCI, sp);
  }

  startpositions_size[0] = counter_startpositions;
  for (i = 0; i < counter_startpositions; i++) {
    startpositions_data[i] = startpositionsT[i];
  }

  if (1 > counter_endpositions - 1) {
    counter_begin_points = 0;
  } else {
    if (counter_endpositions - 1 < 1) {
      emlrtDynamicBoundsCheckR2012b(counter_endpositions - 1, 1, 20, &emlrtBCI,
        sp);
    }

    counter_begin_points = counter_endpositions - 1;
  }

  endpositions_size[0] = counter_begin_points;
  for (i = 0; i < counter_begin_points; i++) {
    endpositions_data[i] = endpositionsT[i];
  }
}

/* End of code generation (returnLines.c) */
