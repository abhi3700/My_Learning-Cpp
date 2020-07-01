#define BOOST_THREAD_VERSION 4
#include <boost/thread.hpp>
#include <boost/timer/timer.hpp>
#include <atomic>
#include <iostream>
#include <cstdint>

std::atomic<std::uint64_t> total{ 0 };

void thread1()
{
    std::uint64_t sum = 0;
    for (int i = 0; i < 500'000'000; ++i)
        sum += i;
    total += sum;
}

void thread2()
{
    std::uint64_t sum = 0;
    for (int i = 500'000'000; i < 1'000'000'000; ++i)
        sum += i;
    total += sum;
}

int main()
{
    boost::timer::cpu_timer timer;

    auto f1 = boost::async(thread1);
    auto f2 = boost::async(thread2);
    boost::wait_for_all(f1, f2);

    std::cout << timer.format();
    std::cout << total << '\n';
}
