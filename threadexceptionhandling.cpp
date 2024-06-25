#include <iostream>
#include <thread>


//Each thread has its own execution stack
//If the thread goes to the top of execution stack, where it cant find the handler, then it will terminate entire program
//in std::thread class, catch  has to be handled where the exception is thrown.
//Correct coding
void hello()
{
    try
    {
        throw std::exception();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
    
    std::cout << "Hello world" <<  "\n";
}

//void hello()
//{
      //throw std::exception();
      //std::cout << "Hello world" << "\n";
//}

int main()
{
    std::thread t(hello);
    t.join();
    
    std::cout << "Finished";
    return 0;
}
