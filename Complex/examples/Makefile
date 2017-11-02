ComplexPath := ..
ComplexHead := complex.h
ComplexSource := complex.cpp
ComplexObject := complex.o

MainPath := .
MainSource := example.cpp
MainObject := example.o
MainExe := example

INCLUDE := -I${ComplexPath}

DEL := rm

ifneq ($(shell uname), Linux)
	DEL = del
endif

${MainExe}: ${MainObject} ${ComplexObject}
	g++ *.o -o ${MainExe}
	
${MainObject}: ${MainSource} ${ComplexPath}/${ComplexHead}
	g++ ${INCLUDE} -c ${MainSource}

${ComplexObject}: ${ComplexPath}/${ComplexSource}  ${ComplexPath}/${ComplexHead}
	g++ ${INCLUDE} -c ${ComplexPath}/${ComplexSource}

clean:
	${DEL} *.o