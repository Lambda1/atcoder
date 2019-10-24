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
	const int mid = (max - min)/2 + min;

	if(min > max) return -1;

	if(data[mid] == key) return mid;
	if(data[mid] < key)  return my_binary_search<T>(mid+1,max,key,data);
	return my_binary_search<T>(min,mid-1,key,data);
}

int main(int argc,char *argv[])
{
	lint n;
	std::cin >> n;

	std::vector<lint> l(n);
	for(int i = 0;i < n;i++) std::cin >> l[i];
	std::sort(l.begin(),l.end(),std::greater<lint>());

	int num = 0;
	for(int a = 0;a < n;a++)
	{
		for(int b = a+1;b < n;b++)
		{
			for(int c = a+1;c < b;c++)
			{
				if(l[a] < l[b] + l[c] && l[b] < l[c]+l[a]) num++;
			}
		}
	}

	std::cout << num << std::endl;

	return 0;
}
