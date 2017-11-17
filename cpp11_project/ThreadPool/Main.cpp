#include <iostream>
#include <chrono>
#include <thread>
#include "SyncQueue.h"
#include "ThreadPool.h"

void TestThdPool() {
  ThreadPool pool(2);
  // XXX startup a thread
  std::thread thd1([&pool] {
    for(int i=0; i<10; ++i) {
      std::thread::id thdID = std::this_thread::get_id();
      pool.AddTask([thdID] {
            std::cout << "同步线程1的线程ID：" << thdID << std::endl;
          });
    }
  });

  // XXX startup a thread
  std::thread thd2([&pool] {
    for(int i=0; i<10; ++i) {
      auto thdID = std::this_thread::get_id();
      pool.AddTask([thdID] {
            std::cout << "同步线程2的线程ID：" << thdID << std::endl;
          });
    }
  });

  std::this_thread::sleep_for(std::chrono::seconds(2));
  getchar();
  pool.Stop();
  thd1.join();
  thd2.join();
}

int main(int argc, char* argv[]) {
  TestThdPool();
  return 0;
}
