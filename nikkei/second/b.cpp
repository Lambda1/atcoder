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

	std::vector<lint> d(n);
	for(lint i = 0;i < n;i++) std::cin >> d[i];
	std::sort(d.begin(),d.end());
	
	for(int i = 0;i < n;i++) std::cout << d[i] << std::endl;

	return 0;
}
