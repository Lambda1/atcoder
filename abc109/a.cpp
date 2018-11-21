#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int a,b;
	std::cin >> a >> b;
	if(a%2 && b%2) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;

	return 0;
}
