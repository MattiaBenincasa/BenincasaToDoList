#include <iostream>
#include "User.h"
#include "InvalidDate.h"

int main() {
    User user;
    int choice;
    std::string name, description;
    int day, month, year, hour, min;
    char slash, points;
    std::cout << "\t\t |To Do List|" << std::endl << std::endl;
    std::cout << "TASK NOT COMPLETED:" << std::endl;
    user.printTasks();
    do {
        std::cout << "----------------" << std::endl;
        std::cout << "Select an option" << std::endl;
        std::cout << "1 - add a task" << std::endl;
        std::cout << "2 - remove a task" << std::endl;
        std::cout << "3 - mark as completed" << std::endl;
        std::cout << "4 - mark as not completed" << std::endl;
        std::cout << "5 - Exit" << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:{
                std::cout << "Insert a name for the task" << std::endl;
                std::cin >> name;
                std::cout << "Insert a description for the task" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, description);
                Date date;
                while(!date.getValid()){
                    try {
                        std::cout << "Date of the task " << std::endl;
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
                        std::cout << "Time of the task " << std::endl;
                        std::cin >> hour >> points >> min;
                        time.setMinute(min);
                        time.setHour(hour);
                    } catch  (const InvalidTime& e){
                        std::cerr << "ERROR! " << e.what() << std::endl;
                    }
                }
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
                std::cout << "Insert the name of the task you want to mark as completed" << std::endl;
                std::cin >> name;
                user.markCompleted(name);
                user.printTasks();
                break;
            }
            case 4:{
                std::cout << "Insert the name of the task you want to mark as not completed" << std::endl;
                std::cin >> name;
                user.markNotCompleted(name);
                user.printTasks();
                break;
            }
            case 5:{
                break;
            }
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }while(choice != 5);
    return 0;
}