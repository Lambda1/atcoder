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

	bool flg = false;
	std::vector<std::string> w(n);
	for(int i = 0;i < n;i++){
	 	std::cin >> w[i];
		for(int j = 0;j < i && !flg;j++)
			if(w[i] == w[j]) flg = true;
	}

	for(int i = 1;i < n;i++)
		if(flg | w[i-1].at(w[i-1].length()-1) != w[i].at(0)){
			std::cout << "No" << std::endl;
			return 0;
		}

	std::cout << "Yes" << std::endl;

	return 0;
}
