#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using ll = long long int;

int main(int argc,char *argv[])
{
	ll n;
	std::cin >> n;

	std::vector<std::string> s;
	for(ll i = 0;i < n;++i)
	{
		std::string str;
		std::cin >> str;
		s.emplace_back(str);
	}

	std::sort(s.begin(), s.end());
	
	ll ans = 1;
	ll idx = 0;
	for (ll i = 1;i < n;i++)
	{
		if (s[idx] != s[i])
		{
			idx = i;
			++ans;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
