#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

// Function to simulate an image processing task
void processImage(const std::string& imageName, int threadId) {
    // Simulate image processing
    std::cout << "Thread " << threadId << " processing image: " << imageName << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulating processing time
    std::cout << "Thread " << threadId << " completed processing for: " << imageName << std::endl;
}

int main() {
    // List of images to be processed
    std::vector<std::string> imageList = {"image1.jpg", "image2.jpg", "image3.jpg", "image4.jpg", "image5.jpg"};

    // Specify the number of threads to use
    const int numThreads = 3;

    // Create vector to store thread objects
    std::vector<std::thread> threads;

    // Launch threads for image processing
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([i, &imageList]() {
            // Each thread processes a subset of images
            for (std::size_t j = i; j < imageList.size(); j += numThreads) {
                processImage(imageList[j], i);
            }
        });
    }

    // Join the threads to wait for their completion
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
