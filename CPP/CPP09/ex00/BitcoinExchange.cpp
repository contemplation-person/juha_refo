#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

static bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static bool isDateNumber(std::string &date, long &year, long &month, long &day)
{
    date.at(4) = '0';
    date.at(7) = '0';
    for (long unsigned int i = 0; i < date.length(); i++)
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
    if (date.empty())
        return false;
    date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
    date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
    if (date[4] != '-' || date[7] != '-')
        return false;

    long year;
    long month;
    long day;

    if (!isDateNumber(date, year, month, day))
    {
        std::cout << "\033[31mError: Bad input => " << date << "\033[0m" << std::endl;
        return false;
    }
    if (isLeapYear(year) && month == 2 && day > 29)
    {
        std::cout << "\033[31mError: Bad input(check LeapYear) => " << date << "\033[0m" << std::endl;
        return false;
    }
    else if (month == 2 && day > 28)
    {
        std::cout << "\033[31mError: Bad input(check LeapYear) => " << date << "\033[0m" << std::endl;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "\033[31mError: Bad input => " << date << "\033[0m" << std::endl;
        return false;
    }
    else if (day > 31)
    {
        std::cout << "\033[31mError: Bad input => " << date << "\033[0m" << std::endl;
        return false;
    }
    i_date = year * 10000 + month * 100 + day;
    return true;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getValue(const int &key)
{
    return _data[key];
}

static bool isValidValue(std::string value, double &d_value)
{
    if (value.empty())
        return false;
    value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
    value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);

    char *endptr;
    long i_value = std::strtol(value.c_str(), &endptr, 10);

    d_value = std::strtod(value.c_str(), &endptr);

    if (endptr && *endptr)
    {
        std::cout << "\033[31mError: invalid value.\033[0m" << std::endl;
        return false;
    }
    if (static_cast<double>(i_value) == d_value)
    {
        if (!(0 < d_value && d_value < 2147483648))
        {
            std::cout << "\033[31mError: range invalid - 0 < int number < 2147483648.\033[0m" << std::endl;
            return false;
        }
    }
    else
    {
        if (!(0 < d_value && d_value < 1000))
        {
            std::cout << "\033[31mError: range invalid - 0 < double number < 1000.\033[0m" << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::calculate(const std::string &fileName)
{
    std::ifstream ifs(fileName.c_str());
    if (!ifs.is_open())
    {
        std::cout << "\033[31mError: could not read file.\033[0m" << std::endl;
        return false;
    }

    std::string line;
    int date;
    double value;
    std::map<int, double>::iterator it;

    std::getline(ifs, line);
    while (!ifs.eof())
    {
        std::getline(ifs, line);
        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
        if (line.length() < 10)
        {
            std::cout << "\033[31mError: Bad input. => " << line << "\033[0m" << std::endl;
        }
        else if (line.length() > 12 && isValidValue(line.substr(12), value) && isValidDate(line.substr(0, 10), date) && line.find('|') != std::string::npos)
        {
            it = _data.find(date);
            if (it != _data.end())
            {
                std::cout << line.substr(0, 10) << " => "
                          << value << " = "
                          << _data[it->second] * value << std::endl;
            }
            else
            {
                if (date > _data.rbegin()->first)
                {
                    std::cout << "\033[31mError: date is out of range.\033[0m" << std::endl;
                    continue;
                }
                for (int i = date; i < _data.rbegin()->first; i++)
                {
                    it = _data.find(i);
                    if (it != _data.end())
                    {
                        std::cout << line.substr(0, 10) << " => "
                                  << value << " = "
                                  << (it->second) * value << std::endl;
                        break;
                    }
                }
            }
        }
    }
    ifs.close();
    return true;
}

BitcoinExchange::BitcoinExchange(const std::string &csvName, const std::string& txtName)
{
    std::ifstream ifs(csvName);
    if (!ifs.is_open())
    {
        std::cout << "\033[31mError: could not read file.\033[0m" << std::endl;
        return;
    }

    std::string line;
    int date;
    double value;

    std::getline(ifs, line);
    while (!ifs.eof())
    {
        std::getline(ifs, line);

        line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
        line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
        if (line[4] != '-' || line[7] != '-' || line[10] != ',')
        {
            std::cout << "\033[31mPass date "
                      << "\033[0m" << std::endl;
            continue;
        }
        if (!line.empty())
        {
            isValidDate(line.substr(0, 10), date);
            value = std::strtod(line.substr(11).c_str(), NULL);
            _data[date] = value;
        }
    }
    ifs.close();
    calculate(fileName);
}
