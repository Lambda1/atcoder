#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using lint = long long int;
using Graph = std::vector<std::vector<lint>>;

int main(int argc,char *argv[])
{
	int a,b;
	std::cin >> a >> b;

	if(a < 1 || a > 9 || b < 1 || b > 9) std::cout << -1 << std::endl;
	else std::cout << a*b << std::endl;

	return 0;
}
