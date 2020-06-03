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
	int a,b;
	std::cin >> a >> b;

	int ans = 0;
	int len = 1;
	while(len < b)
	{
		--len;
		len += a;
		++ans;
	}

	std::cout << ans << std::endl;

	return 0;
}
