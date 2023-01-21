#include <iostream>
#include "Source.h"

using namespace std;


std::string get_value_from_console() {	// получение значения с консоли
	std::string value;
	while (!(cin >> value));	// noskipws?
	std::cin.clear(),
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// очистка буфера консоли
	return value;
}


bool QuestionYN(const std::string& _str) {	// вопрос с двумя вариантами ответа y/n
	std::cout << _str << " (y/n): ";
	std::string command = "";
	while ((command != "y") && (command != "n"))
		command = get_value_from_console();
	return (command == "y") ? true : false;
}
