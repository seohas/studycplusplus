
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) :age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
};
class MyFriendDeTailInfo :public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDeTailInfo(const char* myname, int myage, const char* address, const char* phonnum) :MyFriendInfo(myname, myage)
	{
		addr = new char[strlen(address) + 1];
		phone = new char[strlen(phonnum) + 1];
		strcpy(addr, address);
		strcpy(phone, phonnum);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDeTailInfo()
	{
		delete[]addr;
		delete[]phone;
	}

};
int main(void)
{
	MyFriendDeTailInfo fubao("Fubao", 1, "PANDAWORLD", "01012345678");
	fubao.ShowMyFriendDetailInfo();
	return 0;
}