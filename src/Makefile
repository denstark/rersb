CXX=g++
OPTS=-Wall -g
OBJS=main.o
LIBS=-lmrss

rersb: ${OBJS}
	${CXX} ${OPTS} ${LIBS} -o $@ ${OBJS}

main.o: main.cc
	${CXX} ${OPTS} -c main.cc

clean:
	rm *.o