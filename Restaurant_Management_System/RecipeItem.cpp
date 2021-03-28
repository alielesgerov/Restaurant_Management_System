#include "RecipeItem.h"

int RecipeItem::myid = 0;
RecipeItem::RecipeItem():id(0),ingredient(nullptr),amount(0){}
RecipeItem::RecipeItem(const std::shared_ptr<Ingredient>& ingredient, int amount)
{
	setIngredient(ingredient);
	setAmount(amount);
	setID();
}
//Setter
void RecipeItem::setIngredient(const std::shared_ptr<Ingredient>& ingredient)
{
	this->ingredient = ingredient;
}
void RecipeItem::setID()
{
	this->id = ++myid;
}
void RecipeItem::setID(int id)
{
	this->id = id;
}
void RecipeItem::setAmount(int amount)
{
	this->amount = amount;
}
//Getter
std::shared_ptr<Ingredient>& RecipeItem::getIngredient()
{
	return ingredient;
}
int RecipeItem::getAmount() const
{
	return amount;
}
int RecipeItem::getID() const
{
	return id;
}
RecipeItem::RecipeItem(const RecipeItem& other)
{
	setIngredient(other.ingredient);
	setID(other.getID());
	setAmount(other.getAmount());
}
void RecipeItem::Show()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "================================================\n";
	std::cout << "Ingredient Information: " << std::endl;
	std::cout << getIngredient()<<std::endl;
	std::cout << "Ingredient Amount: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getAmount() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}
