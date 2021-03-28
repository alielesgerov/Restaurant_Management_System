#pragma once
#include "Ingredient.h"

class RecipeItem
{
	std::shared_ptr<Ingredient> ingredient;
	int amount;
	int id;

public:
	static int myid;
	RecipeItem();
	RecipeItem(const std::shared_ptr<Ingredient>& ingredient, int amount);
	void setIngredient(const std::shared_ptr<Ingredient>& ingredient);
	void setID();
	void setID(int id);
	void setAmount(int amount);
	std::shared_ptr<Ingredient>& getIngredient();
	int getAmount() const;
	int getID()const;
	RecipeItem(const RecipeItem& other);
	void Show();

};