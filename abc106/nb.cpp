#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

void Sieve_of_Eratosthenes(int n,int *v)
{
	for(int i = 0;i < n;i++) v[i] = 0;

	v[0] = v[1] = 1;
	for(int i = 2;i <= n;i++)
		for(int j = 1;i*j <= n;j++) v[i*j]++;
	
	int cnt = 0;
	for(int i = 1;i <= n;i+=2){
		//if(v[i]+1 == 8) cnt++;
		//std::cout << i << ":" << v[i] << "  ";
		if((i+1)%10 == 0) std::cout << std::endl;
	}
	std::cout << cnt << std::endl;
}

int main(int argc,char *argv[])
{
	int n;
	int v[201] = {};
	std::cin >> n;

	Sieve_of_Eratosthenes(n,v);

	return 0;
}
