#ifndef BUILDERM
#define BUILDERM
#include "Builder.h"
class BuilderMotorbike : public Builder
{
private:
	Machine* product;
public:

	BuilderMotorbike();
	~BuilderMotorbike();

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