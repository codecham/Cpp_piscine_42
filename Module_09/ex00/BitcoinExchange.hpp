/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:53:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/20 18:42:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		void run(const std::string& database, const std::string& input);

	private:

		typedef struct _s_date
		{
			int y;
			int m;
			int d;

			bool operator<(const _s_date& second) const;
			bool operator<=(const _s_date& second) const;
		} _t_date;

		std::multimap<_s_date, float> _c_database;
		std::string _dataBaseFileName;
		std::string	_inputFileName;
		std::ifstream _database;
		std::ifstream _input;

		struct _s_date  _tmp_date;
		float 			_tmp_value;
		float			_tmp_float;
		std::string		_error_message;
		std::string		_error_filename;
		int				_error_line;

		bool	printError(std::string s) const;
		bool	printError(std::string s, std::string& file, int line) const;
		bool	ErrorMessage(std::string s, std::string& file, int line);
		bool	openFiles(const std::string& database_file, const std::string& input_file);
		bool	checkDataBase();
		bool	checkDate(std::string& date, std::string& file_name, int line);
		bool	checkDay() const;
		bool	checkValueF(std::string& value, std::string& filename, int line);
		bool	checkValueI(std::string& value, std::string& filename, int line);
		bool	checkCharacters(std::string& s, std::string autorizedChars) const;
		void	printResult(std::string &date);
		bool	readInput();
};

#endif