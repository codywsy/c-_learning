CC = g++

DEP_LDFLAGS = /usr/local/lib

DEP_LDLIBS = -levent_core -lpthread

TARGET = Server Client

all: $(TARGET)

Server: Server.cpp
	$(CC) -g $^ -o bin/$@ --std=c++11 \
	-L$(DEP_LDFLAGS) $(DEP_LDLIBS)

Client: Client.cpp
	$(CC) -g $^ -o bin/$@ --std=c++11 \
	-L$(DEP_LDFLAGS) $(DEP_LDLIBS)

.PHONY : all clean

clean: 
	rm -f $(TARGET)
	


