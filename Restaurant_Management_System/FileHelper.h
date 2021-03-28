#pragma once
#include <string>
#include<iostream>
class FileHelper
{
public:
	static void writeToFile(const std::string& file_name, const std::string& text);
	static void writeLog(std::string file_name,std::string error);
};