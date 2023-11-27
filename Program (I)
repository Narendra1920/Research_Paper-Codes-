#include <iostream>
#include <fstream>
#include <future>
#include <chrono>

// Simulated asynchronous I/O operation
void asyncIOOperation(const std::string& filename, const std::string& data) {
    std::ofstream outputFile(filename);
    std::this_thread::sleep_for(std::chrono::seconds(3));  // Simulating I/O delay
    outputFile << data;
    outputFile.close();
}

int main() {
    // Start asynchronous I/O operations concurrently
    std::future<void> ioOperation1 = std::async(std::launch::async, asyncIOOperation, "file1.txt", "Data for File 1");
    std::future<void> ioOperation2 = std::async(std::launch::async, asyncIOOperation, "file2.txt", "Data for File 2");

    // Continue with other tasks while asynchronous I/O operations are running
    for (int i = 0; i < 3; ++i) {
        std::cout << "Main thread is doing some work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Wait for the asynchronous I/O operations to complete
    ioOperation1.get();
    ioOperation2.get();

    // Display a message once I/O operations are finished
    std::cout << "Asynchronous I/O operations completed." << std::endl;

    return 0;
}
