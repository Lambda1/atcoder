#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;
using ul = unsigned long long int;

// GCD: a > b
ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }

int main(int argc,char *argv[])
{
	ll a,b,c,k;
	std::cin >> a >> b >> c >> k;

	if (k <= a) { std::cout << k << std::endl; }
	else if (k-(a+b) <= 0) { std::cout << a << std::endl; }
	else { std::cout << 2*a+b-k << std::endl; }

	return 0;
}
