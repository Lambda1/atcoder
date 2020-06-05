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

	std::vector<ul> a(n,0);
	for(ll i = 0;i < n;++i) std::cin >> a[i];

	std::sort(a.begin(),a.end(),std::less<>());
	if(a[0] == 0) { std::cout << 0 << std::endl; return 0; }

	constexpr ul x = 1000000000000000000;
	ul ans = 1;
	for(ll i = 0;i < n;++i)
	{
		if(a[i] <= x/ans) ans *= a[i];
		else
		{
			std::cout << -1 << std::endl;
			return 0;
		}
	}

	std::cout << ans << std::endl;
	
	return 0;
}
