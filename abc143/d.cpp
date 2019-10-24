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

template<class T>
T my_binary_search(const int &min,const int &max,const T &key,const std::vector<T> &data)
{
	const int mid = (max - min) >> 1;

	std::cout << mid << std::endl;

	if(data[mid] == key) return mid;
	if(data[mid] > key)  return my_binary_search<T>(min,mid,key,data);

	if(min == max) return -1;
	
	return -1;
}

int main(int argc,char *argv[])
{
	lint n;
	std::cin >> n;

	std::vector<lint> l(n);
	for(int i = 0;i < n;i++) std::cin >> l[i];
	//std::sort(l.begin(),l.end(),std::greater<lint>());
	std::sort(l.begin(),l.end());

	for(int i = 0;i < n;i++) std::cout << l[i] << std::endl;

	std::cout << my_binary_search<lint>(0,n,704,l) << std::endl;

	return 0;
}
