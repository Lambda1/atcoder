#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int N;
	std::cin >> N;

	if(!(N%2)) std::cout << static_cast<double>(1.0/2.0) << std::endl;
	else std::cout << (N-N/2)/static_cast<double>(N) << std::endl;

	return 0;
}
