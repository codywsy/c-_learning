SHARE_LIB_PREFIX=/usr/local
CC=c++

all: 
	g++ --std=c++11 test.cpp -o test\ 
	-I/usr/local/include/mongocxx/v_noabi \ 
	#-I$(SHARE_LIB_PREFIX)/include/libmongoc-1.0 \ 
	-I/usr/local/include/bsoncxx/v_noabi \ 
	#-I$(SHARE_LIB_PREFIX)/include/libbson-1.0 \ 
	-L/usr/local/lib -lmongocxx -lbsoncxx 

clean: 
	rm -f test
	


