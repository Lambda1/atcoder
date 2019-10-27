#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int x;
	std::cin >> x;

	if(x == 7 || x == 5 || x == 3) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
	return 0;
}
