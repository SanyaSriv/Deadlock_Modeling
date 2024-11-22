INCLUDEPATH = ../cmurphi-master/include
SRCPATH = ../cmurphi-master/src/

CXX = g++

CFLAGS = 

# optimization
OFLAGS = -ggdb
#OFLAGS = -O2

#Murphi options
MURPHIOPTS = -b -c

QueueClearFirst: QueueClearFirst.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o QueueClearFirst QueueClearFirst.cpp -I${INCLUDEPATH} -lm

QueueClearFirst.cpp: QueueClearFirst.m
	${SRCPATH}mu ${MURPHIOPTS} QueueClearFirst.m

clean:
	rm -f \
	QueueClearFirst.cpp QueueClearFirst
