#pragma once
#include"Ingredient.h"

class Admin
{
	int id;
	std::string username;
	std::string password;
public:
	static int myid;
	Admin();
	Admin(std::string username, std::string password);
	void setID();
	void setUsername(std::string username);
	void setPassword(std::string password);
	std::string getUsername()const;
	std::string getPassword()const;
	int getID();
	void Show()const;
};