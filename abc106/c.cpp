#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	std::string s,k;
	std::cin >> s >> k;

	int i;
	for(i = 0;i < s.size();i++) if(s[i] != '1') break;
	
	if(std::stol(k) <= i) std::cout << 1 << std::endl;
	else std::cout << s[i] << std::endl;

	return 0;
}
