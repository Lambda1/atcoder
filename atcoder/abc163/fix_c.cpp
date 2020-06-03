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
	for (int i = 0;i < n-1;++i)
	{
		ll tmp;
		std::cin >> tmp;
		++a[tmp-1];
	}

	for (int i = 0;i < n-1;++i) { std::cout << a[i] << std::endl; }
	std::cout << 0 << std::endl;

	return 0;
}
