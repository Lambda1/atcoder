#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>

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

	std::vector<int> x(n,0), y(n,0);
	for(int i = 0;i < n;++i) { std::cin >> x[i] >> y[i]; }

	double sum = 0.0;
	for(int i = 0;i < n;++i)
	{
		for(int j = 0;j < n;++j)
		{
			sum += std::sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
	}

	std::cout << std::setprecision(13) << sum/n << std::endl;

	return 0;
}
