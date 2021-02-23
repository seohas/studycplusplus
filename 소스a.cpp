#include <iostream>
using namespace std;
class Car
{
private:
	int gasolinGauge;
public:
	Car(int gas):gasolinGauge(gas)
	{}
	int GetGasGauge()
	{
		return gasolinGauge;
	}
};
class HybridCar:public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elc) :Car(gas), electricGauge(elc)
	{}
	int GetElecGauge()
	{
		return electricGauge;
	}
	
};
class HybridWaterCar :public HybridCar
{
private:
	int waterGaugee;
public:
	HybridWaterCar(int gas,int elc, int water) :HybridCar(gas,elc), waterGaugee(water)
	{}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGaugee << endl;
	}
};
int main(void)
{
	HybridWaterCar fubao(10, 20, 30);
	fubao.ShowCurrentGauge();
	return 0;
}