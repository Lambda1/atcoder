#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <bitset>

using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	// Absolute
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	// GCD: a > b
	ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }
}

int main(int argc,char *argv[])
{
	ll n,m;
	std::cin >> n >> m;

	std::vector<ll> wa_ans(n,0);
	std::vector<bool> ac_ans(n,false);
	for(ll i = 0;i < m;++i)
	{
		ll p;
		std::string s;
		std::cin >> p >> s;
		if(s == "AC") ac_ans[p-1] = true;
		else if(!ac_ans[p-1]) ++wa_ans[p-1];
	}

	ll ac_cnt = 0, wa_cnt = 0;
	for(ll i = 0;i < n;++i)
	{
		if(ac_ans[i])
		{
			++ac_cnt;
			wa_cnt += wa_ans[i];
		}
	}

	std::cout << ac_cnt << " " << wa_cnt << std::endl;

	return 0;
}
