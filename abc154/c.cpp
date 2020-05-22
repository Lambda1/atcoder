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
	ll n;
	std::cin >> n;

	std::map<ll,ll> a;
	for(ll i = 0;i < n;++i)
	{
		ll tmp;
		std::cin >> tmp;
		++a[tmp];
	}
	
	if(static_cast<ll>(a.size()) == n) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;

	return 0;
}
