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

	std::vector<int> v(n);
	for(int i = 0;i < n;i++) std::cin >> v[i];

	int max = 0;
	for(int i = 1;i < n;i++) if(v[max] < v[i]) max = i;

	int cnt = 0;
	for(int i = 0;i < n;i++) cnt += v[i];

	std::cout << cnt - v[max] + v[max]/2 << std::endl;

	return 0;
}
