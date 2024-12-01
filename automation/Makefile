INCLUDEPATH = ../cmurphi-master/include
SRCPATH = ../cmurphi-master/src/

CXX = g++

CFLAGS = 

# optimization
OFLAGS = -ggdb
#OFLAGS = -O2

#Murphi options
MURPHIOPTS = -b -c

skeleton: skeleton.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o skeleton skeleton.cpp -I${INCLUDEPATH} -lm

skeleton.cpp: skeleton.m
	${SRCPATH}mu ${MURPHIOPTS} skeleton.m

p: p.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o p p.cpp -I${INCLUDEPATH} -lm

p.cpp: p.m
	${SRCPATH}mu ${MURPHIOPTS} p.m


clean:
	rm -f \
	skeleton.cpp skeleton \
	p.cpp p
