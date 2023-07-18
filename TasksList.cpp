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