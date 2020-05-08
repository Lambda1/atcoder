#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;

int main(int argc,char *argv[])
{
	ll a,b,c,d;
	std::cin >> a >> b >> c >> d;

	while (true)
	{
		c -= b;
		if (c <= 0) {  std::cout << "Yes" << std::endl; break; }
		a -= d;
		if (a <= 0) {  std::cout << "No" << std::endl; break; }
	}

	return 0;
}
