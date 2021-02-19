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
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
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
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << comname << endl;
		cout << "����: ";
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
	NameCard F("Ǫ�ٿ�", "BABY", "01011112222", COMP_POS::CLERK);
	NameCard A("���̹ٿ�", "FOODFIGHTER", "01033334444", COMP_POS::SENIOR);
	NameCard L("���ٿ�", "FUNNY", "01055556666", COMP_POS::ASSIST);
	F.ShowNameCardInfo();
	A.ShowNameCardInfo();
	L.ShowNameCardInfo();
}