#include <functional>
#include <list>
#include <thread>
#include <memory>
#include <atomic>
#include "SyncQueue.h"

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

class ThreadPool {
 public:
  using Task = std::function<void()>;
  // initialize the size of thread pool based on thread_number
  ThreadPool(int thread_numbers = std::thread::hardware_concurrency());
  // XXX Notice: default argument in constructor should be declared in statment
  // or defination either.

  // call Stop()
  ~ThreadPool();

  // XXX There are different
  void AddTask(const Task &task);
  void AddTask(Task &&task);

  // Stop(). It used std::call_once
  void Stop();

 private:
  // initialize threads in loop
  void Start(int thread_num);

  // the function run in thread
  void RunInThread();

  // Stop the threads in pool
  void StopThreadPool();

 private:
  std::list<std::shared_ptr<std::thread>> thread_pool_;
  SyncQueue<Task> queue_;
  std::atomic_bool running_;
  // XXX ensure the function in std::call_once() is just called once in multi-thread env.
  std::once_flag flag_;
};

#endif
