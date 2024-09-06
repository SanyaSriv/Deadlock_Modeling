INCLUDEPATH = cmurphi-master/include
SRCPATH = cmurphi-master/src/

CXX = g++

CFLAGS = 

# optimization
OFLAGS = -ggdb
#OFLAGS = -O2

#Murphi options
MURPHIOPTS = -b -c

simple: simple.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o simple simple.cpp -I${INCLUDEPATH} -lm

simple.cpp: simple.m
	${SRCPATH}mu ${MURPHIOPTS} simple.m

clean:
	rm -f simple.cpp simple
