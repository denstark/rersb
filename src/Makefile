CXX=g++
OPTS=-Wall -g
OBJS=rersb.o rersbDisplay.o
LIBS=-lmrss -lncurses

rersb: ${OBJS}
	${CXX} ${OPTS} ${LIBS} -o $@ ${OBJS}

rersb.o: rersb.cc
	${CXX} ${OPTS} -c rersb.cc

rersbDisplay.o: rersbDisplay.h rersbDisplay.cc
	${CXX} ${OPTS} -c rersbDisplay.cc

clean:
	rm *.o