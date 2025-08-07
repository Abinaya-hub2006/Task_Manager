#include <iostream>
#include "TaskManager.h"

void displayMenu() {
    std::cout << "\nTask Management System\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Get Next Task\n";
    std::cout << "3. Check if Task Queue is Empty\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int getUserChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
    TaskManager taskManager;

    while (true) {
        displayMenu();
        int choice = getUserChoice();

        switch (choice) {
            case 1: {
                std::string name;
                int priority;
                std::cout << "Enter task name: ";
                std::cin >> name;
                std::cout << "Enter task priority (1-10): ";
                std::cin >> priority;

                if (priority < 1 || priority > 10) {
                    std::cout << "Invalid priority. Please enter a number between 1 and 10.\n";
                    break;
                }

                taskManager.addTask(Task(name, priority));
                std::cout << "Task added successfully.\n";
                break;
            }
            case 2: {
                if (!taskManager.isEmpty()) {
                    Task nextTask = taskManager.getNextTask();
                    std::cout << "Next Task: " << nextTask.name << " (Priority: " << nextTask.priority << ")\n";
                } else {
                    std::cout << "Task queue is empty.\n";
                }
                break;
            }
            case 3: {
                std::cout << (taskManager.isEmpty() ? "Task queue is empty.\n" : "Task queue is not empty.\n");
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
