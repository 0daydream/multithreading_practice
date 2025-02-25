#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void taskFunction(int taskID) {
    std::cout << "Task: " << taskID << " is starting on thread " << std::this_thread::get_id() << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Task: " << taskID << " finished on thread " << std::this_thread::get_id() << "\n";
}

int main() {
    constexpr int numberOfTasks = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < numberOfTasks; i++) {
        threads.emplace_back(taskFunction, i);
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    std::cout << "All tasks completed.\n";
}
