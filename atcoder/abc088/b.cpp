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

	std::vector<ll> a(n,0);
	for(int i = 0;i < n;++i) std::cin >> a[i];

	std::sort(a.begin(), a.end(), std::greater<ll>());

	ll alice = 0, bob = 0;
	for(int i = 0;i < n;i+=2)
	{
		alice += a[i];
		if(i+1 < n) bob += a[i+1];
	}

	std::cout << alice - bob << std::endl;

	return 0;
}
