#pragma once
#include <string>
#include <vector>

class ToDoList
{
private:
	bool isComleted = false;
	std::string task;
	std::string filename;

public:
	ToDoList();
	void removeTask();
	void addTask();
	void read();
	void showMenu(std::vector<std::string>& items, int curentSelection);



};

