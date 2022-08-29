#include "mex.h"

/*
 * timestwoalt.c
 * Use mxGetScalar to return the values of scalars instead of pointers
 * to copies of scalar variables.
 *
 * This is a MEX-file for MATLAB.
 * Copyright 1984-2018 The MathWorks, Inc.
 */

void timestwo_alt(double* y, double x) {
    *y = 2.0 * x;
}

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {
#if MX_HAS_INTERLEAVED_COMPLEX
    mxDouble* py;
#else
    double* y;
#endif
    double x;

    /* Check arguments */
    if (nrhs != 1) {
        mexErrMsgIdAndTxt("MATLAB:timestwoalt:invalidNumInputs", "One input argument required.");
    } else if (nlhs > 1) {
        mexErrMsgIdAndTxt("MATLAB:timestwoalt:maxlhs", "Too many output arguments.");
    } else if (!mxIsNumeric(prhs[0])) {
        mexErrMsgIdAndTxt("MATLAB:timestwoalt:invalidInputType", "Argument must be numeric.");
    } else if (mxGetNumberOfElements(prhs[0]) != 1 || mxIsComplex(prhs[0])) {
        mexErrMsgIdAndTxt("MATLAB:timestwoalt:inputNotRealScalar",
                          "Argument must be non-complex scalar.");
    }
    /* Create a 1-by-1 matrix for the return argument */
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);

    /* Get the scalar value of the input x */
    /* note: mxGetScalar returns a value, not a pointer */
    x = mxGetScalar(prhs[0]);

    /* Assign a pointer to the output */
#if MX_HAS_INTERLEAVED_COMPLEX
    py = mxGetDoubles(plhs[0]);
    /* Call the timestwo_alt subroutine */
    timestwo_alt(py, x);
#else
    y = mxGetPr(plhs[0]);
    /* Call the timestwo_alt subroutine */
    timestwo_alt(y, x);
#endif
}
