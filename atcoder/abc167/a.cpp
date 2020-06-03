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
	std::string s,t;
	std::cin >> s;
	std::cin >> t;

	if (s == t.erase(t.size()-1)) { std::cout << "Yes" << std::endl; }
	else { std::cout << "No" << std::endl; }

	return 0;
}
