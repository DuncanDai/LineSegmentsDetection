/* 
 *  Copyright (c) 2011  Chen Feng (cforrest[at]umich[dot]edu), Sid Yingze Bao
 *  (baoyingze[at]umich[dot]edu) and the University of Michigan
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 */

/* lsd_matlab.c, detecting line segments from grey images,
   using LSD - Line Segment Detector on digital images
   from rafael grompone von gioi (grompone@gmail.com)
	Usage:
		lines = lsd(double(image))
	INPUT:
		image <WxH>, uint8 grey image
	OUTPUT:
		lines <nx5>, x1,y1,x2,y2,width
  */
#include <stdio.h>
#include "lsd.h"
#include "mex.h"

#define IDX(i,j,im) ((im)*(i)+(j))

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
	image_double image;
	ntuple_list out;
	unsigned int i,j,m,n;
	unsigned int X,Y;  /* x , y image size */
	
    double *M,*MP;
	double *imgptr;
	
	if(nlhs<=0 || nrhs<=0)
		mexErrMsgTxt("Not enough i/o parameters! exit...");
	if( !mxIsDouble(prhs[0]) )
		mexErrMsgTxt("Input matrix should be double-precision! exit...");
	
	M = mxGetPr(prhs[0]);
	Y = m = mxGetM(prhs[0]);
	X = n = mxGetN(prhs[0]);
	
    
    /* M is 1-D array and is column major order according to the matlab input */
    /* image->data is 1-D array */
    // !!!Function: following code: change 2D-matlab input to 1D-array
    image = new_image_double(X,Y);
	imgptr=image->data;
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
			*imgptr++ = M[IDX(j,i,m)];

    // lsd v1.5: input is image_double type (struct)
    out = lsd_scale(image,1.0); // scale = 0.8 -> sigma = simga_scale/scale
	/*out = lsd(image);*/  // default scale = 0.8
     
    /* dinggen 2022.08.28 : this reshape the output of lsd_1.5 */
	/*mexPrintf("[lsd] %u line segments found.\n",out->size);*/
	plhs[0] = mxCreateDoubleMatrix(out->size,out->dim,mxREAL);
	MP = mxGetPr(plhs[0]);
    // dinggen: from 1D to 2D-matlab output
	for(i=0;i<out->size;i++) 
		for(j=0;j<out->dim;j++)
			MP[IDX(j,i,out->size)] = out->values[IDX(i,j,out->dim)];

	free_image_double(image);
	free_ntuple_list(out);
}
