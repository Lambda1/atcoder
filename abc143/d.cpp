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

	std::vector<lint> l(n);
	for(int i = 0;i < n;i++) std::cin >> l[i];

	lint num = 0;
	for(lint a = 0;a < n;a++)
	{
		for(lint b = a+1;b < n;b++)
		{
			for(lint c = b+1;c < n;c++)
			{
				if(l[a] < l[b]+l[c] && l[b] < l[c]+l[a] && l[c] < l[a]+l[b]) num++;
			}
		}
	}

	std::cout << num << std::endl;

	return 0;
}
