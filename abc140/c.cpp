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
	
	std::vector<lint> b(n);
	for(int i = 1;i < n;i++) std::cin >> b[i];
	b[0] = b[1];

	lint ans = b[n-1];
	for(int i = 0;i < n-1;i++) ans += ((b[i] < b[i+1]) ? b[i] : b[i+1]);

	std::cout << ans << std::endl;

	return 0;
}
