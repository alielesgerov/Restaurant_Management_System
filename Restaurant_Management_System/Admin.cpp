#include "Admin.h"
int Admin::myid = 0;
Admin::Admin():username(""),password(""){}

Admin::Admin(std::string username, std::string password)
{
	setID();
	setUsername(username);
	setPassword(password);
}
//Setter
void Admin::setID()
{
	id = ++myid;
}
void Admin::setUsername(std::string username)
{
	this->username = username;
}
void Admin::setPassword(std::string password)
{
	this->password = password;
}
//Getter
std::string Admin::getUsername() const
{
	return username;
}
std::string Admin::getPassword() const
{
	return password;
}
int Admin::getID()
{
	return id;
}
void Admin::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "===================================================\n";
	std::cout << "Username: ";
	SetConsoleTextAttribute(hConsole,GREEN);
	std::cout << getUsername() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Password: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getPassword() << std::endl;
}

