#include "TaskManager.h"

void TaskManager::addTask(const Task& task) {
    taskQueue.push(task);
}

Task TaskManager::getNextTask() {
    Task top = taskQueue.top();
    taskQueue.pop();
    return top;
}

bool TaskManager::isEmpty() const {
    return taskQueue.empty();
}
