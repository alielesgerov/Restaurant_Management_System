#include "Exception.h"

Exception::Exception():text(""),file(""),time(""),line(0){}
Exception::Exception(std::string text, std::string file, std::string time, int line)
{
	setText(text);
	setFile(file);
	setTime(time);
	setLine(line);
}
//Setter
void Exception::setText(std::string text)
{
	this->text = text;
}
void Exception::setFile(std::string file)
{
	this->file = file;
}
void Exception::setTime(std::string time)
{
	this->time = time;
}
void Exception::setLine(int line)
{
	this->line = line;
}
//Getter
std::string Exception::getText() const
{
	return text;
}
std::string Exception::getFile() const
{
	return file;
}
std::string Exception::getTime() const
{
	return time;
}
int Exception::getLine() const
{
	return line;
}
void Exception::getException() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "Error Text: " << getText() << std::endl;
	std::cout << "Time: " << getTime() << std::endl;
	std::cout << "Source: " << getFile() << std::endl;
	std::cout << "Line: " << getLine() << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}
std::string Exception::getData() const
{
	std::string exception;
	exception.append(std::string("====================================================") + '\n');
	exception.append("Error Text: " + getText() + "\n");
	exception.append("Time: " + getTime() + "\n");
	exception.append("Source: " + getFile() + "\n");
	exception.append("Line: " + std::to_string(getLine()) + "\n");
	exception.append(std::string("====================================================x") + '\n');
	return exception;
}
