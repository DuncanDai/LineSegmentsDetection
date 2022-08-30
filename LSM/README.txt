# Name: dinggen 
# Date: 2022.08.26
# Email: daidinggen@hotmail.com 


【Source Code Overview】
dir display: display image
dir Imgs: image data
dir lsd_1.5: LSD algorithm for supporting
dir LSM-Dec16: LSM algorithm (main algorithm)

demo.m
README.txt

===============================================================================
【LSD algorithm： Compile】
Please read through the REAME.txt in dir of lsd_1.6


【LSD algorithm: Running】
first: run terminal in the path which includes the lsd code files

1 run lsd_cmd.c in terminal
if you input lsd: you can get command version & help

2 run ./lsd
./lsd chairs.pgm chairs.result.txt
===============================================================================
【LSM algorithm】
Note: based on LSD algorithm, LSM then merge the detected lines.

Please look at the demo.m
The key command is 
	[D, num_lines]=lsd_mexFunc(I/max(I(:))*255, 1.0);

@input
	- I   	      color image	to extract the line
	- scale=1.0   double		image scale size
@output
	- D 	      <nx7>		n is the detected line number, there are 7 values in one detected line
	- num_lines 			the detected line number





===============================================================================
【unfinished work for improving】 -> memory management
	[mxMalloc](http://www.mathworks.com/access/helpdesk/help/techdoc/apiref/mxmalloc.html)，
	[mxFree](http://www.mathworks.com/access/helpdesk/help/techdoc/apiref/mxfree.html)

especially pay attention to the related argument of the following command: 
	output = lsd_scale(&num_lines, image, ncols, mrows, scale);


[Notice!!!]
I tried compiling in matlab firstly -> the APP crashed 
(I guess the reason is the variable memory managment for the function, especially the variable `image`
	output = lsd_scale(&num_lines, image, ncols, mrows, scale); )

Then when I tried compiling in VS 2019 to check the correcness of source code. (source code is ok)
Later I tried compiling in matlab again, the mexfile works fine. (the source code of mexfile has not been changed.)

