#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n,x;
	std::cin >> n;
	n++;

	std::vector<int> v(n);
	for(int i = 0;i < n;i++) std::cin >> v[i];

	std::vector<int> way;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++) way.push_back(abs(v[i]-v[j]));

	for(int i = 0;i < way.size();i++)
	std::cout << way[i] << std::endl;

	return 0;
}
