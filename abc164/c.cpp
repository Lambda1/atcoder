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

		auto result = std::find(s.begin(), s.end(), str);
		if (result == s.end()) { s.emplace_back(str); }
	}

	std::cout << s.size() << std::endl;

	return 0;
}
