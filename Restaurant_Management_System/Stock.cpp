#include "Stock.h"
#include"Exception.h"
Stock::Stock():ingredient(NULL){}

void Stock::addIngredient(std::shared_ptr<Ingredient> ingredient, int amount)
{
	this->ingredient.push_back(std::shared_ptr<RecipeItem>(new RecipeItem(ingredient, amount)));
}
void Stock::updateIngredient(std::shared_ptr<Ingredient> oldIngredient, const std::shared_ptr<Ingredient> newIngredient)
{
	oldIngredient->setName(newIngredient->getName());
	oldIngredient->setFat(newIngredient->getFat());
	oldIngredient->setProtein(newIngredient->getProtein());
	oldIngredient->setCalorie(newIngredient->getCalorie());
	Ingredient::myid--;
}
void Stock::deleteIngredient(const size_t& id)
{
	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		if (id == (*i)->getIngredient()->getID())
		{
			ingredient.erase(i); return;
		}
	}
	throw Exception("This ID is Incorrect ",__FILE__,__TIME__,__LINE__);
}
void Stock::increaseIngredientAmount(std::shared_ptr<RecipeItem> item, int amount)
{
	if (amount > 0)
	{
		item->setAmount(item->getAmount() + amount);
		return;
	}
	throw Exception("Amount mast be greater than 0",__FILE__, __TIME__, __LINE__);
}
void Stock::decreaseIngredientAmount(std::shared_ptr<RecipeItem> item, int amount)
{
	if (amount > 0)
	{
		item->setAmount(item->getAmount() - amount);
		return;
	}
	throw Exception("Amount mast be greater than 0", __FILE__, __TIME__, __LINE__);
}

void Stock::showAllIngredient()
{

	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		(*i)->getIngredient()->Show(); 
		std::cout << std::endl;
		std::cout << "Amount: " << (*i)->getAmount() << std::endl;
	}
}
size_t Stock::getIngredientCount() const
{
	return this->ingredient.size();
}

std::shared_ptr<Ingredient> Stock::getIngredient(int id)
{
	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		if (id == (*i)->getIngredient()->getID())
			return (*i)->getIngredient();
	}
	throw Exception("This ID is Incorrect ", __FILE__, __TIME__, __LINE__);
}

std::shared_ptr<RecipeItem> Stock::getItem(int id) const
{
	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		if (id == (*i)->getID())
		{
			return (*i);
		}
	}
	throw Exception("This ID is Incorrect ", __FILE__, __TIME__, __LINE__);
}

std::shared_ptr<RecipeItem> Stock::getItemByIngredientID(int id) const
{

	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		if (id == (*i)->getIngredient()->getID())
		{
			return (*i);
		}
	}
	throw Exception("This ID is Incorrect ", __FILE__, __TIME__, __LINE__);
}
std::vector<std::shared_ptr<RecipeItem>> Stock::getIngredientItems()
{
	return this->ingredient;
}
bool Stock::checkIngredientAmount(int id, int amount) const
{
	try
	{
		if (getItemByIngredientID(id)->getAmount() >= amount)
			return true;
	}
	catch (const Exception& ex)
	{
		system("CLS");
		ex.getException();
		FileHelper::writeLog("stock_side.log", ex.getData());
	}
	return false;
}
