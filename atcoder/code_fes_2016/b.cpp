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
	ll n,a,b;
	std::string s;

	std::cin >> n >> a >> b;
	std::cin >> s;
	
	ll ja = 0, ab = 0;
	for(ll i = 0;i < n;++i)
	{
		if(s[i] == 'a')
			if(ja+ab < a+b)
			{
				++ja;
				std::cout << "Yes" << std::endl;
			}
			else std::cout << "No" << std::endl;
		else if(s[i] == 'b')
			if(ja+ab < a+b && ab < b)
			{
				++ab;
				std::cout << "Yes" << std::endl;
			}
			else std::cout << "No" << std::endl;
		else std::cout << "No" << std::endl;
	}

	return 0;
}
