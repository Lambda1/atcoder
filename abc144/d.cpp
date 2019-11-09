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
	int a,b,x;
	std::cin >> a >> b >> x;
	
	double v0 = a*a*b;

	constexpr double pi = std::acos(-1);
	
	double s = static_cast<double>(x)/a;

	if(s >= a*b/2.0) std::cout << std::setprecision(10) << std::atan((2*(v0-x))/(a*a*a))*180/pi << std::endl;
	else std::cout << std::setprecision(10) << atan2(b,2*s/b)*180/pi  << std::endl;

	return 0;
}
