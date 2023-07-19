//
// Created by Mattia Benincasa on 18/07/23.
//

#ifndef BENINCASATODOLIST_TASKSLIST_H
#define BENINCASATODOLIST_TASKSLIST_H
#include <list>
#include "List.h"
#include <string>
#include <fstream>

class TasksList {
public:

    TasksList();

    static int getTotal() {
        return total;
    }

    static void incTotal(){
        total++;
    }

    static void decrTotal(){
        total--;
    }

    std::list<List> getList() const {
        return lists;
    }

    void addList(const List& list);
    void removeList(std::string& name);
    void removeListFile();
    void printLists() const;
    void save() const;

    List& getList(std::string& listName) {
        auto findList = std::find(lists.begin(), lists.end(), listName);
        return *findList;
    }


private:
    std::list<List> lists;
    static int total;
};

#endif //BENINCASATODOLIST_TASKSLIST_H
