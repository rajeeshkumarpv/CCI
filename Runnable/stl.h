#include <queue>
#include <mutex>
#include <condition_variable>
template <class T>
class stlque
{
    std::queue<T> m_queue;
    std::mutex m_mutexQueue;
    std::condition_variable cv;
    public:
    void push(T);
   void pop(T &t);
};

template<class T>
void stlque<T>:: push(T data)
{
    
    std::unique_lock<std::mutex> lk(m_mutexQueue);
    
    m_queue.push(data);
    lk.unlock();
    cv.notify_one();
}
template<class T>
void stlque<T>::pop(T& t)
{
    
    std::unique_lock<std::mutex> lk(m_mutexQueue);
    cv.wait(lk);
t = m_queue.front();
    m_queue.pop();
    lk.unlock();
//return true;
}



