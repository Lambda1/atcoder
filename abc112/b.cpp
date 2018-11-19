#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main(int argc,char *argv[])
{
	int n,T;
	std::cin >> n >> T;

	std::vector<int> c(n),t(n);
	for(int i = 0;i < n;i++) std::cin >> c[i] >> t[i];

	int min = 0;
	for(int i = 1;i < n;i++) if(c[i] < c[min] && t[i] <= T) min = i;

	if(t[min] <= T)
		std::cout << c[min] << std::endl;
	else std::cout << "TLE" << std::endl;
	
	return 0;
}
