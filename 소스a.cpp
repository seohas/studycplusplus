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