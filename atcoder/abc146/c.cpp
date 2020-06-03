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
}

int main(int argc,char *argv[])
{
	ul a,b,x;
	std::cin >> a >> b >> x;

	auto expr = [&](const ul& n){ return static_cast<ul>(a*n+b*lamlib::digit(n)); };

	ul left = 0, right = 1000000000;
	while(left <= right)
	{
		ul mid = (left + right)/2;
		auto tmp = expr(mid);
		if (x >= tmp) left = mid+1;
		else if(x < tmp) right = mid-1;
		
		if(left == 0 && right == 0) break;
	}

	auto ans = (left+right)/2;
	std::cout << ans << std::endl;

	return 0;
}
