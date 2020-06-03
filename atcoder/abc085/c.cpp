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

using ld = long double;
using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	/* constant */
	constexpr double epsilon = std::numeric_limits<double>::epsilon();

	/* math */
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	ul inline digit(const ul &num){ return static_cast<ul>(std::log10(num+epsilon))+1; }

	/* algorithm */
	ul gcd(const ul &a,const ul &b) { return (!b) ? a : gcd(b,a%b); } // NOTE: a > b

	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

// std::cout << std::fixed << std::setprecision(15) << std::endl;

int main(int argc,char *argv[])
{
	ll n,y;
	std::cin >> n >> y;

	auto expr = [&](const ll &x, const ll &y) { return n-(x+y); };

	ll ans_1 = 0, ans_2 = 0, ans_3 = 0;
	for(ll i = 0;i <= n;++i)
	{
		for(ll j = 0;j <= n;++j)
		{
			auto k = expr(i,j);
			auto money = i*10000 + j*5000 + k*1000;
			if(k >= 0 && money == y)
			{
				std::cout << i << " " << j << " " << k << std::endl;
				return 0;
			}
		}
	}

	std::cout << -1 << " " << -1 << " " << -1 << std::endl;

	return 0;
}
