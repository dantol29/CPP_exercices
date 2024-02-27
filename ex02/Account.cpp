#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';' << "total:"\
	<< getTotalAmount() << ';' << "deposits:" << getNbDeposits() << ';' << "withdrawals:"\
	<< getNbWithdrawals() << std::endl; 
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "index:" << _accountIndex << ';' << "p_amount:" << _amount\
	<< ';' << "deposit:" << deposit << ';' << "amount:" << _amount + deposit\
	<< ';' << "nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
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

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';' << "amount:" << _amount\
	<< ';' << "deposits:" << _nbDeposits << ';' << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ){
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

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';' << "amount:" << _amount\
	<< ';' << "closed" << std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t currentTime = std::time(NULL);
	std::tm when = *std::localtime(&currentTime);

	std::cout << '[' << when.tm_year + 1900 << std::setfill('0') << std::setw(2) << when.tm_mon\
	<< std::setfill('0') << std::setw(2) << when.tm_mday << '_'\
	<< std::setfill('0') << std::setw(2) << when.tm_hour\
	<< std::setfill('0') << std::setw(2) << when.tm_min\
	<< std::setfill('0') << std::setw(2) << when.tm_sec << "] "; 
}