//
// Created by Mattia Benincasa on 18/07/23.
//
#include "TasksList.h"

TasksList::TasksList() {
    std::string nameFile = "Lists";
    read(nameFile);
}

TasksList::TasksList(const std::string& nameFile) {
    read(nameFile);
}

void TasksList::read(const std::string& nameFile) {
    std::ifstream fin;

    fin.open(nameFile + ".data");

    if(!fin)
        return;
    std::string name;
    int tasks;
    while (fin >> name && fin >> tasks){
        fin >> name;
        fin >> tasks;
        List list(name);
        lists.push_back(list);
        total+= tasks;
    }

    fin.close();
}

void TasksList::addList(const List &list) {
    lists.push_back(list);
    total += list.getSize();
    std::ofstream fout;
    fout.open("Lists.data", std::ios::app);
    fout << list.getName() << std::endl;
    fout << list.getSize() << std::endl;

    fout.close();
}

bool TasksList::removeList(const std::string& name) {
    auto findList = std::find(lists.begin(), lists.end(), name);
    if(findList != lists.end()){
        total -= findList->getSize();
        lists.remove(*findList);
        return true;
    }else
        return false;
}

void TasksList::removeListFile() {
    char name[20];
    std::cout << "Enter the name of the file of the list you want to delete with .data" << std::endl;
    std::cin >> name;
    bool result = remove(name);
    if(result)
        std::cout << "Successfully removed" << std::endl;
    else
        std::cout << "Error during the remove" << std::endl;

}

void TasksList::printLists() const {
    for(auto& list : lists)
        std::cout << list.getName() << std::endl;
}

void TasksList::save() const {
    std::ofstream fout;
    fout.open("Lists.data", std::ios::trunc);
    for( auto& list : lists){
        fout << list.getName() << std::endl;
        fout << list.getSize() << std::endl;
        list.saveTasks();
    }
}

bool TasksList::printTasks(const std::string &listName) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    return findList->printTasks(listName);
}

bool TasksList::addTask(const std::string &listName, const Task& task) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    return (*findList).addTask(task, listName);
}

bool TasksList::removeTask(const std::string& taskName, const std::string &listName) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    return findList->removeTask(taskName, listName);
}

bool TasksList::markTaskCompleted(const std::string &taskName, const std::string &listName) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    return findList->markCompleted(taskName, listName);
}

bool TasksList::markTaskNotCompleted(const std::string &taskName, const std::string &listName) {
    auto findList = std::find(lists.begin(), lists.end(), listName);
    return findList->markNotCompleted(taskName, listName);
}

bool TasksList::findList(const std::string &listName) {
    auto findTheList = std::find(lists.begin(), lists.end(), listName);
    if(findTheList!=lists.end())
        return true;
    else
        return false;
}