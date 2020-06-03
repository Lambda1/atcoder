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
	template<class T>
	inline T abs(const T &a){ return (a>0) ? a : -a; }
	// GCD: a > b
	ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }
}

int main(int argc,char *argv[])
{
	ll k,n;
	std::cin >> k >> n;

	std::vector<ll> a(n,0);
	for(ll i = 0;i < n;++i) { std::cin >> a[i]; }
	
	ll max = (a[0]+k)-a[n-1];
	for(ll i = 0;i < n-1;++i)
	{
		ll d = (a[i+1]-a[i]);
		if(d > max){ max = d; }
	}

	std::cout << k-max << std::endl;

	return 0;
}
