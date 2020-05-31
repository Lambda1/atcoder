#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <limits>

using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	// EPSITON
	constexpr double epsilon = std::numeric_limits<double>::epsilon();
	// Absolute
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	// Digit
	ul inline digit(const ul &num){ return static_cast<ul>(std::log10(num+epsilon))+1; }
	// GCD: a > b
	ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }

	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

int main(int argc,char *argv[])
{
	constexpr ul m = 2019;
	auto expr = [&](const ul &l,const ul&r){ return ((l%m)*(r%m))%m; };

	ul l,r;
	std::cin >> l >> r;

	ul ans = 0;
	if(r - l < 2019)
	{
		ans = 2018;
		for(ul a = l;a < r;++a)
			for(ul b = r;b > l;--b)
			{
				auto tmp = expr(a,b);
				if (ans > tmp) ans = tmp;
			}
	}
	std::cout << ans << std::endl;

	return 0;
}
