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
	ll n,m;
	std::cin >> n >> m;
	
	ll a;
	for(ll i = 0;i < m;++i)
	{
		std::cin >> a;
		n -= a;
	}

	if (n < 0) { std::cout << "-1" << std::endl; }
	else { std::cout << n << std::endl; }

	return 0;
}
