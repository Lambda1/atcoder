#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}

int main(int argc,char *argv[])
{
	int n,x;
	std::cin >> n >> x;

	std::vector<int> v(n);
	for(int i = 0;i < n;i++){
		std::cin >> v[i];
		v[i] = abs(v[i]-x);
	}
	
	int d = v[0];
	for(int i = 1;i < n;i++) d = gcd(MAX(d,v[i]),MIN(d,v[i]));

	std::cout << d << std::endl;

	return 0;
}
