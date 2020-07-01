#include <boost/signals2.hpp>
#include <iostream>

class button
{
public:
    template <class Handler>
    void add_handler(Handler h)
    {
        click_.connect(h);
    }

    template <class Handler>
    void remove_handler(Handler h)
    {
        click_.disconnect(h);
    }

    void click()
    {
        click_();
    }

private:
    boost::signals2::signal<void()> click_;
};

void click_handler()
{
    std::cout << "Clicked!\n";
}

int main()
{
    button btn;
    btn.add_handler(click_handler);
    btn.click();
    btn.remove_handler(click_handler);
    btn.click();
}
