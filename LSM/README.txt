dinggen 2022.08.26 
【Source Code Overview】
dir display: display image
dir Imgs: image data
dir lsd_1.5: LSD algorithm for supporting
dir LSM-Dec16: LSM algorithm (main algorithm)

demo.m
README.txt


【Debug: LSD algorithm】
website page - including article, demo and source code: http://www.ipol.im/pub/art/2012/gjmr-lsd/
website page - the author: https://scholar.google.fr/citations?hl=en&user=GLovf4UAAAAJ&view_op=list_works&sortby=pubdate
github repo: https://github.com/theWorldCreator/LSD


Please read through the REAME.txt in dir of lsd_1.6

### Makefile
# To all source code
all: lsd lsd_call_example

# only for source code: lsd
# 1st line: description
# 2nd line: specific compile command
lsd: lsd.c lsd.h lsd_cmd.c
	gcc -O3 -o lsd lsd_cmd.c lsd.c -lm

# only for source code: lsd_call_example: 
# 1st line: description
# 2nd line: specific compile command
lsd_call_example: lsd.c lsd.h lsd_call_example.c
	gcc -o lsd_call_example lsd_call_example.c lsd.c -lm

doc: lsd.c lsd.h doxygen.config
	doxygen doxygen.config

clean:
	rm -f lsd lsd_call_example

cleandoc:
	rm -rf doc






