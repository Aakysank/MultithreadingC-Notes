#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
std::timed_mutex mt;
void task1()
{
  std::cout << "Task 1 is trying to lock the mutex" << std::endl;
  
  mt.lock();
  std::cout << "Task 1 has successfully locked the mutex" << std::endl;s
  std::this_thread::sleep_for(std::chrono::seconds(5));
  mt.unlock();
  std::cout << "Task 1 has successfully unlocked the mutex" << std::endl;
  return;
}

void task2()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Task 2 is trying to lock the mutex" << std::endl;
  while (!mt.try_lock_for(std::chrono::seconds(1)))
    std::cout << "Task 2 is unable to lock the mutex" << std::endl;

  std::cout << "Task 2 has successfully locked the mutex" << std::endl;
  mt.unlock();
  std::cout << "Task 2 has successfully unlocked the mutex" << std::endl;
  return;
}

int main()
{
  std::thread t1(task1), t2(task2);
  t1.join();
  t2.join();
  return 0;
}
