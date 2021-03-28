#pragma
#include"Ingredient.h"

class Notification
{
	int id;
	std::string message;
	std::string from;
	bool is_read;
public:
	int static myid;
	Notification(std::string message, std::string from);
	void setID();
	void setMessage(std::string message);
	void setFrom(std::string from);
	void setStatus(bool is_read);
	std::string getMessage()const;
	std::string getFrom()const;
	bool getStatus()const;
	int getID()const;
	void Show()const;

};