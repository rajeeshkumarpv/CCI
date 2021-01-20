#include <iostream>
#include <string>
#include <stdlib.h>
#include "Client.h"
#include<unistd.h>
int main()
{
    std::cout<<"Initializing thread"<<std::endl;
    Client cl[2];
    cl[0].start();
    cl[1].start();
    int i=0;
   
    while(i<10)
    {
        std::string data = std::to_string(i);
        
        if(i%2)
        {
std::cout<<"data odd: "<<i<<std::endl;
            cl[1].push(data);
        }
        else{
std::cout<<"data even: "<<i<<std::endl;
        cl[0].push(data);
        }
        i++;
       usleep(200);
}
return 0;
}
