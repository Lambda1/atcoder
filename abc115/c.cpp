#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n,k;
	std::cin >> n >> k;

	std::vector<int> h(n);
	for(int i = 0;i < n;i++) std::cin >> h[i];
	std::sort(h.begin(),h.end());

	int min = abs(h[0] - h[k-1]);
	for(int i = 0;(i+k-1) < n;i++){
		if(min > abs(h[i] - h[i+k-1])) min = abs(h[i]-h[i+k-1]);
	}
	std::cout << min << std::endl;

	return 0;
}
