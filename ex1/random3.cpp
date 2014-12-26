#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
//	ofstream data;
//	data.open ("data.txt");
	int p = 50;
	int c = 13;
	int rnd = 1;
	int n = 99;
	int k = 5;
	double size = p/k;
	double p_i = 1/double(k);
	double chival1,chival2;
	std::vector<double> N_vec (k);
	std::vector<double> chi_vec;
	for(int i=0; i<n; i++)
	{
		rnd = (c * rnd) % p;
		for(int j=0; j<k; j++)
		{
//			cout << rnd << endl;
			if(j*size < rnd && rnd < (j+1)*size)
			{
				N_vec[j]=N_vec[j]+1;
				break;
			}
		}
//		data << j << endl;
	}
	for(int l=0; l<k; l++)
	{
		chival1 = (N_vec[l]-n*p_i);
		chival2 = n*p_i;
		chi_vec.push_back(chival1*chival1/chival2);
	}
//	data.close();
	double chi_sum = std::accumulate(chi_vec.begin(),chi_vec.end(),0);
//	cout << chi_vec[1] << endl;
	cout << chi_sum << endl;
	return 0;
} 
