#pragma once
#include <iostream>

namespace MenuUtil
{
	int GetValidIntInput(int min, int max);
	std::string GetValidStringInput();
	void Print(const char* output);
    void Print(std::basic_string<char> output);
}