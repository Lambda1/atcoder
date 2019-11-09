#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main(int argc,char *argv[])
{
	std::string num;
	std::cin >> num;
	
	std::replace(num.begin(),num.end(),'1','8'), std::replace(num.begin(),num.end(),'9','7'), std::replace(num.begin(),num.end(),'8','9'), std::replace(num.begin(),num.end(),'7','1');

	std::cout << num << std::endl;
	
	return 0;
}
