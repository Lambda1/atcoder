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

	std::string s;
	std::cin >> s;
	
	lint num = 1;
	char check = s[0];
	for(int i = 1;i < n;i++)
	{
		if(check != s[i]){
			check = s[i];
			num++;
		}
	}

	std::cout << num << std::endl;

	return 0;
}
