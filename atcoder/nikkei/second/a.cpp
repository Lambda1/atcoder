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
	lint n;
	std::cin >> n;

	lint cnt = 0;
	lint left = 1, right = n-1;
	while(left < right)
	{
		if(left + right == n) cnt++;
		++left, --right;
	}

	std::cout << cnt << std::endl;

	return 0;
}
