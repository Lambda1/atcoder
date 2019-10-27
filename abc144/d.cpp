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
	int a,b,x;
	std::cin >> a >> b >> x;

	std::cout << a*a*b << std::endl;

	double rate = static_cast<double>(x)/(a*a*b);
	std::cout << rate << std::endl;

	return 0;
}
