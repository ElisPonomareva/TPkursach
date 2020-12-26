#pragma once
#include "Builder.h"
class BuilderQuadrobike : public Builder
{
private:
	Machine* product;
public:

	BuilderQuadrobike();
	~BuilderQuadrobike();

	void Reset();
	/**
	 * Все этапы производства работают с одним и тем же экземпляром продукта.
	 */

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

	/**
	 * Конкретные Строители должны предоставить свои собственные методы
	 * получения результатов. Это связано с тем, что различные типы строителей
	 * могут создавать совершенно разные продукты с разными интерфейсами.
	 * Поэтому такие методы не могут быть объявлены в базовом интерфейсе
	 * Строителя (по крайней мере, в статически типизированном языке
	 * программирования). Обратите внимание, что PHP является динамически
	 * типизированным языком, и этот метод может быть в базовом интерфейсе.
	 * Однако мы не будем объявлять его здесь для ясности.
	 *
	 * Как правило, после возвращения конечного результата клиенту, экземпляр
	 * строителя должен быть готов к началу производства следующего продукта.
	 * Поэтому обычной практикой является вызов метода сброса в конце тела
	 * метода getProduct. Однако такое поведение не является обязательным, вы
	 * можете заставить своих строителей ждать явного запроса на сброс из кода
	 * клиента, прежде чем избавиться от предыдущего результата.
	 */

	Machine* GetProduct();
};
