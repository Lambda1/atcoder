#include <iostream>
#include <vector>

using ll = long long int;

int main(int argc, char *argv[])
{
	ll N, K;
	std::cin >> N >> K;
	std::vector<ll> A(N, 0);

	for (ll i = 0;i < K; ++i)
	{
		ll d;
		std::cin >> d;
		for (ll j = 0;j < d;++j)
		{
			ll idx = 0;
			std::cin >> idx;
			A[idx-1]++;
		}
	}

	ll idx = 0;
	for (ll i = 0;i < N;++i) if (A[i] == 0) { ++idx; }

	std::cout << idx << std::endl;

	return 0;
}
