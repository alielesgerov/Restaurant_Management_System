#include"Order.h"

class Table
{
	int id;
	std::string table_no;
	std::vector<std::shared_ptr<Order>> orders;
	std::string notification;
public:
	static int myid;
	Table();
	Table(std::string table_no);
	void setID();
	void setTableNo(std::string table_no);
	void setNotification(std::string notification);
	int getID()const;
	std::string getTableNo()const;
	std::string getNotification()const;
	std::vector<std::shared_ptr<Order>> getOrders()const;
	std::shared_ptr<Order> getOrder(int id);
	void addOrder(std::shared_ptr<Order> order);
	void deleteOrder(int order_index);
	void Show()const;

};