#include "Runnable.h"
#include "stl.h"
#include <string>
class Client:public Runnable
{
    stlque<std::string> m_queue;
    public:
        Client()
        {
        }
        ~Client()
        {
        }
        void push(std::string data)
        {
            m_queue.push(data);
        }
    void run()
    {
        std::string data;
        while(1)
        {
            m_queue.pop(data);
            std::cout<<"Data:"<<data<<std::endl;
 std::cout<<"running..................."<<this<<std::endl;

        }
    std::cout<<"running..................."<<this<<std::endl;
    }
};
