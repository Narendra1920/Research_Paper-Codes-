#include <iostream>
#include <thread>
#include <chrono>

// Simulate a time-consuming task
void computeTask() {
    std::cout << "Computing Task started..." << std::endl;
    // Simulate a computationally intensive task
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Computing Task completed!" << std::endl;
}

// Handle user input in a separate thread
void userInputTask() {
    std::cout << "Enter something: ";
    std::string userInput;
    std::cin >> userInput;
    std::cout << "You entered: " << userInput << std::endl;
}

int main() {
    // Start the computationally intensive task in a separate thread
    std::thread computeThread(computeTask);

    // Handle user input in the main thread
    userInputTask();

    // Wait for the computing thread to finish
    computeThread.join();

    std::cout << "Main thread continues execution..." << std::endl;

    return 0;
}
