/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BictoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:59:29 by dcorenti          #+#    #+#             */
/*   Updated: 2023/05/22 23:54:11 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	_c_database = copy._c_database;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		_c_database = copy._c_database;
	}
	return (*this);
}

/*-----------------------------Run Function----------------------------------------*/

void	BitcoinExchange::run(const std::string& database, const std::string& input)
{
	if (!_c_database.empty())
		_c_database.clear();
	if (!openFiles(database, input))
	 	return ;
	if (!parseDataBase())
		return ;
	readInput();
}

/*-----------------------------Errors Functions-------------------------------------*/

bool 	BitcoinExchange::printError(const std::string& s) const
{
	std::cout << "Error: " << s << std::endl;
	return(false);
}

bool 	BitcoinExchange::printError(const std::string& s, const int line) const
{
	std::cout << "Error: In database at line " << line << ": " << s << std::endl;
	return(false);
}

/*-----------------------------Files Function-------------------------------------*/

bool	BitcoinExchange::openFiles(const std::string& database_file, const std::string& input_file)
{
	if (database_file.size() < 4 || database_file.substr((database_file.size() - 4 ), 4) != ".csv")
		return (printError("DataBase file must be a .csv file"));
	_database.open(database_file);
	if (!_database)
		return (printError("Can't open the .csv file"));
	_input.open(input_file);
	if (!_input)
		return (printError("Can't open the input file"));
	return(true);
}

/*-----------------------------DataBase Function-------------------------------------*/

bool	BitcoinExchange::parseDataBase()
{
	std::string line;
	_t_date date;
	float value;
	int index_line = 2;
	
	std::getline(_database, line);
	if (line != "date,exchange_rate")
		return(printError("This line must be \"date,exchange_rate\"", 1));
	while(std::getline(_database, line))
	{
		if (line[4] != '-' || line[7] != '-' || line[10] != ',' || line.size() < 12)
			return(printError("Wrong format. Format must be YYYY-MM-DD,[value]", index_line));
		if (!checkDateDataBase(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2), date, index_line) || !checkValueDataBase(line.substr(11, (line.size() - 11)), value, index_line))
			return(false);
		_c_database.insert(std::make_pair(date, value));
		index_line++;
	}
	if (_c_database.empty())
		return(printError("Database empty"));
	return(true);
}

bool	BitcoinExchange::checkDateDataBase(std::string years, std::string month, std::string day, BitcoinExchange::_t_date& date, int& index_line) const
{
	if (!checkCharacters(years, "0123456789") || !checkCharacters(month, "0123456789") || !checkCharacters(day, "0123456789"))
		return(printError("Wrong character in date", index_line));
	date.y = atoi(years.c_str());
	date.m = atoi(month.c_str());
	date.d = atoi(day.c_str());
	if (date.m < 1 || date.m > 12)
		return(printError("Wrong month", index_line));
	if (!checkDay(date))
		return(printError("This day at this month doesn't exist", index_line));
	return(true);
}

bool	BitcoinExchange::checkValueDataBase(std::string str_value, float& value, int& index_line) const
{
	char *endptr;
	
	if (!checkCharacters(str_value, "0123456789."))
		return(printError("Wrong character in date", index_line));
	value = strtof(str_value.c_str(), &endptr);
	if (*endptr)
		return(printError("Wrong character in date", index_line));
	return(true);
}

/*-----------------------------Input Function-------------------------------------*/

void	BitcoinExchange::readInput()
{
	std::string line;
	_t_date date;
	float value;
	
	std::getline(_input, line);
	if (line != "date | value")
	{
		std::cout << "Error in input file: First line must be \"date | value\"" << std::endl;
		return ;
	}
	while (std::getline(_input, line))
	{
		if (line.empty())
			std::cout << "Error: line empty" << std::endl;  
		else if (line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{	
			if (checkDateInput(line.substr(0, 10), date))
			{
				if (checkValueInput(line.substr(13, (line.size() - 13)), value))
					printResult(date, line.substr(0, 10), value);
			}
		}
	}
}

bool 	BitcoinExchange::checkDateInput(std::string str_date, BitcoinExchange::_t_date& date)
{
	std::string years = str_date.substr(0, 4);
	std::string month = str_date.substr(5, 2);
	std::string day = str_date.substr(8, 2);

	if (str_date[4] != '-' || str_date[7] != '-')
		return(printError("Bad date format"));
	if (!checkCharacters(years, "0123456789") || !checkCharacters(month, "0123456789") || !checkCharacters(day, "0123456789"))
		return(printError("Bad character in date"));
	date.y = atoi(years.c_str());
	date.m = atoi(month.c_str());
	date.d = atoi(day.c_str());
	if (date.m < 1 || date.m > 12)
		return(printError("Bad month"));
	if (!checkDay(date))
		return(printError("This day on this month doesn't exist"));
	return(true);
}

bool	BitcoinExchange::checkValueInput(std::string str_value, float& value)
{
	char *endptr;

	if (str_value[0] == '-')
		return(printError("not a positive number"));
	if (!checkCharacters(str_value, ".0123456789"))
		return(printError("Bad character in value"));
	value = strtof(str_value.c_str(), &endptr);
	if (*endptr)
		return(printError("Bad character in value"));
	if (str_value.size() > 4 || value > 1000)
		return(printError("Too large number"));
	return(true);
}

void	BitcoinExchange::printResult(BitcoinExchange::_t_date& date, std::string str_date, float value)
{
	std::multimap<_s_date, float>::iterator it = _c_database.begin();
	float result;

	if (date < (*it).first)
		std::cout << "Error: this date: [" << str_date << "] or lower date can't be found" << std::endl;
	else
	{
		while (it != _c_database.end() && it->first <= date)
			it++;
		it--;
		result = value * it->second; 
		std::cout << str_date << " => " << value << " = " << result << std::endl;
	}
}

/*----------------------------Utils Functions--------------------------------------*/

bool	BitcoinExchange::checkDay(BitcoinExchange::_t_date& date) const
{
	if (date.d <= 0 || date.d >= 32)
		return (false);
	if (date.m == 2)
	{
		if (date.d <= 28)
			return (true);
		if (date.d > 29)
			return (false);
		if (date.d == 29 && date.y % 4 != 0)
			return (false);
		else
			return (true);
	}
	if (date.d <= 30)
		return (true);
	if (date.d == 31)
	{
		if (date.m == 4 || date.m == 6 || date.m == 9 || date.m == 11)
			return (false);
	}
	return(true);
}

bool	BitcoinExchange::checkCharacters(std::string& s, std::string autorizedChars) const
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < s.size())
	{
		j = 0;
		while (j < autorizedChars.size())
		{
			if (s[i] == autorizedChars[j])
				break;
			j++;
		}
		if (j == autorizedChars.size())
			return(false);
		i++;
	}
	return(true);
}

/*-------------------------------Operators----------------------------------------*/

bool	BitcoinExchange::_s_date::operator<(const _s_date& second) const
{
	if (this->y < second.y)
		return(true);
	else if (this->y > second.y)
		return(false);
	else if (this->m < second.m)
		return(true);
	else if (this->m > second.m)
		return (false);
	else if (this->d < second.d)
		return(true);
	return(false);
}

bool	BitcoinExchange::_s_date::operator<=(const _s_date& second) const
{
	if (this->y == second.y && this->m == second.m && this->d == second.d)
		return(true);
	if (this->y < second.y)
		return(true);
	else if (this->y > second.y)
		return(false);
	else if (this->m < second.m)
		return(true);
	else if (this->m > second.m)
		return (false);
	else if (this->d < second.d)
		return(true);
	return(false);
}