
#include <iostream>
#include <string>
using namespace std;
int main(void)
{

	int casenum = 0;
	cin >> casenum;
	for (int i = 0; i < casenum; i++)
	{
		int sumnum = 0;
		cin >> sumnum;
		int exprice= -1;
		int* price = new int[sumnum+1];
		string* name = new string[sumnum+1];
		string* maxname = new string;

		for (int j = 0; j < sumnum; j++)
		{
			cin >> price[j] >> name[j];

		}
		for (int j = 0; j < sumnum; j++)
		{
			if (price[j] > exprice)
			{
				exprice = price[j];
				*maxname=name[j];
				
			}
				
		}

		cout << *maxname << endl;
		delete[]price;
		delete[]name;
		delete maxname;
	
	}


	return 0;
}