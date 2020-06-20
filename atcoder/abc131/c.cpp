#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <limits>
#include <numeric>

using ld = long double;
using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	/* constant */
	constexpr double epsilon = std::numeric_limits<double>::epsilon();

	/* math */
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	ul inline digit(const ul &num){ return static_cast<ul>(std::log10(num+epsilon))+1; }

	/* algorithm */
	ul gcd(const ul &a,const ul &b) { return (!b) ? a : gcd(b,a%b); }
	ul lcm(const ul &a,const ul &b) { return (a/gcd(a,b))*b; } // a/gcd(a,b)*b <=> (a*b)/gcd(a,b)
	std::vector<bool> eratosthenes(const ul &n)
	{
		std::vector<bool> prime_candidate(n,true);
		prime_candidate[0] = prime_candidate[1] = false;
		for(ul i = 2;i*i < n;++i)
		{
			if(!prime_candidate[i]) continue;
			for(ul j = 2;i*j < n;++j) prime_candidate[i*j] = false;
		}
		return prime_candidate;
	}
	ll rho_method(const ll &n)
	{
		auto f = [&](const ll &xi){ return (xi*xi+1)%n; };
		ll x = 2, y = 2, d = 1;
		while(d == 1)
		{
			x = f(x);
			y = f(f(y));
			d = lamlib::gcd(lamlib::abs(x-y),n);
		}
		return d;
	}
	// 素因数分解(試し割)
	std::vector<ll> prime_factorization_trial(const ll &n)
	{
		ll num = n;
		std::vector<ll> prime;
		for(ll i = 2;i*i <= n;++i)
		{
			while((num%i) == 0)
			{
				prime.emplace_back(i);
				num /= i;
			}
		}
		if(num > 1) prime.emplace_back(num);
		return prime;
	}

	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

// std::cout << std::fixed << std::setprecision(15) << std::endl;

int main(int argc,char *argv[])
{
	ll a,b,c,d;
	std::cin >> a >> b >> c >> d;
	
	const ll lcm = lamlib::lcm(c,d);
	
	const ll n1 = b/c;
	const ll n2 = b/d;
	const ll n3 = b/lcm;
	const ll tmp1 = n1 + n2 - n3;
	std::cerr << n1 << " " << n2 << " " << n3 << std::endl;

	const ll m1 = (a-1)/c;
	const ll m2 = (a-1)/d;
	const ll m3 = (a-1)/lcm;
	const ll tmp2 = m1 + m2 - m3;
	std::cerr << m1 << " " << m2 << " " << m3 << std::endl;

	std::cerr << tmp1 << " " << tmp2 << std::endl;

	const ll ans = (b-a+1) - (tmp1 - tmp2);
	std::cout << ans << std::endl;
	
	return 0;
}
