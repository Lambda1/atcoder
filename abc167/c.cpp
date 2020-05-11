#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;
using ul = unsigned long long int;

// GCD: a > b
ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }

int main(int argc,char *argv[])
{
	ll n,m,x;
	std::cin >> n >> m >> x;

	std::vector<ll> c(n,0), a(n*m,0);
	for(ll i = 0;i < n;++i)
	{
		std::cin >> c[i];
		for (ll j = 0;j < m;++j) { std::cin >> a[i*m+j]; }
	}

	ll ans = 99999999;
	for(ll i = 0;i < n;++i)
	{
		std::vector<ll> r(m,0);
		for(ll j = 0;j < m;++j)
		{
			std::cout << a[i*m+j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
