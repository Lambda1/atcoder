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

	std::vector<int> h(n);
	for(int i = 0;i < n;i++) std::cin >> h[i];

	int cnt = 1;
	for(int i = 1;i < n;i++){
		for(int j = 0;j < i;j++)
			if(h[j] > h[i]){ cnt--; break; }
		cnt++;
	}

	std::cout << cnt << std::endl;

	return 0;
}
