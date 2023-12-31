#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added successfully.\n";
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void displayTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Task List:\n";
            for (int i = 0; i < tasks.size(); ++i) {
                std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] ";
                std::cout << i + 1 << ". " << tasks[i].description << "\n";
            }
        }
    }

    void removeCompletedTasks() {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
            [](const Task& task) { return task.completed; }), tasks.end());
        std::cout << "Completed tasks removed.\n";
    }
};

int main() {
    TaskManager taskManager;

    // Example: Adding tasks
    taskManager.addTask("Implement feature A");
    taskManager.addTask("Fix bug in module B");
    taskManager.addTask("Write documentation for project");

    // Example: Displaying tasks
    taskManager.displayTasks();

    // Example: Marking a task as completed
    taskManager.markTaskAsCompleted(1);

    // Example: Displaying tasks after marking one as completed
    taskManager.displayTasks();

    // Example: Removing completed tasks
    taskManager.removeCompletedTasks();

    // Example: Displaying tasks after removing completed tasks
    taskManager.displayTasks();

    return 0;
}
