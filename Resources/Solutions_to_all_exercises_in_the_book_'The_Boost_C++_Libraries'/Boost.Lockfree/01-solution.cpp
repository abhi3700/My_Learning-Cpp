#include <queue>
#include <thread>
#include <mutex>
#include <iostream>

class queue
{
public:
    void push(int i)
    {
        std::lock_guard<std::mutex> l{ m };
        q.push(i);
    }

    bool pop(int &i)
    {
        std::lock_guard<std::mutex> l{ m };
        if (!q.empty())
        {
            i = q.front();
            q.pop();
            return true;
        }
        return false;
    }

private:
    std::mutex m;
    std::queue<int> q;
};

queue q;
int sum = 0;

void produce()
{
    for (int i = 1; i <= 100; ++i)
        q.push(i);
}

void consume()
{
    int i;
    while (q.pop(i))
        sum += i;
}

int main()
{
    std::thread t1{ produce };
    std::thread t2{ consume };
    t1.join();
    t2.join();
    consume();
    std::cout << sum << '\n';
}
