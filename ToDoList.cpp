#include "ToDoList.h"
#include <conio.h>
#include <iostream>
#include <fstream>


ToDoList::ToDoList()
    :filename("ToDooList.txt")
{
    std::vector<std::string>menuItems = { "Remove the task","Add task","Read the task","Exit" };
    int curentSelection = 0;

    while (true)
    {
        showMenu(menuItems, curentSelection);
        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72)
            {
                curentSelection = (curentSelection - 1 + menuItems.size()) % menuItems.size();
            }
            else if (key == 80)
            {
                curentSelection = (curentSelection + 1) % menuItems.size();
            }
        }
        else if (key == 13)
        {
            switch (curentSelection)
            {
            case 0:
                removeTask();
                break;
            case 1:
                addTask();
                break;
            case 2:
                read();
                break;
            case 3:
                std::cout << "Exiting program" << std::endl;
                return;
            }
            std::cout << "\nPress any key to return to the menu...";
            _getch();
        }
    }
}

void ToDoList::addTask()
{
    while (true)
    {
        system("cls");
        std::cout << "Add Task Menu" << std::endl;
        std::cout << "1. Add specific task" << std::endl;
        std::cout << "2. Back to main menu" << std::endl;
        int selection;
        std::cin >> selection;
        std::cin.ignore();
        if (selection == 1)
        {
            std::ofstream fileStream(filename, std::ios::app);
            if (!fileStream.is_open())
            {
                std::cerr << "File could not be opened" << std::endl;
                return;
            }
            std::cout << "Input task: ";
            std::getline(std::cin, task);
            if (task.empty())
            {
                std::cout << "Task cannot be empty. Try again." << std::endl;
                continue;
            }
            fileStream << task << ":not done" << std::endl;
            std::cout << "Task successfully added!" << std::endl;

            fileStream.close();


        }
        else if (selection == 2)
        {
            return;
        }
        else
        {
            std::cout << "Invalid input, try again." << std::endl;
        }
    }
}

void ToDoList::read()
{
    while (true)
    {
        system("cls");
        std::cout << "Read Task Menu" << std::endl;
        std::cout << "1. View tasks" << std::endl;
        std::cout << "2. Change task status" << std::endl;
        std::cout << "3. Back to main menu" << std::endl;
        int selection;
        std::cin >> selection;
        std::cin.ignore();
        if (selection == 1)
        {
            std::ifstream fileStream(filename);
            if (!fileStream.is_open())
            {
                std::cerr << "File could not be opened" << std::endl;
                return;
            }
            std::vector<std::string> tasks;
            std::string line;
            while (std::getline(fileStream, line))
            {
                tasks.push_back(line);
            }
            fileStream.close();

            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                size_t delimiterPos = tasks[i].find(':');
                std::string taskDescription = tasks[i].substr(0, delimiterPos);
                std::string taskStatus = tasks[i].substr(delimiterPos + 1);
                std::cout << i + 1 << ". " << taskDescription << " [" << taskStatus << "]" << std::endl;
            }
            _getch();
        }
        else if (selection == 2)
        {
            std::ifstream fileStream(filename);
            if (!fileStream.is_open())
            {
                std::cerr << "File could not be opened" << std::endl;
                return;
            }
            std::vector<std::string> tasks;
            std::string line;
            while (std::getline(fileStream, line))
            {
                tasks.push_back(line);
            }
            fileStream.close();

            for (size_t i = 0;i < tasks.size();++i)
            {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }

            std::cout << "Enter the task number to change its status: ";
            int taskNumber;
            std::cin >> taskNumber;
            std::cin.ignore();

            if (taskNumber < 1 || taskNumber > tasks.size())
            {
                std::cout << "Invalid task number." << std::endl;
                continue;
            }

            size_t delimiterPos = tasks[taskNumber - 1].find(':');
            std::string taskDescription = tasks[taskNumber - 1].substr(0, delimiterPos);
            std::string taskStatus = tasks[taskNumber - 1].substr(delimiterPos + 1);

            std::cout << "Current status of the task: [" << taskStatus << "]" << std::endl;
            std::cout << "Enter new status: ";
            std::string newStatus;
            std::cin >> newStatus;

            tasks[taskNumber - 1] = taskDescription + ":" + newStatus;

            // Save updated tasks to file
            std::ofstream outFile(filename);
            for (const auto& task : tasks)
            {
                outFile << task << std::endl;
            }
            outFile.close();

            std::cout << "Task status updated successfully!" << std::endl;
            _getch();
        }
        else if (selection == 3)
        {
            return;
        }
        else
        {
            std::cout << "Invalid input, try again." << std::endl;
        }
    }
}

void ToDoList::removeTask()
{
    while (true)
    {
        system("cls");
        std::cout << "Remove Task Menu" << std::endl;
        std::cout << "1. Remove specific task" << std::endl;
        std::cout << "2. Back to main menu" << std::endl;
        int selection;
        std::cin >> selection;
        std::cin.ignore();
        if (selection == 1)
        {
            std::ifstream fileStream(filename);
            if (!fileStream.is_open())
            {
                std::cerr << "File could not be opened" << std::endl;
                return;
            }
            std::vector<std::string> tasks;
            std::string line;
            while (std::getline(fileStream, line))
            {
                tasks.push_back(line);
            }
            fileStream.close();

            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                size_t delimiterPos = tasks[i].find(':');
                std::string taskDescription = tasks[i].substr(0, delimiterPos);
                std::string taskStatus = tasks[i].substr(delimiterPos + 1);
                std::cout << i + 1 << ". " << taskDescription << " [" << taskStatus << "]" << std::endl;
            }

            std::cout << "Enter the number of the task to remove: ";
            int taskNumber;
            std::cin >> taskNumber;
            std::cin.ignore();

            if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size()))
            {
                std::cout << "Invalid task number. Press any key to return to the menu." << std::endl;
                _getch();
                continue;
            }

            tasks.erase(tasks.begin() + taskNumber - 1);

            std::ofstream refilieStream(filename, std::ios::trunc);
            if (!refilieStream.is_open())
            {
                std::cerr << "File could not be opened" << std::endl;
                return;
            }
            for (const auto& task : tasks)
            {
                refilieStream << task << std::endl;
            }
            refilieStream.close();
            std::cout << "Task removed successfully." << std::endl;
            std::cout << "Press any key to return to the menu." << std::endl;
            _getch();
        }
        else if (selection == 2)
        {
            return;
        }
        else
        {
            std::cout << "Invalid input, try again." << std::endl;
        }
    }
}

void ToDoList::showMenu(std::vector<std::string>& items, int curentSelection)
{
    system("cls");
    for (size_t i = 0; i < items.size(); ++i) {
        if (static_cast<int>(i) == curentSelection)
        {
            std::cout << "> " << items[i] << " <" << std::endl;
        }
        else
        {
            std::cout << "  " << items[i] << std::endl;
        }
    }
}
