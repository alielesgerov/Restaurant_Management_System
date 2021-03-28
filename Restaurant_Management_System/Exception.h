#pragma once
#include<iostream>
#include <string>
#include<Windows.h>
class Exception
{
	std::string text;
	std::string file;
	std::string time;
	int line;
public:
	Exception();
	Exception(std::string text, std::string file, std::string time, int line);
	void setText(std::string text);
	void setFile(std::string file);
	void setTime(std::string time);
	void setLine(int line);
	std::string getText()const;
	std::string getFile()const;
	std::string getTime()const;
	int getLine()const;
	void getException()const;
	std::string getData()const;
};