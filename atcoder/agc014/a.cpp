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
	ll a,b,c;
	std::cin >> a >> b >> c;
	
	if (a%2 == 0 && a == b && a==c){ std::cout << -1 << std::endl; return 0;}
	else if (a%2 != 0 || b%2 != 0 || c%2 != 0){ std::cout << 0 << std::endl; return 0;}

	ll ans = 0;
	while(true)
	{
		++ans;
		ll tmp_a = b/2 + c/2;
		ll tmp_b = a/2 + c/2;
		ll tmp_c = a/2 + b/2;
		a = tmp_a, b = tmp_b, c = tmp_c;
		if(tmp_a%2 != 0 || tmp_b%2 != 0 || tmp_c%2 != 0) break;
	}

	std::cout << ans << std::endl;

	return 0;
}
