//
// Created by Mattia Benincasa on 11/07/23.
//

#include "User.h"

User::User() {

    std::ifstream inFile;
    inFile.open("ToDoList.data");
    if(!inFile)
        return;

    while (!inFile.eof()){
        Task task;
        inFile >> task;
        tasks.insert(std::pair<std::string, Task>(task.getName(), task));
    }

    inFile.close();
}

void User::addTask(const Task& newTask) {
    tasks.insert(std::make_pair(newTask.getName(), newTask));

    std::ofstream  outFile;
    outFile.open("ToDoList.data", std::ios::app);

    for(auto &task : tasks)
        outFile << task.second;

    outFile.close();
}

void User::removeTask(std::string &n) {
    auto findTask = tasks.find(n);
    tasks.erase(findTask);
}

void User::markCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    findTask->second.isCompleted();
}

void User::markNotCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    findTask->second.notCompleted();
}

void User::printTasks() const {
    for(auto task : tasks)
        std::cout << task.second;
}