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
	ul gcd(const ul &a,const ul &b) { return (!b) ? a : gcd(b,a%b); } // NOTE: a > b

	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

// std::cout << std::fixed << std::setprecision(15) << std::endl;

std::vector<bool> eratosthenes(const ul &n)
{
	std::vector<bool> prime_candidate(n,true);

	// 0,1は素数でない.
	prime_candidate[0] = prime_candidate[1] = false;

	// 約数と平方根の関係(sqrt(n))
	const ul max_n = static_cast<ul>(std::sqrt(n));
	for(ul i = 2;i < max_n;++i)
	{
		// 素数でない数の倍数は, 素数でない.
		if(!prime_candidate[i]) continue;
		for(ul j = 2;i*j < n;++j)
		{
			// iの倍数は素数でない.
			prime_candidate[i*j] = false;
		}
	}

	return prime_candidate;
}

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	// 事前に10個の素数を列挙.
	/*
	{
		constexpr int num = 100000000;
		auto prime = eratosthenes(num);
		int counter = 0;
		std::vector<ul> tmp;
		for(int i = 100001;counter < max_count;++i)
		{
			if(prime[i])
			{
				tmp.emplace_back(i);
				++counter;
			}
		}
		for(auto itr = tmp.begin();itr != tmp.end();++itr) std::cout << *itr << std::endl;
	}
	*/
	/*
	{
		// 合成数作成
		constexpr ul ans[max_count]={100003,100019,100043,100049,100057,100069,100103,100109,100129,100151};

		int counter = 0;
		std::vector<ul> tmp;
		for(int i = 0;i < max_count;++i)
			for(int j = i;j < max_count;++j) tmp.emplace_back(ans[i]*ans[j]);

		std::sort(tmp.begin(),tmp.end(),std::less<>());
		for(int i = 0;i < max_count;++i) std::cout << tmp[i] << std::endl;
	}
	*/

	// 10個の素敵な日
	constexpr int max_count = 10;
	constexpr ul true_ans[max_count] = {1,10000600009,10002200057,10003800361,10004600129,10005200147,10006000171,10006200817,10006800931,10007200207};
	std::cout << true_ans[n-1] << std::endl;

	return 0;
}
