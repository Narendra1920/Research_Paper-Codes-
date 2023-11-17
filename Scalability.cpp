#include <iostream>
#include <vector>
#include <future>
#include <chrono>

// Simulated asynchronous task (connection handling)
void handleConnection(int connectionID) {
    std::cout << "Handling Connection " << connectionID << std::endl;
    // Simulate processing time
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Connection " << connectionID << " processed." << std::endl;
}

int main() {
    const int totalConnections = 10;

    // Start handling connections asynchronously
    std::vector<std::future<void>> futures;
    for (int i = 1; i <= totalConnections; ++i) {
        futures.push_back(std::async(std::launch::async, handleConnection, i));
    }

    // Continue with other tasks while asynchronous connections are being handled
    for (int i = 0; i < 3; ++i) {
        std::cout << "Main thread is doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for all asynchronous connections to complete
    for (auto& future : futures) {
        future.get();
    }

    // Display a message once all connections are processed
    std::cout << "All asynchronous connections handled." << std::endl;

    return 0;
}
