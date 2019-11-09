#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	for(int i = 1;i < 10;i++)
		if(n <= 111*i){
			std::cout << 111*i << std::endl;
			break;
		}

	return 0;
}
