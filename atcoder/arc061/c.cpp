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
	ll s;
	std::cin >> s;

	std::string str(std::to_string(s));

	ll digit = lamlib::digit(s);
	constexpr ll max_d = 10;

	ul ans = 0;
	for(ll i = 0;i < (1<<(digit-1));++i)
	{
		std::bitset<max_d> bs(i);
		std::string eq;
		for(ll j = 0;j < digit;++j)
		{
			if(bs.test(j))
			{
				eq.push_back(str[j]);
				eq.push_back('+');
			}
			else { eq.push_back(str[j]); }
		}
		ll idx = 0;
		for(ll j = 1;j < eq.size();++j)
			if(eq[j] == '+')
			{
				std::string tmp;
				for(ll k = idx;k < j;++k) { tmp.push_back(eq[k]); }
				idx = j+1;
				ans += stoll(tmp);
			}
		if(idx != eq.size()){ ans += stoll(eq.substr(idx)); }
	}

	std::cout << ans << std::endl;

	return 0;
}
