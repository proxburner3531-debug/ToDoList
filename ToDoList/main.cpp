#include <iostream>
#include <string>
#include <limits>

void AddTasks(std::string* tasks)
{
	std::string assignTask;
	std::cout << "Type in task you want to assign (like -> Homework) : ";
	std::getline(std::cin >> std::ws, assignTask);

	for (int i = 0;i < 100;i++) {
		if (tasks[i] == "") 
		{
			tasks[i] = assignTask;
			break;
		}
	}
}

void RemoveTasks(std::string* tasks)
{
	int removeTask;
	std::cout << "Type in the number in front of the task to delete it : ";
	std::cin >> removeTask;

	for (int i = 0;i < 100;i++) {
		if (removeTask == i + 1) {
			tasks[i] = "";
			//for (int j = i;j < 100;j++) {
			//	tasks[j] == tasks[j + 1];
			//}
		}
	}
}

void ViewTasks(std::string* tasks)
{
	int taskCount = 0;
	for (int i = 0;i < 100;i++) {
		if (tasks[i] != "") 
		{
			taskCount++;
			std::cout << taskCount << ". " << tasks[i] << "\n";
			
		}
	}

	if (taskCount == 0) 
	{
		std::cout << "No tasks assigned!\n";
	}

}

int main()
{
	int user = 0;
	std::string input;
	std::string tasks[100];
	size_t len;
	do 
	{
		std::cout << "************ TO DO LIST ************\n";
		std::cout << "1. View Tasks\n";
		std::cout << "2. Add Tasks\n";
		std::cout << "3. Remove Tasks\n";
		std::cout << "4. Exit\n";
		std::cout << "************************************\n";

		std::cout << "Pick the number in front of option to select it : ";
		std::getline(std::cin >> std::ws, input);

		try
		{
			user = std::stoi(input, &len);

			if (len != input.length())
			{
				std::cout << "Pick a valid integar from the above marked!\n";
				continue;
			}
		}
		catch (...)
		{
			std::cout << "Invalid input!\nTry again!\n";
			continue;
		}

		switch (user)
		{
		case 1: ViewTasks(tasks);
			break;
		case 2: AddTasks(tasks);
			break;
		case 3: RemoveTasks(tasks);
			break;
		case 4:
			break;
		default: std::cout << "Pick a valid option!\n";
			continue;
		}
	} while (user != 4);
	return 0;
}