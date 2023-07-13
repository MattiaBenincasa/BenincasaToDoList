#include <iostream>
#include "User.h"

int main() {
    User user;
    int choice;
    std::string name, description;
    int day, month, year, hour, min;
    char slash, points;
    std::cout << "To Do List" << std::endl << std::endl;

    do {
        std::cout << "Select an option" << std::endl;
        std::cout << "1 - add a task" << std::endl;
        std::cout << "2 - remove a task" << std::endl;
        std::cout << "3 - Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:{
                std::cout << "Insert a name for the task" << std::endl;
                std::cin >> name;
                std::cout << "Insert a description for the task" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                std::cout << "Date of the task " << std::endl;
                std::cin >> day >> slash >> month >> slash >> year;
                std::cout << "Time of the task " << std::endl;
                std::cin >> hour >> points >> min;
                Date date(day, month, year);
                Clock time(hour, min);
                Task task(name, description, date, time);
                user.addTask(task);
                user.printTasks();
                break;
            }
            case 2:{
                std::cout << "Insert the name of the task you want to delete" << std::endl;
                std::cin >> name;
                user.removeTask(name);
                user.printTasks();
                break;
            }
            case 3:{
                break;
            }
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }while(choice != 3);
    return 0;
}
