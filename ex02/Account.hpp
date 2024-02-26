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
		std::cout << "accounts: " << getNbAccounts() << ";total: " << getTotalAmount()
              << ";deposits: " << getNbDeposits() << ";withdrawals: " << getNbWithdrawals() << std::endl;
	}

	Account( int initial_deposit ){
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
}
	~Account( void ){
		
	}

	void	makeDeposit( int deposit ){
		_displayTimestamp();
    	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";deposit:" << deposit;
		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
		std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}
	bool	makeWithdrawal( int withdrawal ){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
					<< ";withdrawal:" << withdrawal;
		if (_amount >= withdrawal) {
			_amount -= withdrawal;
			_nbWithdrawals++;
			_totalAmount -= withdrawal;
			_totalNbWithdrawals++;
			std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
			return true;
		} 
		else {
			std::cout << ";refused" << std::endl;
			return false;
		}
	}
	int		checkAmount( void ){
		return (_amount);
	}
	void	displayStatus( void ){
		_displayTimestamp();
    	std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	}


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ){
		std::cout << "[timestamp]";
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
