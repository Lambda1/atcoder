#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	std::vector<int> x(n,0);
	for(int i = 0;i < n;++i) std::cin >> x[i];

	int min = 99999999;
	for(int i = 0;i < 100;++i)
	{
		int tmp = i+1;
		int ans = 0;
		for(int j = 0;j < n;++j) ans += (x[j]-tmp)*(x[j]-tmp);
		if (ans < min) min = ans;
	}

	std::cout << min << std::endl;

	return 0;
}
