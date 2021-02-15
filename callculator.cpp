#include <iostream>
using namespace std;
class Calculator
{
private:
	
	int sum[4] = { 0 };
public:
	double cal_Add(double num1, double num);
	double cal_Min(double num1, double num2);
	double cal_Mult(double num1, double num2);
	void ShowOpCount();
	double cal_Div(double num1, double num2);
	void Init();
};

	void Calculator::ShowOpCount()
	{
		cout << "µ¡¼À:" << sum[0]<<" " << "»¬¼À:" << sum[1] << " "<<"°ö¼À:" << sum[2] <<" "<<"³ª´°¼À:" << sum[3];
	}
	void Calculator::Init()
	{
		int sum[4] = { 0 };
	}

	double Calculator::cal_Add(double num1, double num2)
	{
		sum[0]++;
		return  num1 + num2;


	}
	double Calculator::cal_Min(double num1, double num2)
	{
		sum[1]++;
		return  num1 - num2;
	}
	double Calculator::cal_Mult(double num1, double num2)
	{
		sum[2]++;
		return num1 * num2;
	}
	double Calculator::cal_Div(double num1, double num2)
	{
		sum[3]++;
		return num1 / num2;
	}

int main(void)
{
	Calculator cal;
	cout << "3.2+2.4=" << cal.cal_Add(3.2, 2.4) << endl;
	cout << "3.2/1.7=" << cal.cal_Div(3.5, 1.7) << endl;
	cout << "2.2-1.5=" << cal.cal_Min(2.2,1.5) << endl;
	cout << "4.9/1.2 =" << cal.cal_Div(4.9,1.2) << endl;
	cal.ShowOpCount();
	return 0;
}