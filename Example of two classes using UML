//1번
#include <iostream>
using namespace std;
class Rectangle
{
private:
	int length;
	int width;
public:
	Rectangle(int l, int w) :length(l), width(w)
	{}
	void ShowAreaInfo()
	{
		cout << "면적: " << length * width << endl;
	}

};
class Square :public Rectangle
{

public:
	Square(int l) :Rectangle(l, l)
	{}

};
int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}



//2번

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
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
		strcpy(this->isbn,isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
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
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~Ebook()
	{
		delete[]DRMKey;
	}
};
int main(void)
{
	Book book("푸바오", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	Ebook ebook("푸바오 ebook", "555-12345-890-1", 10000, "vnqkdh0wn720");
	ebook.ShowEBookInfo();
	return 0;
}
