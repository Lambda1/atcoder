#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;
	
	long double money,all = 0;
	std::string str;
	for(int i = 0;i < n;i++){
		std::cin >> money;
		std::cin >> str;
		if(str == "JPY") all += money;
		else all += money*380000.0;
	}

	std::cout << all << std::endl;

	return 0;
}
