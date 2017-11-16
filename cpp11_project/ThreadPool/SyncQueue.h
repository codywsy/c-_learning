#include <mutex>
#include <list>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <memory>

template <typename T>
class SyncQueue
{
  public:
    SyncQueue(int maxSize) : max_size_(maxSize),
                             to_stop_(false)
    {
    }
    ~SyncQueue();

    void Put(const T& task)
    {
        Add(task);
    }

    void Put(T&& task)
    {
        Add(std::forward<T>(task));
    }

    // Add
    void Add(T &task)
    {
        std::unique_lock<std::mutex> lck(mutex_);
        not_full_.wait(lck, [this] { return to_stop_ || NotFull(); });
        if (to_stop_)
        {
            return;
        }

        queue_.push_back(task);
        not_empty_.notify_one();
    }

    // Take
    void Take(T &task)
    {
        std::unique_lock<std::mutex> lck(mutex_);
        not_empty_.wait(lck, [this] { return to_stop_ || NotEmpty(); });
        if (to_stop_)
        {
            return;
        }

        task = queue_.front();
        queue_.pop_front();
        not_full_.notify_one();
    }

    void Take(const std::list<T> &tasks)
    {
        std::unique_lock<std::mutex> lck(mutex_);
        not_empty_.wait(lck, [this] { return to_stop_ || NotEmpty(); });
        if (to_stop_)
        {
            return;
        }

        tasks = std::move(queue_);
        not_full_.notify_one();
    }

    // Stop
    void Stop()
    {
        {
            std::lock_guard<std::mutex> lck(mutex_);
            to_stop_ = true;
        }

        not_empty_.notify_all();
        not_full_.notify_all();
    }

    // IsEmpty
    bool IsEmpty()
    {
        std::lock_guard<std::mutex> lck(mutex_);
        return queue_.empty();
    }

    // IsFull
    bool Full()
    {
        std::lock_guard<std::mutex> lck(mutex_);
        return queue_.size() == max_size_;
    }

    size_t Size()
    {
        std::lock_guard<std::mutex> lck(mutex_);
        return queue_.size();
    }

    int Count()
    {
        return queue_.size();
    }

  private:
    bool NotEmpty()
    {
        bool empty = queue_.empty();
        if (empty)
        {
            std::cout << "Buffer is empty!" << std::endl;
        }
        return !empty;
    }

    bool NotFull()
    {
        bool full = (queue_.size() == max_size_);
        if (full)
        {
            std::cout << "Buffer is full!" << std::endl;
        }
        return !full;
    }

    // template<typename F>
    // void Add(F&& task){
    //     std::unique_lock<std::mutex> lck(mutex_);
    //     not_full_.wait(lck, [this]{return to_stop_ || NotFull();});
    //     if(to_stop_){
    //         return;
    //     }

    //     queue_.push_back(std::forward<F> (task));
    //     not_empty_.notify_one();
    // }

  private:
    std::list<T> queue_;
    std::mutex mutex_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;
    int max_size_;
    bool to_stop_;
};