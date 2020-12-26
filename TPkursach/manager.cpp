#include "Manager.h"

void manager::set_builder(Builder* builder)
{
	this->builder = builder;
}

void manager::Save(std::vector<Machine*> masMachines)
{
	std::ofstream fo_car("Car.txt");
	std::ofstream fo_moto("Motobike.txt");
	std::ofstream fo_quad("Quadrobike.txt");
	for (size_t i = 0; i < masMachines.size(); i++)
	{
		if (masMachines[i]->machine[0] == "Machine: Car")
			for (size_t j = 0; j < masMachines[i]->machine.size(); j++)
				fo_car << masMachines[i]->machine[j] << std::endl;
			
		if (masMachines[i]->machine[0] == "Machine: Motobike")
			for (size_t j = 0; j < masMachines[i]->machine.size(); j++)
				fo_moto << masMachines[i]->machine[j] << std::endl;
			
		if (masMachines[i]->machine[0] == "Machine: Quadrobike")
			for (size_t j = 0; j < masMachines[i]->machine.size(); j++)
				fo_quad << masMachines[i]->machine[j] << std::endl;
			
	}
	fo_car.close();
	fo_moto.close();
	fo_quad.close();
}

std::vector<Machine*> manager::Load()
{
	std::string line;
	std::vector <Machine*> tmp;
	std::ifstream fin;
	fin.open("Car.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1) break;
		tmp.push_back(new Machine);
		for (size_t i = 0; i < 12; i++)
		{
			getline(fin, line);
			tmp[tmp.size() - 1]->machine.push_back(line);
		}
	}
	fin.close();
	fin.open("Motobike.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1) break;
		tmp.push_back(new Machine);
		for (size_t i = 0; i < 12; i++)
		{
			getline(fin, line);
			tmp[tmp.size() - 1]->machine.push_back(line);
		}
	}
	fin.close();
	fin.open("Quadrobike.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1) break;
		tmp.push_back(new Machine);
		for (size_t i = 0; i < 12; i++)
		{
			getline(fin, line);
			tmp[tmp.size() - 1]->machine.push_back(line);
		}
	}
	fin.close();
	return tmp;
}

void manager::BuildFullProduct()
{
	this->builder->SetColor();
	this->builder->SetPrice();
	this->builder->SetPower();
	this->builder->SetCreateDate();
	this->builder->SetCreatorCompany();
	this->builder->SetModel();
	this->builder->SetSizes();
	this->builder->SetFuel();
	this->builder->SetTypeControl();
	this->builder->SetExpense();
	this->builder->SetVolume();
}

