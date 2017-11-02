SortLinkPath := ..
SortLinkHead := sortlink.h

MainSource := example.cpp
MainObject := example.o
MainExe := example

INCLUDE := -I${SortLinkPath}

DEL := rm
ifneq ($(shell uname), Linux)
	DEL = del
endif

${MainExe}: ${MainObject}
	g++ *.o -o ${MainExe}

${MainObject}: ${MainSource} ${SortLinkPath}/${SortLinkHead}
	g++ ${INCLUDE} -c ${MainSource}
 
clean:
	${DEL} *.o