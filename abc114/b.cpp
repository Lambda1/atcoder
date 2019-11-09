#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>

int main(int argc,char *argv[])
{
	std::string s;
	std::cin >> s;

	int f,c=999;
	for(int i = 0;i < s.size()-2;i++){
		f = std::atoi(s.substr(i,3).c_str());
		int tmp = abs(f-753);
		if(tmp < c) c = tmp;
	}

	std::cout << c << std::endl;

	return 0;
}
