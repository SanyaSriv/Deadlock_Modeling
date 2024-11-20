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

simple_combined_res_req_buf: simple_combined_res_req_buf.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o simple_combined_res_req_buf simple_combined_res_req_buf.cpp -I${INCLUDEPATH} -lm

simple_combined_res_req_buf.cpp: simple_combined_res_req_buf.m
	${SRCPATH}mu ${MURPHIOPTS} simple_combined_res_req_buf.m

simple_combined_res_req_buf2: simple_combined_res_req_buf2.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o simple_combined_res_req_buf2 simple_combined_res_req_buf2.cpp -I${INCLUDEPATH} -lm

simple_combined_res_req_buf2.cpp: simple_combined_res_req_buf2.m
	${SRCPATH}mu ${MURPHIOPTS} simple_combined_res_req_buf2.m

token: token.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o token token.cpp -I${INCLUDEPATH} -lm

token.cpp: token.m
	${SRCPATH}mu ${MURPHIOPTS} token.m

BaseModel: BaseModel.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o BaseModel BaseModel.cpp -I${INCLUDEPATH} -lm

BaseModel.cpp: BaseModel.m
	${SRCPATH}mu ${MURPHIOPTS} BaseModel.m


QueueClearFirst: QueueClearFirst.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o QueueClearFirst QueueClearFirst.cpp -I${INCLUDEPATH} -lm

QueueClearFirst.cpp: QueueClearFirst.m
	${SRCPATH}mu ${MURPHIOPTS} QueueClearFirst.m

ProcessAndSend: ProcessAndSend.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o ProcessAndSend ProcessAndSend.cpp -I${INCLUDEPATH} -lm

ProcessAndSend.cpp: ProcessAndSend.m
	${SRCPATH}mu ${MURPHIOPTS} ProcessAndSend.m

ProcessAndSend2: ProcessAndSend2.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o ProcessAndSend2 ProcessAndSend2.cpp -I${INCLUDEPATH} -lm

ProcessAndSend2.cpp: ProcessAndSend2.m
	${SRCPATH}mu ${MURPHIOPTS} ProcessAndSend2.m

LastSpaceEmpty: LastSpaceEmpty.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o LastSpaceEmpty LastSpaceEmpty.cpp -I${INCLUDEPATH} -lm

LastSpaceEmpty.cpp: LastSpaceEmpty.m
	${SRCPATH}mu ${MURPHIOPTS} LastSpaceEmpty.m

LocalTokens: LocalTokens.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o LocalTokens LocalTokens.cpp -I${INCLUDEPATH} -lm

LocalTokens.cpp: LocalTokens.m
	${SRCPATH}mu ${MURPHIOPTS} LocalTokens.m

GlobalTokens: GlobalTokens.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o GlobalTokens GlobalTokens.cpp -I${INCLUDEPATH} -lm

GlobalTokens.cpp: GlobalTokens.m
	${SRCPATH}mu ${MURPHIOPTS} GlobalTokens.m

LastSpaceNotRequest: LastSpaceNotRequest.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o LastSpaceNotRequest LastSpaceNotRequest.cpp -I${INCLUDEPATH} -lm

LastSpaceNotRequest.cpp: LastSpaceNotRequest.m
	${SRCPATH}mu ${MURPHIOPTS} LastSpaceNotRequest.m

QueueClearFirst_simul: QueueClearFirst_simul.cpp
	${CXX} ${CFLAGS} ${OFLAGS} -o QueueClearFirst_simul QueueClearFirst_simul.cpp -I${INCLUDEPATH} -lm

QueueClearFirst_simul.cpp: QueueClearFirst_simul.m
	${SRCPATH}mu ${MURPHIOPTS} QueueClearFirst_simul.m

clean:
	rm -f simple.cpp simple simple_combined_res_req_buf.cpp 
	simple_combined_res_req_buf simple_combined_res_req_buf2.cpp 
	simple_combined_res_req_buf2 token.cpp token 
	BaseModel.cpp BaseModel
	QueueClearFirst.cpp QueueClearFirst 
	ProcessAndSend.cpp ProcessAndSend
	ProcessAndSend2.cpp ProcessAndSend2
	LastSpaceEmpty.cpp LastSpaceEmpty
	LocalTokens.cpp LocalTokens
	GlobalTokens.cpp GlobalTokens
	LastSpaceNotRequest.cpp LastSpaceEmpty
	QueueClearFirst_simul.cpp QueueClearFirst_simul
