#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SEQURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(void)
{
	srand(time(NULL));
	int randnums[6] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		randnums[i] = rand() % 100;
		cout << "randnum" << i+1 <<" "<< randnums[i] << endl;
	}
	return 0;
}
