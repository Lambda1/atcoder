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
	int n;
	std::cin >> n;

	ll ans = 0;
	ll ans_num = 1;
	for(int i = 2;i <= n;i+=2)
	{
		ll tmp = 0;
		for(int j = i;j > 1;j/=2)
		{
			if(j%2 != 0) break;
			++tmp;
		}
		if(tmp > ans) ans = tmp, ans_num = i;
	}

	std::cout << ans_num << std::endl;

	return 0;
}
