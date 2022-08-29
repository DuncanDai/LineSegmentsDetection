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
