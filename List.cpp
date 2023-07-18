//
// Created by Mattia Benincasa on 11/07/23.
//

#include "List.h"

List::List() {
    readFile();
}

List::List(std::string &n) : name(n) {
    readFile();
}

void List::readFile() {
    std::ifstream fin;
    fin.open(name + ".data");
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

void List::addTask(const Task& newTask) {
    tasks.insert(std::make_pair(newTask.getName(), newTask));

    std::ofstream outFile;
    outFile.open(name + ".data", std::ios::app);

    outFile << newTask;
    outFile.close();
}

void List::removeTask(std::string &n) {
    auto findTask = tasks.find(n);
    if(findTask == tasks.end())
        std::cout << "Task not found" << std::endl;
    else
        tasks.erase(findTask);
}

void List::markCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    if(findTask == tasks.end())
        std::cout << "Task not found" << std::endl;
    else
        findTask->second.isCompleted();
}

void List::markNotCompleted(std::string &n) {
    auto findTask = tasks.find(n);
    if(findTask == tasks.end())
        std::cout << "Task not found" << std::endl;
    else
        findTask->second.notCompleted();
}

void List::printTasks() const {
    std::cout << "------------------" << std::endl;
    for(auto &task : tasks)
        std::cout << task.second;
}

void List::saveTasks() const {
    std::ofstream outFile;
    outFile.open(name + ".data", std::ios::trunc);
    for(auto& task : tasks)
        outFile << task.second;

    outFile.close();
    std::cout << "Successfully saved!" <<std::endl;
}

bool List::operator==(const std::string &right) {
    if(name == right)
        return true;
    else
        return false;
}