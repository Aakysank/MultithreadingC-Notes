#include <thread>
#include <iostream>
#include <chrono>

void func()
{
  // sleep the thread for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Hello world\n";
}

int main()
{
    std::cout << "Starting thread\n";
    std::thread thr(func);
    thr.join();
    
    std::cout << "Thread ends\n";
    return 0;
}
