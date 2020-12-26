#pragma once
#include "Machine.h"

class Builder {
	std::vector<std::string> arrayParams;
public:
	virtual ~Builder() {}
	virtual void SetColor() = 0;			//Цвет
	virtual void SetPrice() = 0;			//Цена
	virtual void SetPower() = 0;			//Объем двигателя
	virtual void SetCreateDate() = 0;		//Год выпуска
	virtual void SetCreatorCompany() = 0;	//Марка
	virtual void SetModel() = 0;			//Модель
	virtual void SetSizes() = 0;			//Размеры
	virtual void SetFuel() = 0;			    //Топливо
	virtual void SetTypeControl() = 0;	    //Тип рулегово управления
	virtual void SetExpense() = 0;		    //Расход топлива
	virtual void SetVolume() = 0;			//Объем багажника
	virtual void LoadParams() = 0;
	virtual void EditParams() = 0;
	std::vector<std::string>& getMas();
	virtual Machine* GetProduct() = 0;
};
