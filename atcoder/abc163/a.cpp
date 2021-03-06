#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;

constexpr double pi = 3.1415926535;

int main(int argc,char *argv[])
{
	double r;
	std::cin >> r;

	std::cout << std::fixed << std::setprecision(15) << 2.0 * pi * r << std::endl;

	return 0;
}
