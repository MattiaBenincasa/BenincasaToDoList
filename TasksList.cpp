//
// Created by Mattia Benincasa on 18/07/23.
//
#include "TasksList.h"

void TasksList::addList(const List &list) {
    lists.push_back(list);
    total += list.getSize();
    for (auto& task : list.getTasks())
        if(!task.second.getCompleted())
            notCompleted++;
}

void TasksList::removeList(std::string& name) {
    auto findList = std::find(lists.begin(), lists.end(), name);
    total -= findList->getSize();
    for (auto& task : findList->getTasks())
        if(!task.second.getCompleted())
            notCompleted--;
}

List& TasksList::getList(std::string &name) {
    auto findList = std::find(lists.begin(), lists.end(), name);
    return *findList;
}

void TasksList::printLists() const {
    for(auto& list : lists)
        std::cout << list.getName() << std::endl;
}

void TasksList::printTasks(std::string& listName) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    (*findList).printTasks();
}

void TasksList::addTask(std::string &listName, const Task& task) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    (*findList).addTask(task);
}

