#include <iostream>
#include "User.h"
#include "InvalidDate.h"

int main() {
    User user;
    int choice;
    std::string name, description;
    int day, month, year, hour, min;
    char slash, points;
    user.printTasks();
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
                try {
                    std::cout << "Date of the task " << std::endl;
                    std::cin >> day >> slash >> month >> slash >> year;
                    std::cout << "Time of the task " << std::endl;
                    std::cin >> hour >> points >> min;
                    Date date;
                    date.setYear(year);
                    date.setMonth(month);
                    date.setDay(day);
                    Clock time;
                    time.setMinute(min);
                    time.setHour(hour);
                    Task task(name, description, date, time);
                    user.addTask(task);
                    user.printTasks();
                }catch (InvalidDate& e){
                    std::cerr << "Date is not valid" << std::endl;
                }catch (InvalidTime& e){
                    std::cerr << "Time is not valid" << std::endl;
                }
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
