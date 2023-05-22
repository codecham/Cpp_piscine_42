/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:53:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/05/22 22:33:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
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
		std::ifstream _database;
		std::ifstream _input;

		bool	printError(const std::string& s) const;
		bool	printError(const std::string& s, const int line) const;
		bool	openFiles(const std::string& database_file, const std::string& input_file);
		bool	checkCharacters(std::string& s, std::string autorizedChars) const;
		bool	checkDay(BitcoinExchange::_t_date& date) const;
		bool	checkValueDataBase(std::string str_value, float& value, int& index_line) const;
		bool	checkDateDataBase(std::string years, std::string month, std::string day, BitcoinExchange::_t_date& date, int& index_line) const;
		bool	checkDateInput(std::string str_date, BitcoinExchange::_t_date& date);
		bool	checkValueInput(std::string str_value, float& value);
		void	printResult(BitcoinExchange::_t_date& date, std::string str_date, float value);
		bool	parseDataBase();
		void	readInput();
};

#endif