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

	int i;
	for(i = 9;i > 0;i--) if(n%i == 0) break;
	
	if(n/i < 10) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	
	return 0;
}
