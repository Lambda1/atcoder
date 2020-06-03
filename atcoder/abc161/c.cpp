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

// ABS
template<class T>
inline T abs(const T &a){ return (a>0) ? a : -a; }
// GCD: a > b
ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }

int main(int argc,char *argv[])
{
	ll n,k;
	std::cin >> n >> k;
	
	ll tmp = abs<ll>(n%k);
	if (tmp > abs<ll>(tmp-k)) { tmp = abs<ll>(tmp-k); }
	
	std::cout << tmp << std::endl;

	return 0;
}
