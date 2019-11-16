#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using lint = long long int;
using Graph = std::vector<std::vector<lint>>;

template<class T>
struct edge
{
	T dist;
	lint to;
	edge(){}
	edge(const T &a_dist,const lint &a_to) : dist(a_dist), to(a_to) {}
	~edge(){}
};

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	std::vector<char> a(n,0);
	for(int i = 0;i < n;++i) std::cin >> a[i];

	if(n%2 != 0)
	{
			std::cout << "No" << std::endl;
			return 0;
	}

	for(int i = 0;i < n/2;++i)
	{
		if(a[i] != a[i+n/2]) 
		{
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	std::cout << "Yes" << std::endl;

	return 0;
}
