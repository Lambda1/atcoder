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

	std::map<std::string,ll> s;
	for(ll i = 0;i < n;++i)
	{
		std::string tmp;
		std::cin >> tmp;
		s[tmp]++;
	}

	ll max = 0;
	for(auto itr = s.begin();itr != s.end();++itr)
		if(max < itr->second) max = itr->second;

	for(auto itr = s.begin();itr != s.end();++itr)
		if(max == itr->second) std::cout << itr->first << std::endl;


	return 0;
}
