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
	int n;
	std::cin >> n;
	
	ll tmp = n*(100.0/108.0);

	while(static_cast<int>(tmp*(108.0/100.0)) < n) ++tmp;
	
	if(static_cast<int>(tmp*(108.0/100.0)) == n) std::cout << tmp << std::endl;
	else std::cout << ":(" << std::endl;

	return 0;
}
