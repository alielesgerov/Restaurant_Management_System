#include "Ingredient.h"

int Ingredient::myid = 0;
Ingredient::Ingredient():id(0),name(""),calorie(0),amount(0),fat(0),protein(0),price(0){}
Ingredient::Ingredient(std::string name, int calorie, double fat, double protein, int amount, double price):Ingredient(name,calorie,fat,protein,amount)
{
	setPrice(price);
}
Ingredient::Ingredient(std::string name, int calorie, double fat, double protein, int amount):Ingredient(name,calorie,fat,protein)
{
	setAmount(amount);
}
Ingredient::Ingredient(std::string name, int calorie, double fat, double protein):Ingredient(name,calorie,fat)
{
	setProtein(protein);
}
Ingredient::Ingredient(std::string name, int calorie, double fat) : Ingredient(name, calorie)
{
	setFat(fat);
}
Ingredient::Ingredient(std::string name, int calorie)
{
	setCalorie(calorie);
}
Ingredient::Ingredient(std::string name)
{
	setID();
	setName(name);
}
//Setter
void Ingredient::setID()
{
	this->id = ++myid;
}
void Ingredient::setName(std::string name)
{
	this->name = name;
}
void Ingredient::setCalorie(int calorie)
{
	this->calorie = calorie;
}
void Ingredient::setAmount(int amount)
{
	this->amount = amount;
}
void Ingredient::setPrice(double price)
{
	this->price = price;
}
void Ingredient::setFat(double fat)
{
	this->fat = fat;
}
void Ingredient::setProtein(double protein)
{
	this->protein = protein;
}
//Getter
std::string Ingredient::getName() const
{
	return name;
}
int Ingredient::getCalorie() const
{
	return calorie;
}
int Ingredient::getAmount() const
{
	return amount;
}
double Ingredient::getPrice() const
{
	return price;
}
double Ingredient::getProtein() const
{
	return protein;
}
double Ingredient::getFat() const
{
	return fat;
}
int Ingredient::getID() const
{
	return id;
}
void Ingredient::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "================================================\n";
	std::cout << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Ingeredien Name: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getName() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Calorie: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getCalorie() << " Kcal" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Fat: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getFat() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Protein: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getProtein() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Amount: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getAmount() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Price: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getPrice() << " $" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}
//Output overload
std::ostream& Ingredient::operator<<(std::ostream& out)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "================================================\n";
	out << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	out << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Ingeredien Name: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getName() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Calorie: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getCalorie() << " Kcal" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Fat: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getFat() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Protein: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getProtein() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Amount: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getAmount() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Price: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getPrice() << " $" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	return out;
}
//Input overload
std::istream& Ingredient::operator>>(std::istream& in)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "================================================\n";
	SetConsoleTextAttribute(hConsole, WHITE);
	setID();
	std::cout << "Enter Ingredient Name: ";
	std::string name;
	SetConsoleTextAttribute(hConsole, GREEN);
	getline(in, name);
	setName(name);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Enter Ingredient Calorie: ";
	int calorie;
	SetConsoleTextAttribute(hConsole, GREEN);
	in >> calorie;
	setCalorie(calorie);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Enter Ingredient Fat: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	double temp;
	in >> temp;
	setFat(temp);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Enter Ingredient Protein: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	in >> temp;
	setProtein(temp);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Enter Ingredient Price: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	in >> temp;
	setPrice(temp);
	return in;
}
