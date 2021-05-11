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

// constant
constexpr ll type = 26;

ll solve(const std::vector<ll> &c, const std::vector<ll> &s, std::vector<ll> last, ll satisfaction, const ll &day, const ll &contest)
{
	satisfaction += s[day*type+contest];
	last[contest] = day+1;
	ll decline = 0;
	for(ll j = 0;j < type;++j) decline += c[j]*(last[contest]-last[j]);
	satisfaction -= decline;
	return satisfaction;
}

int main(int argc,char *argv[])
{
	// input
	ll d;
	std::cin >> d;
	std::vector<ll> c(type, 0);
	ll cs = 0;
	for(ll i = 0;i < type;++i){ std::cin >> c[i]; cs += c[i];}
	std::vector<ll> s(d*type, 0);
	for(ll i = 0;i < d*type;++i) std::cin >> s[i];
	
	std::cerr << "max: " << cs << std::endl;

	// output
	std::vector<ll> last(type,0);
	ll satisfaction = 0, score = 0;
	for(ll day = 0;day < d;++day)
	{
		ll index = 0;
		ll greed = solve(c,s,last,satisfaction,day,index);
		ll g_score = (1000000 + greed) > 0 ? (1000000 + greed) : 0;
		for(ll contest = 1;contest < type;++contest)
		{
			ll tmp = solve(c,s,last,satisfaction,day,contest);
			ll s_tmp = (1000000 + tmp) > 0 ? (1000000 + tmp) : 0;
			if(s_tmp > g_score)
			{
				greed = tmp;
				index = contest;
				g_score = s_tmp;
			}
		}
		greed = solve(c,s,last,satisfaction,day,index);
		satisfaction = greed;
		last[index] = day+1;
		score = g_score;
		std::cerr << day << "-day" << " " << "contest: " << index << " " << satisfaction << " " << score << std::endl;
		std::cout << index+1 << std::endl;
	}
	
	score = (1000000 + satisfaction) > 0 ? (1000000 + satisfaction) : 0;
	std::cerr << "satisfaction: " << satisfaction << std::endl;
	std::cerr << "score: "<< score << std::endl;

	return 0;
}
