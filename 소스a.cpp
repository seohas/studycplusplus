#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class  Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	virtual void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};
class PermenentWorker :public Employee
{
private:
	int salary;
public:
	PermenentWorker(const char* name, int money) :Employee(name), salary(money)
	{}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};
class temporaryWorker :public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	temporaryWorker(const char* name, int pay) :Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};
class SalesWorker :public PermenentWorker
{
private:
	int SalesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio) :PermenentWorker(name, money), SalesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value)
	{
		SalesResult += value;
	}
	int GetPay() const
	{
		return PermenentWorker::GetPay() + (int)(SalesResult * bonusRatio);
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

namespace RISK_LEVEL
{
	enum {RISK_A=30,RISK_B=20,RISK_C=10};
}
class ForeignSalesWorker :public SalesWorker
{
private:
	const int risklevel;
public:
	ForeignSalesWorker(const char* name, int result, double ratio, int level) :SalesWorker(name, result, ratio), risklevel(level)
	{}
	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * risklevel / 100);
	}
	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo()const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay:" << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl<<endl;
	}

};
class EmployHandler
{
private:
	Employee* emplist[50];
	int empNum;
public:
	EmployHandler() :empNum(0)
	{}
	void AddEmployee(Employee* emp)
	{
		emplist[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			emplist[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary()const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetPay();
		}
		cout << "Salary sum: " << sum << endl;
	}
	~EmployHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete emplist[i];
		}
	}
};
int main(void)
{
	EmployHandler handler;
	ForeignSalesWorker* fubao = new ForeignSalesWorker("푸바오", 1000, 0.1, RISK_LEVEL::RISK_A);
	fubao->AddSalesResult(7000);
	handler.AddEmployee(fubao);
	ForeignSalesWorker* aibao = new ForeignSalesWorker("아이바오", 1000, 0.1, RISK_LEVEL::RISK_B);
	aibao->AddSalesResult(7000);
	handler.AddEmployee(aibao);
	ForeignSalesWorker* lebao = new ForeignSalesWorker("러바오", 1000, 0.1, RISK_LEVEL::RISK_C);
	lebao->AddSalesResult(7000);
	handler.AddEmployee(lebao);
	handler.ShowAllSalaryInfo();
	return 0;

}