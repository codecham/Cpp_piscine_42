/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:34:37 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/11 19:52:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount+= this->_amount;
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amout:";
	std::cout << this->_amount;
	std::cout << ";created";
	std::cout << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";closed";
	std::cout << std::endl;
	_nbAccounts--;
	_amount -= this->_amount;
}

Account::Account()
{
	
}

int		Account::getNbAccounts()
{
	return(_nbAccounts);
}

int		Account::getTotalAmount()
{
	return(_totalAmount);
}

int		Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:"
				<< Account::getNbAccounts()
				<< ";total:"
				<< Account::getTotalAmount()
				<< ";deposits:"
				<< Account::getNbDeposits()
				<< ";withdrawals:"
				<< Account::getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount - deposit;
	std::cout << ";deposit:";
	std::cout << deposit;
	std::cout << ";amount:";
	std::cout<< this->_amount;
	std::cout << ";nb_deposits:";
	std::cout << this->_nbDeposits;
	std::cout << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal <= _amount)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal;
		std::cout << ";amount:";
		std::cout << this->_amount;
		std::cout << ";nb_withdrawals:";
		std::cout << this->_nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	std::cout << "refused";
	std::cout << std::endl;
	return (false);
}

int		Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";deposit:";
	std::cout << this->_nbDeposits;
	std::cout << ";withdrawal:";
	std::cout << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t	timestamp = std::time(0);
	tm			*time = localtime(&timestamp);

	std::cout	<< "["
				<< time->tm_year + 1900
				<< time->tm_mon
				<< time->tm_mday
				<< '_'
				<< time->tm_hour
				<< time->tm_min
				<< time->tm_sec
				<< "] ";
}