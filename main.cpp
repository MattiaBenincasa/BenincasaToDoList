#include <iostream>
#include "List.h"
#include "InvalidDate.h"
#include "TasksList.h"

int TasksList::total = 0;

int main() {

    TasksList system;
    std::string listName;
    int choice;
    std::string name, description;
    int day, month, year, hour, min;
    char slash, points;
    std::cout << "\t\t |To Do List|" << std::endl << std::endl;
    std::cout << "Lists of the user:" << std::endl;
    system.printLists();
    std::cout << "Total tasks: " << system.getTotal() << std::endl;
    do {
        std::cout << "----------------" << std::endl;
        std::cout << "Select an option" << std::endl;
        std::cout << "1 - add a task" << std::endl;
        std::cout << "2 - remove a task" << std::endl;
        std::cout << "3 - mark as completed" << std::endl;
        std::cout << "4 - mark as not completed" << std::endl;
        std::cout << "5 - save tasks" << std::endl;
        std::cout << "6 - Create a list" << std::endl;
        std::cout << "7 - Remove a list" << std::endl;
        std::cout << "8 - Print all lists" << std::endl;
        std::cout << "9 - Exit" << std::endl;

        std::cout << "-------------------------" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:{
                std::cout << "Insert the name of the list" << std::endl;
                std::cin >> listName;
                std::cout << "Insert a name for the task" << std::endl;
                std::cin >> name;
                std::cout << "Insert a description for the task" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                Date date;
                while(!date.getValid()){
                    try {
                        std::cout << "Date of the task [dd/mm/yy]" << std::endl;
                        std::cin >> day >> slash >> month >> slash >> year;
                        date.setYear(year);
                        date.setMonth(month);
                        date.setDay(day);
                    }catch (const InvalidDate& e){
                        std::cerr << "ERROR! " << e.what() << std::endl;
                    }
                }
                Clock time;
                while (!time.getValid()) {
                    try {
                        std::cout << "Time of the task [hh:mm] " << std::endl;
                        std::cin >> hour >> points >> min;
                        time.setMinute(min);
                        time.setHour(hour);
                    } catch  (const InvalidTime& e){
                        std::cerr << "ERROR! " << e.what() << std::endl;
                    }
                }
                Task task(name, description, date, time);
                system.addTask(listName, task);
                system.printTasks(listName);
                break;
            }
            case 2:{
                std::cout << "Insert the name of the list" << std::endl;
                std::cin >> listName;
                std::cout << "Insert the name of the task you want to delete" << std::endl;
                std::cin >> name;
                system.removeTask(name, listName);
                system.printTasks(listName);
                break;
            }
            case 3:{
                std::cout << "Insert the name of the list" << std::endl;
                std::cin >> listName;
                std::cout << "Insert the name of the task you want to mark as completed" << std::endl;
                std::cin >> name;
                system.markTaskCompleted(name, listName);
                system.printTasks(listName);
                break;
            }
            case 4:{
                std::cout << "Insert the name of the list" << std::endl;
                std::cin >> listName;
                std::cout << "Insert the name of the task you want to mark as not completed" << std::endl;
                std::cin >> name;
                system.markTaskNotCompleted(name, listName);
                system.printTasks(listName);
                break;
            }
            case 5:{
                system.save();
                break;
            }
            case 6:{
                std::cout << "Insert the name of the list you want to create" << std::endl;
                std::cin >> listName;
                List list(listName);
                system.addList(list);
                system.printLists();
                break;
            }
            case 7:
                std::cout << "Insert the name of the list you want to remove" << std::endl;
                std::cin >> listName;
                system.removeList(listName);
                system.removeListFile();
                system.printLists();
                break;
            case 8:
                system.printLists();
                std::cout << "Total tasks: " << system.getTotal() << std::endl;
                break;
            case 9:
                break;
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }while(choice != 9);
    return 0;
}