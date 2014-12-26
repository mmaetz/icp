#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream data;
	data.open ("data.txt");
	int p = 35;
	int c = 13;
	int old_rnd = 1;
	int rnd = 1;
	int n = 100;
	for(int i=0; i<n; i++)
	{
		old_rnd = rnd;
		rnd = (c * rnd) % p;
		data << old_rnd << "\t" << rnd << endl;
	}
	data.close();
	return 0;
} 
