#include <iostream>
#include <thread>
#include <vector>

//global variable
int gVar = 0;
 
void increment()
{
    for (int i = 0; i < 100000; i++)
        gVar++;
}
 
int main()
{
    //defined multiple threads -- here four threads
    std::vector<std::thread> threadVect;
    for (int i = 0; i < 4; i++)
    {       
        std::thread t(increment);
        threadVect.push_back(std::move(t));
    }

    //joined the threads
    for (int i = 0 ; i< threadVect.size(); i++)
        threadVect[i].join();

    //each time output will be different due to multiple threads accessinng the global variable gVar. This condition is called data race.
    std::cout << "Value of global variable is " << gVar;
    return 0;
}
