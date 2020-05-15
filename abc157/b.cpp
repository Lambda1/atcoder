#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <bitset>

using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	// Absolute
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	// GCD: a > b
	ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }
}

int main(int argc,char *argv[])
{
	ll array[9]={};
	for(int i = 0;i < 9;++i) std::cin >> array[i];
	
	ll n;
	std::cin >> n;

	for(int i = 0;i < n;++i)
	{
		ll b;
		std::cin >> b;
		for(int i = 0;i < 9;++i)
			if(array[i] == b) { array[i] = -1; break; }
	}
	
	// 縦横
	for(int i = 0;i < 3;++i)
	{
		ll v=0,h=0;
		for(int j = 0;j < 3;++j)
		{
			if(array[i*3+j] == -1) ++v;
			if(array[j*3+i] == -1) ++h;
		}
		if(v==3 || h==3){ std::cout << "Yes" << std::endl; return 0; }
	}
	// 斜め
	if(array[0] == array[4] && array[8] == -1) { std::cout << "Yes" << std::endl; return 0; }
	if(array[2] == array[4] && array[6] == -1) { std::cout << "Yes" << std::endl; return 0; }

	std::cout << "No" << std::endl;

	return 0;
}
