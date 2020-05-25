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
	ll n,k;
	std::cin >> n >> k;

	std::vector<ll> h(n,0);
	for(ll i = 0;i < n;++i) std::cin >> h[i];

	std::sort(h.begin(), h.end(), std::less<>());

	ll ans = 0;
	for(ll i = 0;i < n-k;++i) ans += h[i];

	std::cout << ans << std::endl;

	return 0;
}
