#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;

int main(int argc,char *argv[])
{
	ll n;
	std::cin >> n;

	while (n > 0)
	{
		if (n%10 == 7) { std::cout << "Yes" << std::endl; return 0; }
		n /= 10;
	}

	std::cout << "No" << std::endl;

	return 0;
}
