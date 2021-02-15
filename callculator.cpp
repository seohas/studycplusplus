#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class Printer
{
private:
	char sentence[20];
public:
	void Setstring(const char *s);
	void Showstring();
};
void Printer::Setstring(const char *s)
{
	strcpy(sentence, s);

}
void Printer::Showstring()
{
	cout << sentence << endl;
}
int main(void)
{
	Printer pnt;
	pnt.Setstring("Hello world!");
	pnt.Showstring();
	pnt.Setstring("I love C++");
	pnt.Showstring();
	return 0;
}