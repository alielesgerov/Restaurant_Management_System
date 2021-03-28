#include"Meal.h"
#include"Exception.h"
class Order
{
	int id;
	std::string table_no;
	std::shared_ptr<Meal>meal;
	int amount;
public:
	static int myid;
	Order();
	Order(std::string table_no,const std::shared_ptr<Meal> meal, int amount);
	void setID();
	void setTableNo(std::string table_no);
	void setMeal(const std::shared_ptr<Meal>& meal);
	void setAmount(int amount);
	std::string getTableNo()const;
	std::shared_ptr<Meal> getMeal()const;
	int getAmount()const;
	int getID()const;
	void Show()const;
	const std::ostream& operator<<(std::ostream& out);
};