#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	std::vector<int> tmp(5);
	int k;

	for(int i = 0;i < 5;i++) std::cin >> tmp[i];
	std::cin >> k;
	std::sort(tmp.begin(),tmp.end());
	std::cout << (abs(tmp[0]-tmp[4])>k?":(":"Yay!") << std::endl;

	return 0;
}
