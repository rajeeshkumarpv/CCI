#include<thread>

class Runnable
{

        std::thread m_thread;
    public:
        virtual void run()=0;
        Runnable()
        {
           
        }

        void start()
        {
            if(!m_thread.joinable())
            {
            m_thread=std::thread(&Runnable::run,this);
            }
        }
        ~Runnable()
        {
            if(m_thread.joinable())
            {
                m_thread.join();
            }
        }
};


