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
	ll a,b;
	std::cin >> a >> b;
	
	for(ll i = 1;i < 1100;++i)
	{
		if ((i*8)/100 == a && (i*10)/100 == b)
		{
			std::cout << i << std::endl;
			return 0;
		}
	}

	std::cout << -1 << std::endl;

	return 0;
}
