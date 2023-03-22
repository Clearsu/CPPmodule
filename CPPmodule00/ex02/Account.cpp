/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:05:19 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/22 18:22:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <iostream>
#include "Account.hpp"

// public
int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accouts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposites:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {
	_amount = initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account(void) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	p_amount = _amount;
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "deposits:" << deposit << ';';
	_amount += deposit;
	std::cout << "amount:" << _amount << ';';
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	int p_amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	p_amount = _amount;
	std::cout << "p_amount:" << p_amount << ';';
	if (_amount < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ';';
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ';';
	_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return (true);
}

//int		checkAmount( void ) const;

void	Account::displayStatus( void ) const { 
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "ammount:" << _amount << ';';
	std::cout << "deposits:"<< _nbDeposits << ';';
	std::cout << "withdrawals:"<< _nbWithdrawals << std::endl;
}

// private
void	Account::_displayTimestamp( void ) {
	time_t		curTime = time(NULL);
	struct tm	*pLocal = localtime(&curTime);

	std::cout << '[' << pLocal->tm_year + 1900;
	std::cout << pLocal->tm_mon + 1 << pLocal->tm_mday;
	std::cout << '_' << pLocal->tm_hour << pLocal->tm_min;
	std::cout << pLocal->tm_sec << ']';
}

//Account(void);
