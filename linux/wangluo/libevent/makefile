CC=gcc
CXX=g++
LD_FLAG=-g
LIBS=-L/opt/libevent/lib -levent
INCLUDE=-I/opt/libevent/include

TARGET=test

${TARGET}:
	$(CXX) test.cpp $(LD_FLAG) $(LIBS) $(INCLUDE) -o $(TARGET)
clean:
	rm -rf *.o *~ $(TARGET)
