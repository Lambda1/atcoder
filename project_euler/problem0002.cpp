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
	constexpr double pi = std::acos(-1.0);

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

std::map<ul,ul> fib_map;
ll fibo(const ul &n)
{
	if(n == 0 || n == 1) { return 1; }

	if(fib_map.find(n-1) != fib_map.end())
	{
		if(fib_map.find(n-2) == fib_map.end()) fib_map[n-2] = fibo(n-2);
	}
	else
	{
		if(fib_map.find(n-2) != fib_map.end()) fib_map[n-1] = fibo(n-1);
		else
		{
			fib_map[n-1] = fibo(n-1);
			fib_map[n-2] = fibo(n-2);
		}
	}
	return fib_map[n-1] + fib_map[n-2];
}
ul fibonacci(const ul &n)
{
	fib_map[0] = fib_map[1] = 1;
	return fibo(n);
}

int main(int argc,char *argv[])
{
	// 34: 5,702,887
	ul max = 34;
	std::cout << fibonacci(max) << std::endl;

	ul ans = 0;
	for(auto itr = fib_map.begin();itr != fib_map.end();++itr)
	{
		if((itr->second)%2 == 0 && itr->second < 4000000)
		{
			std::cout << itr->first+1 << ": " << itr->second << std::endl;
			ans += (itr->second);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
