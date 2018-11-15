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
	
	int ans = 0;
	for(int i = 0;i < n;i++)
		if(i%2) ans -= v[i];
		else ans += v[i];

	std::cout << ans << std::endl;

	return 0;
}
