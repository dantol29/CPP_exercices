// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ){
		return (_nbAccounts);
	}
	static int	getTotalAmount( void ){
		return (_totalAmount);
	}
	static int	getNbDeposits( void ){
		return (_totalNbDeposits);
	}
	static int	getNbWithdrawals( void ){
		return (_totalNbWithdrawals);
	}
	static void	displayAccountsInfos( void ){
		_displayTimestamp();
		std::cout << "accounts:" << getNbAccounts() << ';' << "total:"\
		<< getTotalAmount() << ';' << "deposits:" << getNbDeposits() << ';' << "withdrawals:"\
		<< getNbWithdrawals() << std::endl; 
	}
	Account( int initial_deposit ){
		_displayTimestamp();
		_totalAmount += initial_deposit;
		_nbAccounts += 1;
		_accountIndex = _nbAccounts - 1;
		_amount = initial_deposit;
		_nbWithdrawals = 0;
		_nbDeposits = 0;
		std::cout << "index:" << _accountIndex << ';' << "amount:" << _amount\
		<< ';' << "created" << std::endl;
	}
	~Account( void ){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';' << "amount:" << _amount\
		<< ';' << "closed" << std::endl;
	}

	void	makeDeposit( int deposit ){
		_displayTimestamp();
		_nbDeposits += 1;
		_totalNbDeposits += 1;
		std::cout << "index:" << _accountIndex << ';' << "p_amount:" << _amount\
		<< ';' << "deposit:" << deposit << ';' << "amount:" << _amount + deposit\
		<< ';' << "nb_deposits:" << _nbDeposits << std::endl;
		_amount += deposit;
	}
	bool	makeWithdrawal( int withdrawal ){
		_displayTimestamp();
		if (withdrawal > _amount)
		{
			std::cout << "index:" << _accountIndex << ';' << "p_amount:" << _amount\
			<< ';' << "withdrawal:" << "refused" << std::endl;
			return (0);
		}
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		std::cout << "index:" << _accountIndex << ';' << "p_amount:" << _amount\
		<< ';' << "withdrawal:" << withdrawal << ';' << "amount:" << _amount - withdrawal\
		<< ';' << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		return (1);
	}
	void	displayStatus( void ){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';' << "amount:" << _amount\
		<< ';' << "deposits:" << _nbDeposits << ';' << "withdrawals:" << _nbWithdrawals << std::endl;
	}


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ){
		std::cout << "[timestamp] ";
	}

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
