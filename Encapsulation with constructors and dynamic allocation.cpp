#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void ShowPositon(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
		}
	}

}
class NameCard
{
private:
	char* name;
	char* comname;
	char* phonum;
	int position;
public:
	NameCard(const char* person, const char* company, const char* phone, int pos) :position(pos)
	{
		name = new char[strlen(person) + 1];
		comname = new char[strlen(company) + 1];
		phonum = new char[strlen(phone) + 1];
		strcpy(name, person);
		strcpy(comname, company);
		strcpy(phonum, phone);
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << comname << endl;
		cout << "직급: ";
		COMP_POS::ShowPositon(position);
		cout << endl;
	}
	~NameCard()
	{
		delete[]name;
		delete[]comname;
		delete[]phonum;

	}
};
int main(void)
{
	NameCard F("푸바오", "BABY", "01011112222", COMP_POS::CLERK);
	NameCard A("아이바오", "FOODFIGHTER", "01033334444", COMP_POS::SENIOR);
	NameCard L("러바오", "FUNNY", "01055556666", COMP_POS::ASSIST);
	F.ShowNameCardInfo();
	A.ShowNameCardInfo();
	L.ShowNameCardInfo();
}


//this포인터와 복사 생성자를 이용
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void ShowPositon(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
		}
	}

}
class NameCard
{
private:
	char* name;
	char* company;
	char* phonum;
	int position;
public:
	NameCard(const char* name, const char* company, const char* phonum, int pos) :position(pos)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phonum = new char[strlen(phonum) + 1];
		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phonum, phonum);
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "직급: ";
		COMP_POS::ShowPositon(position);
		cout << endl;
	}
	NameCard(const NameCard& copy): position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		phonum = new char[strlen(copy.phonum) + 1];
		strcpy(phonum, copy.phonum);

	}
	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phonum;

	}
};
int main(void)
{
	NameCard F("푸바오", "BABY", "01011112222", COMP_POS::CLERK);
	NameCard copy1 = F;
	NameCard A("아이바오", "FOODFIGHTER", "01033334444", COMP_POS::SENIOR);
	NameCard copy2 = A;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}
