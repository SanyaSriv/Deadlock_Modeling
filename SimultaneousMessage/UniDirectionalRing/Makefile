INCLUDEPATH = ../../cmurphi-master/include
SRCPATH = ../../cmurphi-master/src/

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

BoundedTokenOscillation: BoundedTokenOscillation.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o BoundedTokenOscillation BoundedTokenOscillation.cpp -I${INCLUDEPATH} -lm

BoundedTokenOscillation.cpp: BoundedTokenOscillation.m
	${SRCPATH}mu ${MURPHIOPTS} BoundedTokenOscillation.m

ProcessAndSend: ProcessAndSend.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o ProcessAndSend ProcessAndSend.cpp -I${INCLUDEPATH} -lm

ProcessAndSend.cpp: ProcessAndSend.m
	${SRCPATH}mu ${MURPHIOPTS} ProcessAndSend.m

LastSpaceNotRequest: LastSpaceNotRequest.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o LastSpaceNotRequest LastSpaceNotRequest.cpp -I${INCLUDEPATH} -lm

LastSpaceNotRequest.cpp: LastSpaceNotRequest.m
	${SRCPATH}mu ${MURPHIOPTS} LastSpaceNotRequest.m

clean:
	rm -f \
	QueueClearFirst.cpp QueueClearFirst \
	BoundedTokenOscillation.cpp BoundedTokenOscillation \
	ProcessAndSend.cpp ProcessAndSend \
	LastSpaceNotRequest.cpp LastSpaceNotRequest
