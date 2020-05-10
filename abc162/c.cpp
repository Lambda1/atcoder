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
	ul k;
	std::cin >> k;
	
	ul ans = 0;
	for (ul a = 1;a <= k;++a){ for (ul b = 1;b <= k;++b) { for (ul c = 1;c <= k;++c) { ans += gcd(gcd(a,b),c); } } }

	std::cout << ans << std::endl;

	return 0;
}
