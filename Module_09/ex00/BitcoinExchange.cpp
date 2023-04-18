/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:59:29 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/18 22:29:45 by dcorenti         ###   ########.fr       */
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
	_dataBaseFileName = copy._dataBaseFileName;
	_inputFileName = copy._inputFileName;
	_tmp_date = copy._tmp_date;
	_tmp_float = copy._tmp_float;
	_tmp_value = copy._tmp_value;
	_error_message = copy._error_message;
	_error_filename = copy._error_filename;
	_error_line = copy._error_line;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if(this != &copy)
	{
		_c_database = copy._c_database;
		_dataBaseFileName = copy._dataBaseFileName;
		_inputFileName = copy._inputFileName;
		_tmp_date = copy._tmp_date;
		_tmp_float = copy._tmp_float;
		_tmp_value = copy._tmp_value;
		_error_message = copy._error_message;
		_error_filename = copy._error_filename;
		_error_line = copy._error_line;
	}
	return(*this);
}

/*------------------------------------------------------------------------------*/

void	BitcoinExchange::run(const std::string& database, const std::string& input)
{
	if (!openFiles(database, input))
	 	return ;
	if (!checkDataBase())
		return ;
	readInput();
}

bool 	BitcoinExchange::printError(std::string s) const
{
	std::cout << "Error: " << s << std::endl;
	return(false);
}

bool 	BitcoinExchange::ErrorMessage(std::string s, std::string& file, int line)
{
	_error_message = s;
	_error_filename = file;
	_error_line	= line;
	return(false);
}

bool 	BitcoinExchange::printError(std::string s, std::string& file, int line) const
{
	std::cout << "Error: In " << file << " at line " << line << ": " << s << std::endl;
	return(false);
}

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
	_dataBaseFileName = database_file;
	_inputFileName = input_file;
	return(true);
}

/*------------------------------------------------------------------------------*/

bool	BitcoinExchange::checkDataBase()
{
	std::string date;
	std::string value;
	std::string line;
	std::multimap<BitcoinExchange::_t_date, float>::iterator it;
	int i;

	it = _c_database.begin();
	std::getline(_database, line);
	i = 2;
	if (line != "date,exchange_rate")
		return (printError("First line of database must be \"date,exchange_rate\""));
	while (std::getline(_database, line))
	{
		if (line.empty())
			return (printError("Empty line", _dataBaseFileName, i));
		if (line.size() < 11 || line[10] != ',')
			return (printError("Format must be YYYY-MM-DD,[float_value]", _dataBaseFileName, i));
		date = line.substr(0, 10);
		value = line.substr(11, (line.size() - 11));
		if (!checkDate(date, _dataBaseFileName, i) || !checkValueF(value, _dataBaseFileName, i))
			return(printError(_error_message, _error_filename, _error_line));
		_c_database.insert(it, std::pair<BitcoinExchange::_t_date, float>(_tmp_date, _tmp_value));
		i++;
	}
	return(true);
}

bool	BitcoinExchange::checkDate(std::string& date, std::string& file_name, int line)
{
	std::string years;
	std::string month;
	std::string	day;
	char 	*endptr;

	if (date[4] != '-' || date[7] != '-')
		return(ErrorMessage("Format date must be YYYY-MM-DD", file_name, line));
	years = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	if (!checkCharacters(years, "0123456789") || !checkCharacters(month, "0123456789") || !checkCharacters(day, "0123456789"))
		return (ErrorMessage("Wrong character(s) in date", file_name, line));
	_tmp_date.y = (int)strtol(years.c_str(), &endptr, 10);
	_tmp_date.m = (int)strtol(month.c_str(), &endptr, 10);
	_tmp_date.d = (int)strtol(day.c_str(), &endptr, 10);
	if (_tmp_date.y < 0)
		return (ErrorMessage("Wrong years. Bitcoin starts in 2009", file_name, line));
	if (_tmp_date.m < 1 || _tmp_date.m > 12)
		return (ErrorMessage("Wrong month. Must be between 1 and 12", file_name, line));
	if (!checkDay())
		return(ErrorMessage("The day in this month doesn't exist", file_name, line));
	return (true);
}

