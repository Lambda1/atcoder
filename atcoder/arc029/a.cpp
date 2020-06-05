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
	ll n;
	std::cin >> n;

	std::vector<ll> t(n,0);
	for(int i = 0;i < n;++i) std::cin >> t[i];

	constexpr int bit = 4;
	ll ans = 99999999;
	for(int i = 1;i < (1<<bit)-1;++i)
	{
		std::bitset<bit> bs(i);
		ll tmp_1 = 0, tmp_2 = 0;
		for(int j = 0;j < n;++j)
		{
			if(bs.test(j)) { tmp_2 += t[j]; }
			else { tmp_1 += t[j]; }
		}
		ll tmp = (tmp_1 > tmp_2) ? tmp_1 : tmp_2;
		if(ans > tmp) { ans = tmp; }
	}

	std::cout << ans << std::endl;

	return 0;
}
