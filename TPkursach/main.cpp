#include "Manager.h"
#include "BuilderCar.h"
#include "BuilderMotorbike.h"
#include "BuilderQuadrobike.h"

int main()
{
	manager* Manager = new manager();
	Builder* Car = new BuilderCar();
	Builder* Motorbike = new BuilderMotorbike();
	Builder* Quadrobike = new BuilderQuadrobike();
	std::vector <Machine*> masMachines;
	char main;
	while (true)
	{
		system("cls");
		try
		{
			std::cout << "MENU" << std::endl
				<< "0. EXIT" << std::endl
				<< "1. CREATE" << std::endl
				<< "2. EDIT" << std::endl
				<< "3. SAVE" << std::endl
				<< "4. LOAD" << std::endl
				<< "5. PRINT" << std::endl
				<< "6. DELETE" << std::endl
				
				<< ">>> ";
			std::cin >> main;
			if (main < '0' || main > '6')
				throw (std::string)"CHOSE (0, 1, 2, 3, 4, 5, 6)";
			system("cls");
			switch (main)
			{
			case '1':
				system("cls");
				std::cout << "CREATE" << std::endl
					<< "1. CAR" << std::endl
					<< "2. MOTORBIKE" << std::endl
					<< "3. QUADROBIKE" << std::endl
					<< ">>> ";
				std::cin >> main;
				if (main < '1' || main > '3')
				{
					throw (std::string)"CHOOSE (1, 2, 3)";
				}
				switch (main)
				{
				case '1':
					Manager->set_builder(Car);
					Manager->BuildFullProduct();
					masMachines.push_back(Car->GetProduct());
					break;
				case '2':
					Manager->set_builder(Motorbike);
					Manager->BuildFullProduct();
					masMachines.push_back(Motorbike->GetProduct());
					break;
				case '3':
					Manager->set_builder(Quadrobike);
					Manager->BuildFullProduct();
					masMachines.push_back(Quadrobike->GetProduct());
					break;
				default:
					break;
				}
				std::cout << "OBJECT CREATED" << std::endl;
				break;
			default:
				break;
			case '2':
				system("cls");
				std::cout << "EDIT" << std::endl
					<< "1. CAR" << std::endl
					<< "2. MOTORBIKE" << std::endl
					<< "3. QUADROBIKE" << std::endl
					<< ">>> ";
				std::cin >> main;
				if (main < '1' || main > '3')
					throw (std::string)"CHOOSE (1, 2, 3)";
				switch (main)
				{
				case '1':
					Car->EditParams();
					break;
				case '2':
					Motorbike->EditParams();
					break;
				case '3':
					Quadrobike->EditParams();
					break;
				default:
					break;
				}
				std::cout << "OBJECT CHANGED" << std::endl;
				break;
				break;
			case '3':
				Manager->Save(masMachines);
				break;
			case '4':
				masMachines = Manager->Load();
				break;
			case '5':
				for (size_t i = 0; i < masMachines.size(); i++)
					masMachines[i]->ListParts();
				
				break;
			case '6':
				if (!masMachines.empty()) {

					for (size_t j = 0; j < masMachines.size(); j++) 
						std::cout << j + 1 << ". " << masMachines[j]->machine[0] << " " << masMachines[j]->machine[1] << std::endl;

					std::string tmp = "";
					size_t ch = 0;
				
					do {
						std::cout << ">>> ";
						std::cin >> ch;
					} while (ch < 0 || ch > masMachines.size());
					masMachines.erase(masMachines.begin() + (ch - 1));
				}
				break;
			case '0':
				delete Quadrobike;
				delete Motorbike;
				delete Car;
				delete Manager;
				return 0;
			}
			system("pause");
			system("cls");
		}
		catch (std::string err)
		{
			std::cout << "ERROR: " << err << std::endl;
			system("pause");
		}
	}
}
