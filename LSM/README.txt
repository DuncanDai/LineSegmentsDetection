dinggen 2022.08.26 
【Source Code Overview】
dir display: display image
dir Imgs: image data
dir lsd_1.5: LSD algorithm for supporting
dir LSM-Dec16: LSM algorithm (main algorithm)

demo.m
README.txt


【LSD algorithm： Compile】
website page - including article, demo and source code: http://www.ipol.im/pub/art/2012/gjmr-lsd/
website page - the author: https://scholar.google.fr/citations?hl=en&user=GLovf4UAAAAJ&view_op=list_works&sortby=pubdate
github repo: https://github.com/theWorldCreator/LSD

Please read through the REAME.txt in dir of lsd_1.6


【LSD algorithm: Running】
first: run terminal in the path which includes the lsd code files
# lsd_cmd.c
if you input lsd: you can get command version & help

# run ./lsd
./lsd chairs.pgm chairs.result.txt


【LSM algorithm】
step 1 use lsd_1.6(updated) to replace lsd_1.5
step 2 implement lsd_mexFunc.c （imitate the lsd_call_example.c to implement the mex Entry Function）
step 3 mex -output lsd_mex lsd.c lsd_mexFunc.c

===============================================================================
[lsd_1.5]
1 Bug: mxErrMsgTxt -> mexErrMsgTxt (other mexFuncs use mx_)
2 Bug: there is no hardcopy() in the new version 
	from `img = hardcopy(hfig, '-Dzbuffer', '-r0');` -> `img = frame2im(getframe(hfig));`



[lsd_1.6]
### Debug notes： lsd_mexFunc.c
1 Bug: mxErrMsgTxt -> mexErrMsgTxt (other mexFuncs use mx_)

	in lsd_mexFunc.c some variable are not defined in lsd.h （because everthing except LSD functions are only declared and implemented in lsd.c）
	- Solution: move the in lsd_mexFunc.c called variable and functions to lsd.h (Don't delete others, and don't redefinite)


	Bug: the arguments number of lsd_scale() (lsd.c implementation differs from lsd1.5 to lsd1.6 -> need to change mexFunction)
	- double * lsd_scale(int * n_out, double * img, int X, int Y, double scale);

final decision: rewrite mexFunction() 2022.08.27
===============================================================================