#include "Order.h"

int Order::myid = 0;
Order::Order():id(0),table_no(""),meal(NULL),amount(0){}
Order::Order(std::string table_no,const std::shared_ptr<Meal> meal, int amount)
{
	setID();
	setMeal(meal);
	setAmount(amount);
}
//Setter
void Order::setID()
{
	id = myid++;
}
void Order::setTableNo(std::string table_no)
{
	if (table_no.empty())
		throw Exception("You must wirte table no", __FILE__, __TIME__, __LINE__);
	this->table_no = table_no;
}
void Order::setMeal(const std::shared_ptr<Meal>& meal)
{
	if(meal==nullptr)
		throw Exception("There is no Meal ", __FILE__, __TIME__, __LINE__);
	this->meal = meal;
}
void Order::setAmount(int amount)
{
	if(amount<=0)
		throw Exception("Mael amount must more than 0 ", __FILE__, __TIME__, __LINE__);
	this->amount = amount;
}
//Getter
std::string Order::getTableNo() const
{
	return table_no;
}
std::shared_ptr<Meal> Order::getMeal() const
{
	return meal;
}
int Order::getAmount() const
{
	return amount;
}
int Order::getID() const
{
	return id;
}
void Order::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "===================================================\n";
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Table NO: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getTableNo() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Meal Amount: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getAmount() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Meal Information: \n==============================================="<<std::endl;
	std::cout << getMeal() << std::endl;
}
const std::ostream& Order::operator<<(std::ostream& out)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "===================================================\n";
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	out << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Table NO: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getTableNo() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Meal Amount: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getAmount() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Meal Information: \n===============================================" << std::endl;
	out << getMeal() << std::endl;
	return out;
}
