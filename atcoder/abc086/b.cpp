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
	std::string a,b;
	std::cin >> a >> b;

	double num = std::sqrt(std::stoi(a+b));

	if(num == static_cast<int>(num)) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;

	return 0;
}
