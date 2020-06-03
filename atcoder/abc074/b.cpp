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

	ll k;
	std::cin >> k;

	std::vector<ll> x(n,0);
	for(int i = 0;i < n;++i) std::cin >> x[i];

	ll ans = 0;
	std::vector<ll> a_cost(n*n,0), b_cost(n*n,0);
	for(int i = 0;i < n;++i)
	{
		const ll nx = x[i];
		const ll ny = i+1;
		ll min_a = 99999999;
		ll min_b = 99999999;
		for(ll j = 0;j < n;++j)
		{
			const ll y = j+1;
			ll tmp_a = nx + abs(ny-y); // A-COST
			ll tmp_b = abs(nx-k) + abs(ny-y); // B-COST
			if(min_a > tmp_a) min_a = tmp_a;
			if(min_b > tmp_b) min_b = tmp_b;
		}
		ans += (min_a > min_b) ? min_b : min_a;
	}

	std::cout << ans * 2 << std::endl;

	return 0;
}
