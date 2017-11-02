PolyPath := ..
PolyHead := poly.h
PolySource := poly.cpp
PolyObject := poly.o

SortLinkPath := ../../SortLink
SortLinkHead := sortlink.h

MatrixPath := ../../Matrix
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

INCLUDE := -I${PolyPath} -I${SortLinkPath} -I${MatrixPath} -I${ComplexPath}

DEL := rm
ifneq ($(shell uname), Linux)
	DEL = del
endif

${MainExe}: ${MainObject} ${PolyObject} ${MatrixObject} ${ComplexObject}
	g++ *.o -o ${MainExe}

${MainObject}: ${MainPath}/${MainSource} ${PolyPath}/${PolyHead}
	g++ ${INCLUDE} -c ${MainSource}

${PolyObject}: ${PolyPath}/${PolySource} ${PolyPath}/${PolyHead}
	g++ ${INCLUDE} -c ${PolyPath}/${PolySource}

${MatrixObject}: ${MatrixPath}/${MatrixSource} ${MatrixPath}/${MatrixHead}
	g++ ${INCLUDE} -c ${MatrixPath}/${MatrixSource}

${ComplexObject}: ${ComplexPath}/${ComplexSource} ${ComplexPath}/${ComplexHead}
	g++ ${INCLUDE} -c ${ComplexPath}/${ComplexSource}
 
clean:
	${DEL} *.o