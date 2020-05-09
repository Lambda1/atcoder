#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;

int main(int argc,char *argv[])
{
	ll n;
	std::cin >> n;

	std::vector<ll> a(n-1,0);
	for (int i = 0;i < n-1;++i) { std::cin >> a[i]; }

	std::sort(a.begin(), a.end());

	std::vector<ll> p(n-1,0);
	ll idx = 0;
	++p[a[idx]-1];
	for (int i = 1;i < n-1;++i)
	{
		if (a[idx] != a[i]) { idx = i; }
		++p[a[idx]-1];
	}

	for (int i = 0;i < n-1;++i) { std::cout << p[i] << std::endl; }
	std::cout << 0 << std::endl;

	return 0;
}
