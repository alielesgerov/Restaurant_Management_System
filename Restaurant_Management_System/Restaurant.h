#pragma once
#include"Table.h"
#include"Admin.h"
class Restaurant
{
	std::string name;
	std::string address;
	double budget;
	std::vector<std::shared_ptr<Admin>> admins;
	std::vector<std::shared_ptr<Table>> tables;
public:
	Restaurant();
	Restaurant(std::string name,std::string address,std::vector<std::shared_ptr<Admin>> admins,std::vector<std::shared_ptr<Table>> tables);
	void setName(std::string name);
	void setAddress(std::string address);
	void setBudget(double budget);
	void setTables(std::vector<std::shared_ptr<Table>> tables);
	void setAdmins(std::vector<std::shared_ptr<Admin>> admins);
	std::string getName()const;
	std::string getAddress()const;
	double getBudget()const;
	std::vector < std::shared_ptr<Table>> getTables()const;
	std::vector<std::shared_ptr<Admin>> getAdmins()const;
	void Show()const;

};