bool	BitcoinExchange::checkDay() const
{
	if (_tmp_date.d <= 0)
		return (false);
	if (_tmp_date.m == 2)
	{
		if (_tmp_date.d <= 28)
			return (true);
		if (_tmp_date.d > 29)
			return (false);
		if (_tmp_date.d == 29 && _tmp_date.y % 4 != 0)
			return (false);
		else
			return (true);
	}
	if (_tmp_date.d <= 30)
		return (true);
	if (_tmp_date.d == 31)
	{
		if (_tmp_date.m == 4 || _tmp_date.m == 6 || _tmp_date.m == 9 || _tmp_date.m == 11)
			return (false);
	}
	return(true);
}

bool	BitcoinExchange::checkValueF(std::string& value, std::string& filename, int line)
{
	char *endptr;

	if (!checkCharacters(value, "0123456789."))
		return (ErrorMessage("Wrong character(s) in value", filename, line));
	_tmp_value = strtof(value.c_str(), &endptr);
	if (*endptr)
		return(ErrorMessage("Wrong character(s) in value", filename, line));
	return(true);
}

bool	BitcoinExchange::checkValueI(std::string& value, std::string& filename, int line)
{
	char *endptr;

	if (!checkCharacters(value, "-0123456789."))
		return (ErrorMessage("Wrong character(s) in value", filename, line));
	_tmp_float = strtof(value.c_str(), &endptr);
	if (*endptr)
		return(ErrorMessage("Wrong character(s) in value", filename, line));
	if (_tmp_float < 0)
		return(ErrorMessage("Not a positive number", filename, line));
	if (_tmp_float > 1000)
		return(ErrorMessage("Too large number", filename, line));
	return(true);
}

/*-----------------------------------------------------------------------------*/

bool	BitcoinExchange::readInput()
{
	std::string line;
	std::string date;
	std::string value;
	int i;

	i = 1;
	std::getline(_input, line);
	if (line.empty() || line != "date | value")
		return (printError("Line must be \"date | value\"", _inputFileName, 1));
	while(std::getline(_input, line))
	{
		if (line.empty())
			std::cout << "Error: empty line" << std::endl;
		else if (line.size() < 14 || line[11] != '|')
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			date = line.substr(0, 10);
			if (checkDate(date, _inputFileName, i))
			{
				value = line.substr(13, line.size() - 13);	
				if (checkValueI(value, _inputFileName, i))
					printResult(date);
				else
					std::cout << "Error: " << _error_message << " => " << line << std::endl;
			}
			else
				std::cout << "Error: " << _error_message << " => " << line << std::endl;
		}
	}
	return(true);
}

void	BitcoinExchange::printResult(std::string& date)
{
	std::multimap<_s_date, float>::iterator it;
	float value_in_db;
	float result;

	it = _c_database.begin();
	value_in_db = -1;
	if (_tmp_date < (*it).first)
	{
		std::cout << "Error: this date: [" << _tmp_date.y << "-" <<_tmp_date.m << "-" << _tmp_date.d << "] or lower date can't be found" << std::endl;
		return ;
	}
	while(it != _c_database.end() && (*it).first <= _tmp_date)
	{
		value_in_db = (*it).second;
		it++;
	}
	if (value_in_db == -1)
	{
		std::cout << "Error: this date: [" << _tmp_date.y << "-" <<_tmp_date.m << "-" << _tmp_date.d << "] or lower date can't be found" << std::endl;
		return ;
	}
	else
	{
		result = value_in_db * _tmp_float;
		std::cout << date << " => " << _tmp_float << " = " << result << std::endl; 
	}
}

/*------------------------------------------------------------------------------*/

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

/*------------------------------------------------------------------------------*/

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