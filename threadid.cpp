#include <thread>
#include <iostream>

void func()
{
    std::cout << "Hello world\n";
}

int main()
{
    std::thread thr(func);
    //id of main function thread will be displayed
    std::cout << "Id of main thread: "<<std::this_thread::get_id() << "\n";
    
     //id of thr thread will be displayed
    std::cout << "Id of thr thread: " << thr.get_id() << "\n";
    
    thr.join();

    //after the thread execution is ended with "join", the id of the thr thread is not valid, so 0 will be displayed.
    std::cout << "Id of thr thread: " << thr.get_id() << "\n";
}
