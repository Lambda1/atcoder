#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
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
	std::string s;
	std::cin >> s;

	ul k;
	std::cin >> k;

	if(s.length() == 1)
	{
		std::cout << s.length()*(k/2) << std::endl;
		return 0;
	}
	else if(lamlib::same_char_count(s,s[0]) == s.length())
	{
		std::cout << s.length()*(k/2)+1 << std::endl;
		return 0;
	}

	std::string ss = (k!=1) ? s+s : s;

	for(ll i = 1;i < ss.length();++i)
		if(ss[i-1] == ss[i]) ss[i] = '@';
	
	ul ans_one = 0;
	for(ll i = 0;i < s.length();++i)
		if(ss[i] == '@') ++ans_one;
	ul ans_two = 0;
	for(ll i = s.length();i < ss.length();++i)
		if(ss[i] == '@') ++ans_two;

	if(s[0] != s[s.length()-1]) std::cout << ans_one * k << std::endl;
	else std::cout << ans_one+ans_two*(k-1) << std::endl;

	return 0;
}
