#define BOOST_THREAD_VERSION 4
#include <boost/thread.hpp>
#include <boost/timer/timer.hpp>
#include <vector>
#include <atomic>
#include <iostream>
#include <cstdint>

std::atomic<std::uint64_t> total{ 0 };

void thread(int from, int to)
{
    std::uint64_t sum = 0;
    for (int i = from; i < to; ++i)
        sum += i;
    total += sum;
}

int main()
{
    int cores = boost::thread::hardware_concurrency();
    std::cout << "Cores: " << cores << '\n';
    int chunk = 1'000'000'000 / cores;

    boost::timer::cpu_timer timer;

    std::vector<boost::future<void>> futures;
    for (int i = 0; i < cores; ++i)
    {
        int from = i * chunk;
        int to = (i + 1) * chunk;
        futures.push_back(boost::async([from, to]{ thread(from, to); }));
    }
    boost::wait_for_all(futures.begin(), futures.end());

    std::cout << timer.format();
    std::cout << total << '\n';
}
