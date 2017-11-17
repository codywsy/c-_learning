ThreadPoolTest: ThreadPool.o
	g++ Main.cpp ThreadPool.o -o ThreadPoolTest -std=c++11 -lpthread
ThreadPool.o:
	g++ -c ThreadPool.cpp -std=c++11 

.PHONY: clean

clean:
	-rm ThreadPoolTest ThreadPool.o
