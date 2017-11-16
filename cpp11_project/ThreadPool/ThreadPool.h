#include <functional>
#include <list>
#include <thread>
#include <memory>
#include <atomic>
#include "SyncQueue.h"

class ThreadPool {
public:
    using Task = std::function<void()>;
    // initialize the size of thread pool based on thread_number
    ThreadPool(int thread_numbers);

    // call Stop()
    ~ThreadPool();


    void AddTask(const Task& task);
    void AddTask(Task&& task);

    // Stop()
    void Stop();

private:
    // initialize threads in loop
    void Start(int thread_num);

    // the function run in thread
    void RunInThread();

    // Stop the threads in pool
    void StopThreadPool();
    
private:
    std::list<std::shared_ptr<std::thread> > thread_pool_;
    SyncQueue<Task> queue_;
    std::atomic_bool running_;
    std::once_flag flag_;
};