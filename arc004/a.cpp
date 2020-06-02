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
	int n;
	std::cin >> n;

	std::vector<int> x(n,0), y(n,0);
	for(int i = 0;i < n;++i) std::cin >> x[i] >> y[i];


	auto expr = [](const ld &x1, const ld &y1,const ld &x2, const ld &y2){ return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); };

	ld ans = 0;
	for(int i = 0;i < n;++i)
	{
		for(int j = i+1;j < n;++j)
		{
			auto tmp = expr(static_cast<ld>(x[i]),static_cast<ld>(y[i]),static_cast<ld>(x[j]),static_cast<ld>(y[j]));
			if (tmp > ans) ans = tmp;
		}
	}

	std::cout << std::fixed << std::setprecision(15) << ans << std::endl;

	return 0;
}
