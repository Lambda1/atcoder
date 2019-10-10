#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

int* eratosthenes(int num)
{
	int *array = new int[num+1];
	for(int i = 0;i < num+1;i++) array[i] = 0;
	array[0] = 1;

	for(int i = 2;i < num+1;i++)
	{
		for(int j = 2;j*i < num+1;j++){
			array[j*i]++;
		}
	}
	return array;
}

int* try_div(int num)
{
	int *array = new int[num+1];
	for(int i = 0;i < num+1;i++) array[i] = 0;
	array[0]++;

	for(int i = 1;i < num+1;i++) if(num%i) array[i]++;

	return array;
}

int main(int argc,char *argv[])
{
	int A,B;
	std::cin >> A >> B;

	int max_gcd = ((A>B) ? gcd(A,B) : gcd(B,A));
	int *array = try_div(max_gcd);
	
	for(int i = 2;i < max_gcd+1;i++)
		if(!array[i])
			for(int j = i+1;j < max_gcd+1;j++)
				if(!array[j] && gcd(j,i)!=1) array[j]++;

	int cnt = 0;
	for(int i = 0;i < max_gcd+1;i++) if(!array[i]) cnt++;

	std::cout << cnt << std::endl;

	delete[] array;
	return 0;
}
