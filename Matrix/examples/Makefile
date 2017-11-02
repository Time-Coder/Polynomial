MatrixPath := ..
MatrixHead := matrix.h
MatrixSource := matrix.cpp
MatrixObject := matrix.o

ComplexPath := ../../Complex
ComplexHead := complex.h
ComplexSource := complex.cpp
ComplexObject := complex.o

MainPath := .
MainSource := example.cpp
MainObject := example.o
MainExe := example

INCLUDE := -I${MatrixPath} -I${ComplexPath}

DEL := rm

ifneq ($(shell uname), Linux)
	DEL = del
endif

${MainExe}: ${MainObject} ${MatrixObject} ${ComplexObject}
	g++ *.o -o ${MainExe}
	
${MainObject}: ${MainSource} ${MatrixPath}/${MatrixHead}
	g++ ${INCLUDE} -c ${MainSource}

${MatrixObject}: ${MatrixPath}/${MatrixSource} ${MatrixPath}/${MatrixHead}
	g++ ${INCLUDE} -c ${MatrixPath}/${MatrixSource}

${ComplexObject}: ${ComplexPath}/${ComplexSource}  ${ComplexPath}/${ComplexHead}
	g++ ${INCLUDE} -c ${ComplexPath}/${ComplexSource}

clean:
	${DEL} *.o