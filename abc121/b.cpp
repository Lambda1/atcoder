#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

int main(int argc,char *argv[])
{
	int n,m,c;
	std::cin >> n >> m >> c;

	std::vector<int> b(m,0);
	for(int i = 0;i < m;++i) std::cin >> b[i];

	std::vector<int> a(n*m,0);
	for(int i = 0;i < n*m;++i) std::cin >> a[i];
	
	int ans = 0;
	for(int i = 0;i < n;++i)
	{
		int tmp = c;
		for(int j = 0;j < m;++j) tmp += b[j]*a[i*m+j];
		if(tmp > 0) ++ans;
	}

	std::cout << ans << std::endl;

	return 0;
}
