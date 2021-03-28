#include "Table.h"

int Table::myid = 0;
Table::Table():id(0),table_no(""),orders(NULL),notification(""){}
Table::Table(std::string table_no)
{
	setID();
	setTableNo(table_no);
}
//Setter
void Table::setID()
{
	id = ++myid;
}
void Table::setTableNo(std::string table_no)
{
	if (table_no.empty())
		throw Exception("Table No is Empty!", __FILE__, __TIME__,__LINE__);
	this->table_no = table_no;
}
void Table::setNotification(std::string notification)
{
	this->notification.append(notification + '\n');
}
//Getter
int Table:: getID()const
{
	return id;
}
std::string Table::getTableNo() const
{
	return table_no;
}
std::string Table::getNotification() const
{
	return notification;
}
std::vector<std::shared_ptr<Order>> Table::getOrders()const
{
	return orders;
}

std::shared_ptr<Order> Table::getOrder(int id)
{
	for (auto& i : this->orders)
	{
		if (id == i->getID())
			return i;
	}
	throw Exception("Wrong ID ",__FILE__,__TIME__,__LINE__);
}
void Table::addOrder(std::shared_ptr<Order> order)
{
	orders.push_back(order);
}
void Table::deleteOrder(int order_index)
{
	orders.erase(orders.begin()+order_index);
}
void Table::Show() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "===================================================\n";
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Table ID:";
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getID() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	std::cout << "Table No: ";
	SetConsoleTextAttribute(hConsole, RED);
	std::cout << getTableNo() << std::endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	if (getOrders().size() > 0)
	{
		std::cout << "All Orders: \n=================================================\n";
		for (int i = 0; i < getOrders().size(); i++)
		{
			std::cout << getOrders()[i] << std::endl;
		}
	}
	if (!getNotification().empty())
	{
		std::cout << "Message from Kitchen: " << getNotification() << std::endl;
	}
	else
		std::cout << "There is no messages: " << std::endl;
}
