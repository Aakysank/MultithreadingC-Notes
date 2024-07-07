#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::recursive_mutex rmutex;

int bad_factorial(int n)
{
    if (n <= 1)
    {
        std::cout << "Returning 1" << std::endl;
        return 1;
    }
    
    std::lock_guard<std::recursive_mutex> lck_grd(rmutex);
    int retval = n * bad_factorial(n-1);
    std::cout << "Returning " << retval << std::endl;
    return retval;
}
int main()
{
    std::thread t1(bad_factorial,10);
    std::thread t2(bad_factorial, 11);
    
    t1.join();
    t2.join();
    return 0;
}
