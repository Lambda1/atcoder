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
	ll n;
	std::cin >> n;

	std::vector<std::string> s;
	for(ll i = 0;i < n;++i)
	{
		std::string tmp;
		std::cin >> tmp;
		s.emplace_back(tmp);
	}

	std::sort(s.begin(),s.end());

	ll ans = 0;
	for(ll i = 0;i < n;++i)
	{
		ll ans_tmp = 0;
		std::string str = s[i];
		for(ll j = i+1;j < n;++j)
		{
			if(str != s[j]) break;
			++ans_tmp;
		}
		if(ans_tmp > ans) ans = ans_tmp;
	}
	for(ll i = 0;i < n;++i)
	{
		ll count = 0;
		std::string str = s[i];
		for(ll j = i+1;j < n;++j)
		{
			if(str != s[j]) break;
			++count;
		}
		if(count == ans) std::cout << str << std::endl;
	}

	return 0;
}
