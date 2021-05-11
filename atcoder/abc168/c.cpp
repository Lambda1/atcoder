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

#define ANS(false)

int main(int argc,char *argv[])
{
	ld a,b,h,m;
	std::cin >> a >> b >> h >> m;

	ld alpha = ((60.0*h + m)/720.0) * (2*std::acos(-1));
	ld beta = (m/60.0) * (2*std::acos(-1));
#if ANS
	ld rad = alpha - beta;
	ld ans = std::sqrt((a*a+b*b) - 2.0*a*b*std::cos(rad));
#else
	ld x_a = a*std::cos(alpha);
	ld y_a = a*std::sin(alpha);
	ld x_b = b*std::cos(beta);
	ld y_b = b*std::sin(beta);
	ld ans = std::sqrt((x_a-x_b)*(x_a-x_b) + (y_a-y_b)*(y_a-y_b));
#endif
	
	std::cout << std::fixed << std::setprecision(15) << ans << std::endl;

	return 0;
}
