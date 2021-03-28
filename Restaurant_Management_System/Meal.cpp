#include "Meal.h"

int Meal::myid = 0;
Meal::Meal():id(0),ingredient(NULL),name(""),category(""),rating(0),price(0){}
Meal::Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name, const std::string category, double rating, double price):Meal(ingredient,name,category,rating)
{
	
	setPrice(price);
}
Meal::Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name, const std::string category, double rating):Meal(ingredient,name,category)
{
	setRating(rating);
}
Meal::Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name, const std::string category) : Meal(ingredient, name)
{
	setCategory(category);
}
Meal::Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient, const std::string& name) : Meal(ingredient)
{
	setName(name);
}
Meal::Meal(std::vector<std::shared_ptr<RecipeItem>>& ingredient)
{
	setIngredient(ingredient);
	setID();
}
//Setter
void Meal::setID()
{
	this->id = ++myid;
}
void Meal::setIngredient(const std::vector<std::shared_ptr<RecipeItem>>& ingredient)
{
	this->ingredient = ingredient;
}
void Meal::setName(const std::string name)
{
	this->name = name;
}
void Meal::setCategory(const std::string category)
{
	this->category = category;
}
void Meal::setRating(double rating)
{
	if(rating<0||rating>5)
		throw Exception("Rating can't be more than 5 or less than 0", __FILE__, __TIME__, __LINE__);
	this->rating = rating;
}
void Meal::setPrice(double price)
{
	this->price = price;
}
//Getter
int Meal::getID()const
{
	return id;
}
std::vector<std::shared_ptr<RecipeItem>>& Meal::getIngredinet()
{
	return ingredient;
}
std::string Meal::getName() const
{
	return name;
}
std::string Meal::getCategory() const
{
	return category;
}
double Meal::getRating() const
{
	return rating;
}
double Meal::getPrice() const
{
	return price;
}
void Meal::increasePrice(const double& ingredientPrice,int count)
{
	this->price += ingredientPrice * count;
}
void Meal::decreasePrice(const double& ingredientPrice,int count)
{
	this->price -= ingredientPrice * count;
}
void Meal::giveRating(double rating)
{
	this->rating = (this->rating + rating) / 2;
}
void Meal::addIngredient(const std::shared_ptr<Ingredient>& ingredient, int amount)
{
	RecipeItem* item = new RecipeItem(ingredient, amount);
	this->ingredient.push_back(std::shared_ptr<RecipeItem>(item));
	increasePrice(ingredient->getPrice(), amount);
}
void Meal::deleteIngredientByID(int id)
{
	for (auto i = ingredient.begin(); i != ingredient.end(); i++)
	{
		if (id == (*i)->getIngredient()->getID())
		{
			decreasePrice((*i)->getIngredient()->getPrice(), (*i)->getAmount());
			ingredient.erase(i);
			return;
		}
	}
	throw Exception(std::string("There is no ingredient in this id (" + std::to_string(id) + ")"), __FILE__, __TIME__,__LINE__);
}
void Meal::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "================================================\n";
	std::cout << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Meal Name:";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getName() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Meal Category: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getCategory() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Meal Rating: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getRating() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Price: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	std::cout << getPrice()<<" $" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

std::ostream& Meal::operator<<(std::ostream& out)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "================================================\n";
	out << "ID: ";
	SetConsoleTextAttribute(hConsole, RED);
	out << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Meal Name:";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getName() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Meal Category: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getCategory() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Meal Rating: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getRating() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	out << "Price: ";
	SetConsoleTextAttribute(hConsole, GREEN);
	out << getPrice() << " $" << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	return out;
}
