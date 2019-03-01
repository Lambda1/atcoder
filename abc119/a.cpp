#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <sstream>

int main(int argc,char *argv[])
{
	std::string str;
	std::cin >> str;

	if(atoi(str.substr(0,4).c_str()) > 2018 && atoi(str.substr(5,7).c_str()) > 4)
		std::cout << "TBD" << std::endl;
	else std::cout << "Heisei" << std::endl;
	//if(atoi(str.substr(8,11).c_str()))

	return 0;
}
