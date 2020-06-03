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
	ll h,n;
	std::cin >> h >> n;
	
	ll tmp = h*n;
	if (h == 1 || n == 1) std::cout << 1 << std::endl;
	else if(!(tmp%2)) std::cout << tmp/2 << std::endl;
	else std::cout << tmp/2 + 1 << std::endl;

	return 0;
}
