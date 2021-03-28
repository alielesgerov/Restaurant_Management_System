#include"RecipeItem.h"
#include"FileHelper.h"
class Stock
{
	std::vector<std::shared_ptr<RecipeItem>> ingredient;
public:
	Stock();
	void addIngredient(std::shared_ptr<Ingredient> ingredient, int amount);
	void updateIngredient(std::shared_ptr<Ingredient> oldIngredient, const std::shared_ptr<Ingredient> newIngredient);
	void deleteIngredient(const size_t& id);
	void increaseIngredientAmount(std::shared_ptr<RecipeItem> item, int amount);
	void decreaseIngredientAmount(std::shared_ptr<RecipeItem> item, int amount);
	void showAllIngredient();
	size_t getIngredientCount() const;
	std::shared_ptr<Ingredient> getIngredient(int id);
	std::shared_ptr<RecipeItem> getItem(int id) const;
	std::shared_ptr<RecipeItem> getItemByIngredientID(int id) const;
	std::vector<std::shared_ptr<RecipeItem>> getIngredientItems();
	bool checkIngredientAmount(int id, int amount) const;
};