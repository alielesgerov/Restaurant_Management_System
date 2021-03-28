#include "FileHelper.h"
#include <fstream>

void FileHelper::writeToFile(const std::string& file_name, const std::string& text)
{
	std::ofstream fout(file_name);

	if (fout.is_open())
		fout << text;
	else
		std::cout << "File could not be opened!\n";

	fout.close();
}
void FileHelper::writeLog(std::string file_name, std::string error)
{
	std::ofstream fout(file_name, std::ios::app);
	if (fout.is_open())
	{
		fout << error << std::endl;
	}
	fout.close();
}
