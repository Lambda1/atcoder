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
	std::vector<bool> eratosthenes(const ul &n)
	{
		std::vector<bool> prime_candidate(n,true);
		prime_candidate[0] = prime_candidate[1] = false;
		const ul max_n = static_cast<ul>(std::sqrt(n));
		for(ul i = 2;i <= max_n;++i)
		{
			if(!prime_candidate[i]) continue;
			for(ul j = 2;i*j < n;++j)
			{
				prime_candidate[i*j] = false;
			}
		}
		return prime_candidate;
	}

	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

// std::cout << std::fixed << std::setprecision(15) << std::endl;

int main(int argc,char *argv[])
{
	ll n;
	std::cin >> n;

	for(ll i = 1e+5;i >= 0;--i)
	{
		if(n%(i*i) == 0)
		{
			std::cout << i << " " << n/(i*i) << std::endl;
			break;
		}
	}

	return 0;
}
