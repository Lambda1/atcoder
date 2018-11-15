#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	std::vector<int> v(n);
	for(int i = 0;i < n;i++) std::cin >> v[i];
	std::sort(v.begin(),v.end(),std::greater<int>());
	v.erase(std::unique(v.begin(),v.end()),v.end());

	std::cout << v.size() << std::endl;

	return 0;
}
