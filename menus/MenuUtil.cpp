#include "MenuUtil.h"
#include <iostream>

namespace MenuUtil
{
	int GetValidIntInput(int min, int max)
	{
		std::cout << "\nPlease enter your choice:";
		int tmp;
		std::cin >> tmp;
		while (!std::cin >> tmp || tmp > max || tmp < min) 
		{
			std::cout << "Not a valid input, please try again:";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
			std::cin >> tmp;
		}
		return tmp;
	}

	std::string GetValidStringInput()
    {
	    std::string tmp = "";
	    while(tmp.empty())
        {
	        std::getline(std::cin, tmp);
        }
	    return tmp;
    }

	void Print(const char* output)
	{
		std::cout << output;
	}

    void Print(std::basic_string<char> output)
    {
        std::cout << output;
    }
}