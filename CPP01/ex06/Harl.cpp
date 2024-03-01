#include "Harl.hpp"

#define RED_TEXT "\033[1;31m"
#define ORANGE_TEXT "\033[1;33m"
#define GREEN_TEXT "\033[1;32m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_COLOR "\033[0m"

void Harl::complain( std::string level ) const{
	void (Harl::*infoPtr[4])(void) const = {&Harl::debug, &Harl::info,\
	&Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*infoPtr[i])();		
			break ;
		}
	}
}

void Harl::debug( void ) const{
	std::cout << GREEN_TEXT <<"\n\nDEBUG" << RESET_COLOR <<std::endl;
	std::cout << "I love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n" << std::endl;
}

void Harl::info( void ) const{
	std::cout << BLUE_TEXT <<"\n\nINFO" << RESET_COLOR <<std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."; 
	std::cout << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n" << std::endl;
}

void Harl::warning( void ) const{
	std::cout << ORANGE_TEXT <<"\n\nWARNING" << RESET_COLOR <<std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."; 
	std::cout << " I’ve been coming for years whereas you started working here since last month.\n\n" << std::endl;
}

void Harl::error( void ) const{
	std::cout << RED_TEXT <<"\n\nERROR" << RESET_COLOR <<std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n" << std::endl;
}