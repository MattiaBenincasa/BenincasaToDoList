//
// Created by Mattia Benincasa on 11/07/23.
//

#include "List.h"
#include "TasksList.h"

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

bool List::addTask(const Task& newTask, const std::string& n) {
    if(name == n){
        tasks.insert(std::make_pair(newTask.getName(), newTask));
        std::ofstream outFile;
        outFile.open(name + ".data", std::ios::app);

        outFile << newTask;
        outFile.close();
        TasksList::incTotal();
        return true;
    }else {
        std::cout << "List not found" << std::endl;
        return false;
    }
}

bool List::removeTask(const std::string &taskName, const std::string& listName) {
    if(name == listName) {
        auto findTask = tasks.find(taskName);
        if(findTask == tasks.end()) {
            std::cout << "Task not found" << std::endl;
            return false;
        }
        else {
            tasks.erase(findTask);
            TasksList::decrTotal();
            return true;
        }
    }else {
        std::cout << "List not found" << std::endl;
        return false;
    }
}

bool List::markCompleted(const std::string &taskName, const std::string& listName) {
    if(name == listName){
        auto findTask = tasks.find(taskName);
        if(findTask == tasks.end()){
            std::cout << "Task not found" << std::endl;
            return false;
        }
        else{
            findTask->second.isCompleted();
            return true;
        }
    }else {
        std::cout << "List not found" << std::endl;
        return false;
    }
}

bool List::markNotCompleted(const std::string &taskName, const std::string& listName) {
    if(name == listName) {
        auto findTask = tasks.find(taskName);
        if(findTask == tasks.end()){
            std::cout << "Task not found" << std::endl;
            return false;
        }
        else{
            findTask->second.notCompleted();
            return true;
        }
    }else{
        std::cout << "List not found" << std::endl;
        return false;
    }

}

bool List::printTasks(const std::string& n) const {
    if(name == n) {
        std::cout << "------------------" << std::endl;
        for (auto &task: tasks)
            std::cout << task.second;
        return true;
    }else {
        std::cout << "No list to show" << std::endl;
        return false;
    }
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

bool List::operator==(const List& list) const{
    if(name == list.name)
        return true;
    else return false;
}

std::ifstream& operator >> (std::ifstream & ifs, List& list) {
    ifs >> list.name;
    int size = list.getSize();
    ifs >> size;
    return ifs;
}

bool List::findTask(const std::string &n) {
    auto findTask = tasks.find(n);
    if(findTask != tasks.end())
        return true;
    else
        return false;
}