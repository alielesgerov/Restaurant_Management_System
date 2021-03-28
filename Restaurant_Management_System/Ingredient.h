#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>


#define RED 12
#define GREEN 10
#define WHITE 15

class Ingredient
{
protected:
	int id;
	std::string name;
	int calorie;
	int amount;
	double fat;
	double protein;
	double price;
public:
	static int myid;
	Ingredient();
	Ingredient(std::string name, int calorie, double fat, double protein, int amount, double price);
	Ingredient(std::string name, int calorie, double fat, double protein, int amount);
	Ingredient(std::string name, int calorie, double fat, double protein);
	Ingredient(std::string name, int calorie, double fat);
	Ingredient(std::string name, int calorie);
	explicit Ingredient(std::string name);
	void setID();
	void setName(std::string name);
	void setCalorie(int calorie);
	void setAmount(int amount);
	void setPrice(double price);
	void setFat(double fat);
	void setProtein(double protein);
	std::string getName()const;
	int getCalorie()const;
	int getAmount()const;
	double getPrice()const;
	double getProtein()const;
	double getFat()const;
	int getID()const;
	void Show()const;
	std::ostream& operator<<(std::ostream& out);
	std::istream& operator>>(std::istream& in);
};