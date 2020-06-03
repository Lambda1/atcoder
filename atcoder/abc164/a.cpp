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
	ll s,w;
	std::cin >> s >> w;

	if (w >= s) { std::cout << "unsafe" << std::endl; }
	else { std::cout << "safe" << std::endl; }

	return 0;
}
