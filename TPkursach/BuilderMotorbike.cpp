#include "BuilderMotorbike.h"

BuilderMotorbike::BuilderMotorbike()
{
	this->LoadParams();
	this->Reset();
}

BuilderMotorbike::~BuilderMotorbike()
{
	delete product;
}

void BuilderMotorbike::Reset()
{
	this->product = new Machine();
	this->product->machine.resize(12);
	this->product->machine[0] = getMas()[0];
}

void BuilderMotorbike::SetColor()
{
	this->product->machine[1] = getMas()[1];
}

void BuilderMotorbike::SetPrice()
{
	this->product->machine[2] = getMas()[2];
}

void BuilderMotorbike::SetPower()
{
	this->product->machine[3] = getMas()[3];
}

void BuilderMotorbike::SetCreateDate()
{
	this->product->machine[4] = getMas()[4];
}

void BuilderMotorbike::SetCreatorCompany()
{
	this->product->machine[5] = getMas()[5];
}

void BuilderMotorbike::SetModel()
{
	this->product->machine[6] = getMas()[6];
}

void BuilderMotorbike::SetSizes()
{
	this->product->machine[7] = getMas()[7];
}

void BuilderMotorbike::SetFuel()
{
	this->product->machine[8] = getMas()[8];
}

void BuilderMotorbike::SetTypeControl()
{
	this->product->machine[9] = getMas()[9];
}

void BuilderMotorbike::SetExpense()
{
	this->product->machine[10] = getMas()[10];
}

void BuilderMotorbike::SetVolume()
{
	this->product->machine[11] = getMas()[11];
}

void BuilderMotorbike::LoadParams()
{
	getMas().resize(12);
	getMas()[0] = "Machine: Motobike";
	getMas()[1] = "Color: Red";
	getMas()[2] = "Price: 200 000";
	getMas()[3] = "Power: 300w";
	getMas()[4] = "Create Date: 20/04/2020";
	getMas()[5] = "Mark: Mazda";
	getMas()[6] = "Model: RX-8";
	getMas()[7] = "Sizes: 100/140/175";
	getMas()[8] = "Fuel: 95";
	getMas()[9] = "Type Control: AUTO";
	getMas()[10] = "Expense: 3.2";
	getMas()[11] = "Volume: 45";
}

void BuilderMotorbike::EditParams()
{
	system("cls");
	size_t value;
	std::string s_value;
	std::cout << "Select an option to change: " << std::endl;
	for (size_t i = 0; i < getMas().size(); i++)
		std::cout << i << ". " << getMas()[i] << std::endl;
	
	std::cout << ">>> ";
	std::cin >> value;
	if (value < 0 || value > getMas().size()-1)
		throw (std::string)"Parameter selection error";
	
	std::cin.ignore(256, '\n');
	system("cls");
	std::cout << getMas()[value] << std::endl
		<< "New value: ";
	getline(std::cin, s_value);
	if (s_value.empty())
		throw (std::string)"The value can't be empty";
	
	getMas()[value] = getMas()[value].substr(0, getMas()[value].find(":") + 1) + " " + s_value;
}

Machine* BuilderMotorbike::GetProduct()
{
	Machine* result = this->product;
	this->Reset();
	return result;
}
