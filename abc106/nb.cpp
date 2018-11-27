#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

void Sieve_of_Eratosthenes(int n,std::vector<int> *s)
{
	int *v = new int[201];
	for(int i = 0;i < n;i++) v[i] = 0;

	v[0] = v[1] = 1;
	for(int i = 2;i < sqrt(n);i++)
		for(int j = 2;i*j < n;j++) v[i*j] = 1;
	
	for(int i = 0;i < n;i++)
		if(!v[i]) s->push_back(i);
	
	delete [] v;
}

int main(int argc,char *argv[])
{
	int n;
	int s[201] = {};
	std::vector<int> v;
	std::cin >> n;

	Sieve_of_Eratosthenes(n,&v);

	for(int i = 0;i < v.size();i++){
		if(!(n%v[i])){
			s[v[i]]++;
			n /= v[i];
			i = -1;
		}
	}
	return 0;
}
