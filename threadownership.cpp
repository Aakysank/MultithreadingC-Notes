#include <iostream>
#include <thread>
#include <chrono>

//threads follow RAII idiom, so threads cannot be copied, threads can only be moved.
//std::thread is implemented using RAII, similar to std::unique_ptr, std::fstream.
//The constructor acquires the resource
//The destructor deletes the resource
//An std::thread obj has ownership of execution thread.

//due to this, the std::thread obj can be moved, not copied. move operations help in achieving the transfer of ownership of execution thread
//the moved from object is not associated with the execution thread (after std::move is called)
void hello()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Hello World!\n";
}
//function taking thread object as argument 
//the object must be moved inside the argument
void func(std::thread&& t)
{
    std::cout << "Received thread ID: "<< t.get_id() << "\n";
    //The function argument now owns the system thread (used std::move), 
    ///It is responsible to call join.
    t.join();
}
int main()
{
    std::thread thr(hello);
    
    //Display the child thread ID
    std::cout << "Hello thread has ID: " << thr.get_id() << "\n";

    //moving the thread by rvalue reference
    func(std::move(thr));
    return 0;
}
