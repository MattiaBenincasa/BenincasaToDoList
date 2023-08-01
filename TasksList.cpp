//
// Created by Mattia Benincasa on 18/07/23.
//
#include "TasksList.h"

TasksList::TasksList() {
    std::ifstream fin;

    fin.open("Lists.data");

    if(!fin)
        return;
    std::string name;
    int tasks;
    while (fin >> name && fin >> tasks){
        fin >> name;
        fin >> tasks;
        List list(name);
        lists.push_back(list);
        total+= list.getSize();
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

void TasksList::removeList(std::string& name) {
    auto findList = std::find(lists.begin(), lists.end(), name);
    total -= findList->getSize();
    lists.remove(*findList);
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
