#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long int;

int main(int argc, char *argv[])
{
	ll n,m;
	std::cin >> n >> m;

	std::vector<ll> h(n,0);
	std::vector<ll> s(n,0);
	for(ll i = 0;i < n;++i) { std::cin >> h[i]; }
	
	for(ll i = 0;i < m;++i)
	{
		ll a,b;
		std::cin >> a >> b;
		s[a-1] = std::max(s[a-1], h[b-1]);
		s[b-1] = std::max(s[b-1], h[a-1]);
	}

	int ans = 0;
	for (int i = 0;i < n;++i) { if (h[i] > s[i]) { ++ans; } }

	std::cout << ans << std::endl;

	return 0;
}
