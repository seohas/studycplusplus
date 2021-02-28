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
//문제 2 상속 이용
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int p) :price(p)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	Book(const Book& ref) :price(ref.price)
	{
		this->title= new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];
		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
	}
	Book& operator=(const Book& ref)
	{
		delete[] title;
		delete[] isbn;
		this->title = new char[strlen(ref.title) + 1];
		this->isbn = new char[strlen(ref.isbn) + 1];
		strcpy(this->title, ref.title);
		strcpy(this->isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};
class Ebook :public Book
{
private:
	char* DRMKey;
public:
	Ebook(const char* title, const char* isbn, int price, const char* DRMKey) :Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	void ShowEbookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	Ebook(const Ebook& ref) :Book(ref)
	{
		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(this->DRMKey, ref.DRMKey);
	}
	Ebook& operator=(const Ebook& ref)
	{
		Book::operator=(ref);
		delete[]DRMKey;
		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(this->DRMKey, ref.DRMKey);
		return *this;
	}
	~Ebook()
	{
		delete[]DRMKey;
	}
};
int main(void)
{
	Book book("Fubao", "2020-07-20", 10000);

	Ebook book1("Fubao", "2020-07-20", 10000, "vhqk07dh20");
	Ebook book2 = book1;
	book2.ShowEbookInfo();
	cout << endl;
	Ebook ebook3("dummy", "dummy", 0, "dummy");
	ebook3 = book2;
	ebook3.ShowEbookInfo();
	return 0;
}
