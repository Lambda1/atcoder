#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int d;
	std::cin >> d;

	if(d == 25) std::cout << "Christmas" << std::endl;
	if(d == 24) std::cout << "Christmas Eve" << std::endl;
	if(d == 23) std::cout << "Christmas Eve Eve" << std::endl;
	if(d == 22) std::cout << "Christmas Eve Eve Eve" << std::endl;
	
	return 0;
}
