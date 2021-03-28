#include "Restaurant.h"
#include"Exception.h"
Restaurant::Restaurant():name(""),address(""),budget(0),admins(NULL),tables(NULL){}
Restaurant::Restaurant(std::string name, std::string address,std::vector<std::shared_ptr<Admin>> admins, std::vector<std::shared_ptr<Table>> tables)
{
	setName(name);
	setAddress(address);
	setAdmins(admins);
	setTables(tables);
}
//Setter
void Restaurant::setName(std::string name)
{
	if (name.empty())
		throw Exception("name is empty", __FILE__, __TIME__, __LINE__);
	this->name = name;
}
void Restaurant::setAddress(std::string address)
{
	if (address.empty())
		throw Exception("address is empty", __FILE__, __TIME__, __LINE__);
	this->address = address;
}
void Restaurant::setBudget(double budget)
{
	if (budget<0)
		throw Exception("budget less than 0", __FILE__, __TIME__, __LINE__);
	this->budget = budget;
}
void Restaurant::setTables(std::vector<std::shared_ptr<Table>> tables)
{
	this->tables = tables;
}
void Restaurant::setAdmins(std::vector<std::shared_ptr<Admin>> admins)
{
	this->admins = admins;
}
//Getter
std::string Restaurant::getName() const
{
	return name;
}

std::string Restaurant::getAddress() const
{
	return address;
}
double Restaurant::getBudget() const
{
	return budget;
}
std::vector<std::shared_ptr<Table>> Restaurant::getTables() const
{
	return tables;
}
std::vector<std::shared_ptr<Admin>> Restaurant::getAdmins() const
{
	return admins;
}
void Restaurant::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Restaurant Name: ";
	SetConsoleTextAttribute(hConsole, GREEN); 
	std::cout << getName() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Restaurant Address: ";
	SetConsoleTextAttribute(hConsole, GREEN); 
	std::cout << getAddress() <<std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Restaurant Budget: ";
	SetConsoleTextAttribute(hConsole, GREEN); 
	std::cout << getBudget() <<" $" <<std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Restaurant Tables Inforamtions:";
	SetConsoleTextAttribute(hConsole, GREEN);
	for (size_t i = 0; i < getTables().size(); i++)
		getTables()[i]->Show();
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Restaurant Admins Inforamtions:";
	SetConsoleTextAttribute(hConsole, GREEN);
	for (size_t i = 0; i < getAdmins().size(); i++)
		getAdmins()[i]->Show();
}
