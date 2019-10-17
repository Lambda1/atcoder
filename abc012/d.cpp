#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using lint = long long int;
using Graph = std::vector<std::vector<lint>>;

constexpr lint MAX_COST = 999999;

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
void warshall_floyd(std::vector<T> &graph)
{
	int n = static_cast<int>(std::sqrt(graph.size()));

	for(int k = 0;k < n;k++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				graph[i*n+j] = (graph[i*n+j] > graph[i*n+k] + graph[k*n+j]) ? (graph[i*n+k]+graph[k*n+j]) : graph[i*n+j];
}

int main(int argc,char *argv[])
{
	lint n,m;
	std::cin >> n >> m;

	std::vector<lint> graph(n*n, MAX_COST);
	for(int i = 0;i < n;i++) graph[i*n+i] = 0;
	for(int i = 0;i < m;i++)
	{
		lint a, b, t;
		std::cin >> a >> b >> t;
		graph[(b-1)*n + (a-1)] = graph[(a-1)*n + (b-1)] = t;
	}

	warshall_floyd<lint>(graph);
	lint true_max = MAX_COST;
	for(int i = 0;i < n;i++)
	{
		lint max = 0;
		for(int j = 0;j < n;j++)
			max = (max < graph[i*n+j]) ? graph[i*n+j] : max;
		true_max = true_max < max ? true_max : max;
	}

	std::cout << true_max << std::endl;

	return 0;
}
