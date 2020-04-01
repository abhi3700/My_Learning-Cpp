/**
 * @brief Block the execution of a thread for a given amount of time.
 * @details used for pausing/delaying an execution.
 */
#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

int main() {
  std::chrono::milliseconds sleepDuration(20);
  std::this_thread::sleep_for(sleepDuration);
  std::this_thread::sleep_for(5s);	 // sleep for 5 seconds. For this `using` directive is required.

  return 0;
}

