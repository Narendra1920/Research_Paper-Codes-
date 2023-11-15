#include <iostream>
#include <thread>
#include <vector>

// Function representing an independent task (module)
void moduleFunction(int moduleId) {
    std::cout << "Module " << moduleId << " is starting." << std::endl;

    // Simulate some module-specific work
    for (int i = 0; i < 5; ++i) {
        std::cout << "Module " << moduleId << " is working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Module " << moduleId << " is completed." << std::endl;
}

int main() {
    // Create threads for each module
    std::vector<std::thread> threads;

    // Define the number of modules
    const int numModules = 3;

    // Launch threads for each module
    for (int i = 1; i <= numModules; ++i) {
        threads.push_back(std::thread(moduleFunction, i));
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Main thread: All modules are completed." << std::endl;

    return 0;
}

 
