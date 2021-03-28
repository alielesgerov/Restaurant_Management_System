#pragma once
#include"RecipeItem.h"
#include"Exception.h"
class Meal
{
	int id;
	std::vector<std::shared_ptr<RecipeItem>>ingredient;
	std::string name;
	std::string category;
	double rating;
	double price;
public:
	static int myid;
	Meal();
	Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient,const std::string& name, const std::string category, double rating, double price);
	Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name, const std::string category, double rating);
	Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name, const std::string category);
	Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name);
	explicit Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient);
	void setID();
	void setIngredient(const std::vector<std::shared_ptr<RecipeItem>>& ingredient);
	void setName(const std::string name);
	void setCategory(const std::string category);
	void setRating(double rating);
	void setPrice(double price);
	int getID()const;
	std::vector<std::shared_ptr<RecipeItem>>& getIngredinet();
	std::string getName()const;
	std::string getCategory()const;
	double getRating()const;
	double getPrice()const;
	void increasePrice(const double& ingredientPrice, int count);
	void decreasePrice(const double& ingredientPrice, int count);
	void giveRating(double rating);
	void addIngredient(const std::shared_ptr<Ingredient>& ingredient, int amount);
	void deleteIngredientByID(int id);
	void Show()const;
	std::ostream& operator << (std::ostream& out);
};