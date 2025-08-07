#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <queue>
#include <string>

struct Task {
    std::string name;
    int priority;

    Task(const std::string& n, int p) : name(n), priority(p) {}

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

class TaskManager {
private:
    std::priority_queue<Task> taskQueue;

public:
    void addTask(const Task& task);
    Task getNextTask();
    bool isEmpty() const;
};

#endif
