#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Machine
{
public:
	std::vector<std::string> machine;
	void ListParts() const;
};
