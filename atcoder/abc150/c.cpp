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

	std::vector<ll> p(n,0);
	for(ll i = 0;i < n;++i) std::cin >> p[i];
	std::vector<ll> q(n,0);
	for(ll i = 0;i < n;++i) std::cin >> q[i];

	std::vector<ll> cp = q;

	std::sort(cp.begin(),cp.end(),std::less<>());

	ll cnt = 0;
	ll a = 0,b = 0;
	do
	{
		ll a_judge = 0, b_judge = 0;
		++cnt;
		for(ll i = 0;i < n;++i)
		{
			if(cp[i] == p[i]) ++a_judge;
			if(cp[i] == q[i]) ++b_judge;
		}
		if(a_judge == n) a = cnt;
		if(b_judge == n) b = cnt;
	}while(std::next_permutation(cp.begin(),cp.end()));

	std::cout << abs(a-b) << std::endl;

	return 0;
}
