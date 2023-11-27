#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Simulated time-consuming task
int timeConsumingTask() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 42;
}

int main() {
    // Start the time-consuming task asynchronously
    std::future<int> futureResult = std::async(std::launch::async, timeConsumingTask);

    // While the task is running, the main thread can perform other operations
    for (int i = 0; i < 5; ++i) {
        std::cout << "Main thread is doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for the asynchronous task to complete and retrieve the result
    int result = futureResult.get();

    // Display the result once the task is finished
    std::cout << "Asynchronous task completed. Result: " << result << std::endl;

    return 0;
}
