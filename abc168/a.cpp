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

	ll ans = n%10;

	if(ans == 3) std::cout << "bon" << std::endl;
	else if(ans == 0||ans==1||ans==6||ans==8) std::cout << "pon" << std::endl;
	else std::cout << "hon" << std::endl;

	return 0;
}
