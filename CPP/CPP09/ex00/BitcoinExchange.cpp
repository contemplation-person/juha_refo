#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>

static bool isLeapYear(int year) 
{
	return ((year % 4 == 0 && year % 100 != 0) 
			|| year % 400 == 0);
}

static bool isDateNumber(std::string& date, long& year, long& month, long& day)
{
	date.at(4) = '0';
	date.at(7) = '0';
	for (long unsigned int i = 0; i < date.size(); i++)
	{
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	year = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
	month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
	day = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	return true;
}

static bool isValidDate(std::string date, int &i_date)
{
	std::cout << "comment - date : " << date << std::endl;
	if (date[4] != '-' || date[7] != '-')
		return false;
	long year;
	long month;
	long day;
	if (isDateNumber(date, year, month, day) == false)
		return false;
	if (isLeapYear(year) && month == 2 && day > 29)
		return false;
	else if (month == 2 && day > 28)
		return false;
	else if ((month == 4 || month == 6 || month == 9 || month == 11) 
			&& day > 30)
		return false;
	else if (day > 31)
		return false;
	i_date = year * 10000 + month * 100 + day;
	return true;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getValue(const int& key) 
{
	return _data[key];
}

BitcoinExchange::BitcoinExchange() 
{
	FILE* fp = fopen("data.csv", "r");
	if (!fp)
	{
		std::cout << "\033[31mError: could not open file.\033[0m" << std::endl;
		return ;
	}

	std::string	line;
	char		tmp[1024];
	int			date;
	double		value;

	while (std::fscanf(fp, "%s\n", tmp) != EOF)
	{
		line = tmp;
		std::cout << "comment - line : " << line << std::endl;
		isValidDate(line.substr(0, 10), date);
		value = std::strtod(line.substr(11).c_str(), NULL);
		if (value == 0)
			value = ZERO;
		_data[date] = value;
		std::cout << "\033[31mcomment - date : " << date 
				<< ", value : \033[0m" << value << std::endl;
	}
	fclose(fp);
}

/*
void BitcoinExchange::setData(char *fileName) 
{
	FILE* fp = fopen(fileName, "r");
	if (!fp)
	{
		std::cout << "\033[31mError: could not open file.\033[0m" << std::endl;
		return ;
	}
	std::string	line;
	int			date;
	double		value;

	while (std::getline(fp, line))
	{
		
		if(isValidDate(line.substr(0, 10), date) 
			&& isValidValue(line.substr(11), value)
			&& line[10] == ',')	
		{
			std::cout << "comment - , : " << line[10] << std::endl;
			_data[date] = value;
		}
		else
		{
			std::cout << "\033[31mError: invalid file format.\033[0m" << std::endl;
			return ;
		}
	}
}
*/
