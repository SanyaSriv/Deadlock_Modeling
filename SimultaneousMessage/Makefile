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

ProcessAndSend: ProcessAndSend.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o ProcessAndSend ProcessAndSend.cpp -I${INCLUDEPATH} -lm

ProcessAndSend.cpp: ProcessAndSend.m
	${SRCPATH}mu ${MURPHIOPTS} ProcessAndSend.m


clean:
	rm -f \
	QueueClearFirst.cpp QueueClearFirst
	ProcessAndSend.cpp ProcessAndSend
