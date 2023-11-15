#include <iostream>
#include <thread>
#include <chrono>

// Function representing a time-consuming task
void timeConsumingTask() {
    // Simulate a time-consuming task
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Task completed!" << std::endl;
}

int main() {
    // Create a thread for the time-consuming task
    std::thread taskThread(timeConsumingTask);

    // Inform the user that the task is running
    std::cout << "Task is running in the background. Please wait..." << std::endl;

    // Do some other work in the main thread (simulating responsiveness)
    for (int i = 0; i < 5; ++i) {
        std::cout << "Main thread doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for the task thread to finish
    taskThread.join();

    // Inform the user that the task is completed
    std::cout << "Main thread: Task completed in the background." << std::endl;

    return 0;
}
