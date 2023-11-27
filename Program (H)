#include <iostream>
#include <future>
#include <chrono>

// Simulated time-consuming task
int timeConsumingTask(int id, int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    return id * 10;
}

int main() {
    // Start multiple time-consuming tasks asynchronously
    std::future<int> result1 = std::async(std::launch::async, timeConsumingTask, 1, 3);
    std::future<int> result2 = std::async(std::launch::async, timeConsumingTask, 2, 5);
    std::future<int> result3 = std::async(std::launch::async, timeConsumingTask, 3, 2);

    // Continue with other tasks while asynchronous tasks are running
    for (int i = 0; i < 3; ++i) {
        std::cout << "Main thread is doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for the asynchronous tasks to complete and retrieve the results
    int resultValue1 = result1.get();
    int resultValue2 = result2.get();
    int resultValue3 = result3.get();

    // Display the results once the tasks are finished
    std::cout << "Task 1 Result: " << resultValue1 << std::endl;
    std::cout << "Task 2 Result: " << resultValue2 << std::endl;
    std::cout << "Task 3 Result: " << resultValue3 << std::endl;

    return 0;
}
