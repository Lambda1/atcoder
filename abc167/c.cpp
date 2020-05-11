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

	ll min = 9999999;
	for(ll i = 0;i < (1<<n);++i)
	{
		ll ans = 0;
		std::bitset<12> s(i);
		std::vector<ll> r(m,0);
		for (ll j = 0;j < n;++j)
		{
			if (s.test(j))
			{
				ans += c[j];
				bool flag = true;
				for (ll k = 0;k < m;++k)
				{
					r[k] += a[j*m+k];
					if (r[k] < x) { flag = false; }
				}
				if (flag) { if (ans < min) { min = ans; } }
			}
		}
	}

	if (min == 9999999) { std::cout << -1 << std::endl; }
	else { std::cout << min << std::endl; }

	return 0;
}
