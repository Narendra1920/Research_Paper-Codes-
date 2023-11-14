#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

// Function to calculate the sum of elements in a subarray
template <typename Iterator>
int parallelSum(Iterator begin, Iterator end) {
    return std::accumulate(begin, end, 0);
}

int main() {
    // Create a large array of integers
    const int arraySize = 10000000;
    std::vector<int> dataArray(arraySize, 1); // Initialize each element to 1

    // Specify the number of threads to use
    const int numThreads = 4;

    // Calculate the range of elements each thread will process
    const int chunkSize = arraySize / numThreads;
    
    // Vector to store thread objects
    std::vector<std::thread> threads;

    // Vector to store partial sums calculated by each thread
    std::vector<int> partialSums(numThreads, 0);

    // Launch threads to calculate partial sums in parallel
    for (int i = 0; i < numThreads; ++i) {
        auto start = dataArray.begin() + i * chunkSize;
        auto end = (i == numThreads - 1) ? dataArray.end() : start + chunkSize;

        threads.emplace_back([start, end, &partialSums, i]() {
            // Calculate partial sum for the assigned range
            partialSums[i] = parallelSum(start, end);
        });
    }

    // Join the threads to wait for their completion
    for (auto& thread : threads) {
        thread.join();
    }

    // Calculate the final sum using the partial sums
    int totalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0);

    // Output the result
    std::cout << "Parallel Sum: " << totalSum << std::endl;

    return 0;
}