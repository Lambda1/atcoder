#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int k;
	std::cin >> k;

	int d = 0,t = k;
	for(int i = 0;i < k;i++){
		d += (t/2);
		t--;
	}
	std::cout << d << std::endl;

	return 0;
}
