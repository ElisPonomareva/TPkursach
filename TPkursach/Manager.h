#ifndef MANAGER
#define MANAGER
#include "Builder.h"
#include "Machine.h"
#include <fstream>
#include <vector>
#include <string>

class manager {

private:
	Builder* builder;

public:

	void set_builder(Builder* builder);
	void Save(std::vector <Machine*> masMachines);
	std::vector <Machine*> Load();
	void BuildFullProduct();
};
#endif