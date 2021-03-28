#include "Notification.h"

int Notification::myid = 0;

Notification::Notification(std::string message, std::string from)
{
	setID();
	setMessage(message);
	setFrom(from);
}

void Notification::setID()
{
	this->id = ++myid;
}

void Notification::setMessage(std::string message)
{
	this->message = message;
}

void Notification::setFrom(std::string from)
{
	this->from = from;
}

void Notification::setStatus(bool is_read)
{
	this->is_read = is_read;
}

std::string Notification::getMessage() const
{
	return message;
}

std::string Notification::getFrom() const
{
	return from;
}

bool Notification::getStatus() const
{
	return is_read;
}

int Notification::getID() const
{
	return id;
}

void Notification::Show() const
{
	std::cout <<"========================================"<< std::endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "ID: " ;
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "From: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout<< getFrom() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Message: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getMessage() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}
