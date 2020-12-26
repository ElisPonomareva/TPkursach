#ifndef BUILDERC
#define BUILDERC
#include "Builder.h"
#include "Machine.h"
class BuilderCar : public Builder
{
private:
	Machine* product;
public:

	BuilderCar();
	~BuilderCar();

	void Reset();
	void SetColor() override;
	void SetPrice() override;
	void SetPower() override;
	void SetCreateDate() override;
	void SetCreatorCompany() override;
	void SetModel() override;
	void SetSizes() override;
	void SetFuel() override;
	void SetTypeControl() override;
	void SetExpense() override;
	void SetVolume() override;
	void LoadParams() override;
	void EditParams() override;

	Machine* GetProduct();
};
#endif