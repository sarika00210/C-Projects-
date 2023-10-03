#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task task;
        task.description = description;
        task.completed = false;
        tasks.push_back(task);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks in the list:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        std::cout << "\nToDo List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear the newline character from the input buffer
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
