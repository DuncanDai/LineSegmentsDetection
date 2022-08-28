/* dinggen 2022.08.27 Copyright (c) 2022  DAI Dinggen (dinggen.dai@student.kit.edu)
 */

/* mexFunction, Entry function to be used by matlab for compiling the c source code lsd.c
	Usage:
		lsd_scale(n_out, double(img), X, Y, double(scale))
	INPUT:
        n int, the number of the detected lines
		image <WxH>, double grey image
        X int, image width (column of matrix)
        Y int, image height (row of matrix)
        scale double, downsampling scale of image
	OUTPUT:
        the number of detected lines
		lines <nx7>, x1,y1,x2,y2,width,p,-log10(NFA)
  */


#include "mex.h"

#include <stdio.h>
#include <stdlib.h>
#include "lsd.h"

/** deal with the index of image (Column major order in matlab) */
#define IDX(i,j,im) ((im)*(i)+(j))
#define OUT_MAT_ROWS 7

/* Input Arguments */
// extern mxArray *mxCreateSharedDataCopy(const mxArray *pr);

#define NUM_OUT   prhs[0]
#define IMAGE     prhs[1]
#define NUM_COL   prhs[2]
#define NUM_ROW   prhs[3]
#define SCALE     prhs[4]


/* Output Arguments */
// #define	NUM_LINES	plhs[0]
#define	OUT_MAT  	plhs[0]




void mexFunction(int nlhs, mxArray* plhs[], 
                 int nrhs, const mxArray* prhs[]) 
{
    int * n_out;  // number of lines detected
    double * image;
    double * output;
    double scale;
    int i,j,mrows,ncols;
    
    double * output_mat;
    
    
    /* check the number of input arguments */
    if(nrhs != 5) {
        mexErrMsgIdAndTxt("lsd_scale(&n_out, double(image) , ncols, mrows, double(scale))",
                          "Five inputs required.");
    }
    /* check the number of output arguments */
    if(nlhs != 1) {
        mexErrMsgIdAndTxt("n_out: number of lines detected; output matric <nx7>",
                          "two outputs required.");
    }
    
    /* validate the input arguments type */
    /* make sure the 2nd input argument is an image */
    mrows = mxGetScalar(NUM_ROW);
    ncols = mxGetScalar(NUM_COL);
    mexPrintf("image rows is %u, image cols is %u\n",mrows, ncols);
   
    if(!mxIsDouble(IMAGE) ||
        mxIsComplex(IMAGE) ||
        mrows <= 0 || ncols <= 0){
       mexErrMsgIdAndTxt( "2nd Input must be an image.", 
                          "load an image");
    }
    
    /* get the values of input arguments */
    /* create a pointer to the real data in the input matrix  */
    #if MX_HAS_INTERLEAVED_COMPLEX
        image = mxGetDoubles(IMAGE);
    #else
        image = mxGetPr(IMAGE);
    #endif
    scale = mxGetScalar(SCALE);
    
    
    /* =========================== */
    /* set the values to the ouput */
//     NUM_LINES = mxCreateDoubleScalar(0);  // initial value
    ///????
//     n_out = (int *) mxGetPr(NUM_LINES);
    mexPrintf("hey I'm here 1");
    output = lsd_scale(n_out, image, ncols, mrows, scale);
//     n_out = sizeof(output)/sizeof(output[0])/NUM_OUTPUT_ROWS; => mxGetNumberOfElements(prhs[0])
    mexPrintf("\n number of lines is %d 1", *n_out);
    OUT_MAT = mxCreateDoubleMatrix(OUT_MAT_ROWS, (mwSize)*n_out, mxREAL);
    output_mat = mxGetPr(OUT_MAT);
    mexPrintf("\n number of lines is %d 2", *n_out);
    
    // from 1-D array in C to 1-D form in matlab (output of mexFunction is a matrix)
    for(i=0;i<*n_out;i++) 
		for(j=0;j<OUT_MAT_ROWS;j++)
			output_mat[IDX(j,i,*n_out)] = output[IDX(i,j,OUT_MAT_ROWS)];
    mexPrintf("\n number of lines is %d 3", *n_out);
          

    
    /* memcopy() */
//     memcpy(mxGetPr(temp), data, 5*sizeof(double));
    
    
    /* free memory */
    free( (void *) image );
    free( (void *) output );

}

