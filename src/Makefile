CXX=g++
OPTS=-Wall -g
OBJS=rersb.o
LIBS=-lmrss

rersb: ${OBJS}
	${CXX} ${OPTS} ${LIBS} -o $@ ${OBJS}

rersb.o: rersb.cc
	${CXX} ${OPTS} -c rersb.cc

clean:
	rm *.o