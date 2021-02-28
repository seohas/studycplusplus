//문제 1-상속을 이용하지 않는 HAS-A관계
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{}
	void Shot()
	{
		cout << "BANG!" << endl;
		bullet--;
	}
};
class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police ( const Police& ref) :handcuffs(ref.handcuffs)
	{
		if (ref.pistol!= NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref)
	{
		if (pistol = NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "HUT BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};
int main(void)
{
	Police pman1(3, 5);
	Police pman2 = pman1; //복사 생성자의 호출
	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1; //대입 연산자의 호출
	pman3.PutHandcuff();
	pman3.Shot();
	return 0;
}
