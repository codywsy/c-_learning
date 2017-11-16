
#include "ThreadPool.h"


const int MaxTaskCount = 100;

    // initialize the size of thread pool based on thread_number
    ThreadPool::ThreadPool(int thread_number = std::thread::hardware_concurrency()):
        queue_(MaxTaskCount) {
        Start(thread_number);
    }

    // call Stop()
    ThreadPool::~ThreadPool(){
        Stop();
    }


    void ThreadPool::AddTask(const Task& task){
        queue_.Add(task);
    }

    void ThreadPool::AddTask(Task&& task){
        // forward rvalue quto perfectly
        queue_.Add(std::forward(task));
    }

    // Stop()
    void ThreadPool::Stop(){
        std::call_once(flag, [this]{this->StopThreadPool();});
    }

    // initialize threads in loop
    void ThreadPool::Start(int thread_num) {
        running_ = true;
        for(init i=0; i<thread_num; ++i){
            thread_pool_.push_back(std::make_shared<std::thread>(
                &ThreadPool::RunInThread, this));
        }
    }

    // the function run in thread
    void ThreadPool::RunInThread() {
        while(running_){
            // get task from queue
            std::list<Task> task;
            queue.Take(list);

            for(auto& task : list){
                if(!running_){
                    return; 
                }

                task();
            }
        }
    }

    // Stop the threads in pool
    void ThreadPool::sStopThreadPool() {
        queue_.Stop();
        running_ = false;

        for(auto thread : thread_pool_){
            if(thread){
                thread->join();
            }
        }
        thread_pool_.clear()
    }