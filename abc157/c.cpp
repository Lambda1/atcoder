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
	ll n,m;
	std::cin >> n >> m;

	std::vector<ll> arr(n,10);
	for(ll i = 0;i < m;++i)
	{
		ll s, c;
		std::cin >> s >> c;
		if(arr[s-1] > c) arr[s-1] = c;
	}

	if(arr[0] == 10 || arr[0] == 0) std::cout << -1 << std::endl;
	else
	{
		for(ll i = 0;i < n;++i)
		{
			if(arr[i] == 10) std::cout << 0;
			else std::cout << arr[i];
		}
		std::cout << std::endl;
	}
	return 0;
}
