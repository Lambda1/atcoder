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
	std::string abcd;
	std::cin >> abcd;

	constexpr int bit = 3;

	for(int i = 0;i < (1<<bit);++i)
	{
		std::bitset<bit> bs(i);
		std::string ans;
		ans.push_back(abcd[0]);
		int tmp = abcd[0]-'0';
		for(int j = 0;j < bit;++j)
		{
			if(bs.test(j))
			{
				tmp += (abcd[j+1]-'0');
				ans.push_back('+');
			}
			else
			{
				tmp -= (abcd[j+1]-'0');
				ans.push_back('-');
			}
			ans.push_back(abcd[j+1]);
		}
		if(tmp==7){ std::cout << ans << "=" << tmp << std::endl; break; }
	}

	return 0;
}
