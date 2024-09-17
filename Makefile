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

clean:
	rm -f simple.cpp simple simple_combined_res_req_buf.cpp simple_combined_res_req_buf simple_combined_res_req_buf2.cpp simple_combined_res_req_buf2 token.cpp token
