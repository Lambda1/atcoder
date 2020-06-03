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

	lint i;
	for(i = sqrt(n);i > 0;i--) if(n%i == 0) break;

	lint j = n/i;
	std::cout << i-1 + j-1 << std::endl;
	return 0;
}
