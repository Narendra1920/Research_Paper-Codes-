#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<int> sharedCounter(0);

// Function representing a lock-free increment operation
void incrementCounter(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Atomic increment operation without the need for locks
        int oldValue = sharedCounter.load(std::memory_order_relaxed);
        while (!sharedCounter.compare_exchange_weak(oldValue, oldValue + 1, std::memory_order_relaxed))
            ; // Retry if the value has changed

        std::cout << "Thread " << id << ": Incremented Counter to " << sharedCounter.load() << std::endl;

        // Simulate some non-critical work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    const int numThreads = 3;
    const int iterationsPerThread = 5;

    std::vector<std::thread> threads;

    // Launch threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementCounter, i + 1, iterationsPerThread);
    }

    // Join threads to wait for their completion
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Final Counter Value: " << sharedCounter.load() << std::endl;

    return 0;
}
