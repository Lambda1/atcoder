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

int main(int argc,char *argv[])
{
	ul n;
	std::cin >> n;

	ul ans = 0;
	for (ul i = 1;i <= n;++i)
	{
		if (!(i%3) || !(i%5)) { continue; }
		ans += i;
	}

	std::cout << ans << std::endl;

	return 0;
}
