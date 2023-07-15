//
// Created by Mattia Benincasa on 11/07/23.
//

#include "User.h"

User::User() {

    readFile();
}

void User::readFile() {
    std::string fileName = "ToDoList.data";
    std::ifstream fin;
    fin.open("ToDoList.data");
    if(!fin)
        return;
    Task task;
    std::string line;
    if(fin.is_open()){
        while (fin.good()) {
            fin >> task;
            tasks.insert(std::make_pair(task.getName(), task));
        }
        fin.close();
    }
}

void User::addTask(const Task& newTask) {
    tasks.insert(std::make_pair(newTask.getName(), newTask));

    std::ofstream outFile;
    outFile.open("ToDoList.data", std::ios::app);

    outFile << newTask;
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
    for(auto &task : tasks)
        std::cout << task.second;
}

User::~User() {
    std::ofstream outFile;
    outFile.open("ToDoList.data", std::ios::trunc);
    for(auto& task : tasks)
        outFile << task.second;

    outFile.close();
}