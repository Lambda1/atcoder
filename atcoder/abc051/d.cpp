#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <utility>

using lint = long long int;

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
using Graph = std::vector<std::vector<edge<lint>>>;

	template<class T>
std::vector<T> dijkstra(const Graph &graph,const lint &start)
{
	const lint n = static_cast<lint>(graph.size());
	std::vector<T> dist(n, MAX_COST);
	dist[start] = 0;

	std::priority_queue<std::pair<T,lint>, std::vector<std::pair<T,lint>>,std::greater<std::pair<T,lint>>> pq;
	pq.push(std::make_pair(dist[start], start));

	while(!pq.empty())
	{
		T now_d = pq.top().first, now_v = pq.top().second;
		pq.pop();
		if(now_d > dist[now_v]) continue;
		for(lint i = 0;i < static_cast<lint>(graph[now_v].size());i++)
		{
			edge<lint> e = graph[now_v][i];
			if(dist[e.to] > dist[now_v] + e.dist)
			{
				dist[e.to] = dist[now_v] + e.dist;
				pq.push(std::make_pair(dist[e.to], e.to));
			}
		}
	}

	return dist;
}
lint cnt = 0;
	template<class T>
std::vector<T> dijkstra(const std::vector<T> &graph,const lint &n)
{
	std::vector<T> dist(n, MAX_COST);
	dist[0] = 0;

	std::priority_queue<std::pair<T,lint>, std::vector<std::pair<T,lint>>,std::greater<std::pair<T,lint>>> pq;
	pq.push(std::make_pair(dist[0], 0));

	while(!pq.empty())
	{
		T now_d = pq.top().first, now_v = pq.top().second;
		pq.pop();
		if(now_d > dist[now_v]) continue;
		for(lint i = 0;i < n;i++)
		{
			if(graph[now_v*n + i] == -1) continue;

			lint e = graph[now_v*n+i];
			if(dist[i] > dist[now_v] + e)
			{
				dist[i] = dist[now_v] + e;
				pq.push(std::make_pair(dist[i], i));
				cnt++;
			}
		}
	}

	return dist;
}

int main(int argc,char *argv[])
{
	lint n,m;
	std::cin >> n >> m;

	Graph graph(n);
	std::vector<lint> g(n*n,-1);
	for(lint i = 0;i < m;i++)
	{
		lint a,b,c;
		std::cin >> a >> b >> c;
		graph[a-1].push_back(edge<lint>(c, b-1));
		g[(a-1)*n+(b-1)] = g[(b-1)*n+(a-1)] = c;
	}

	//std::vector<lint> dist = dijkstra<lint>(graph,0);
	std::vector<lint> dist = dijkstra<lint>(g,n);
	
	std::cout << n-cnt << std::endl;

	for(int i = 0;i < n;i++)
		std::cout << dist[i] << " ";
	std::cout << std::endl;

	return 0;
}
