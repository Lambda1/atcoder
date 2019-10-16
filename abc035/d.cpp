#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>

constexpr int MAX_COST = 99999;

template<class T>
struct edge
{
	long long int to;
	T cost;
	edge() : to(0), cost(static_cast<T>(0)) {}
	edge(const long long int &n_v, const T &val) : to(n_v), cost(val) {}
	~edge() {}
};

	template<class T>
std::vector<T> dijkstra(std::vector<std::vector<edge<T>>> graph)
{
	std::vector<T> weight(static_cast<long long int>(graph.size()),MAX_COST);
	weight[0] = 0;

	std::priority_queue<std::pair<T,long long int>,std::vector<std::pair<T,long long int>>,std::greater<std::pair<T,long long int>>> pq;
	pq.push(std::make_pair(weight[0], 0));

	while(!pq.empty())
	{
		T cost = pq.top().first;
		long long int v = pq.top().second;
		pq.pop();
		if(weight[v] < cost) continue;
		for(long long int i = 0;i < static_cast<long long int>(graph[v].size());i++)
		{
			edge<T> now = graph[v][i];
			if(weight[now.to] > now.cost + weight[v])
			{
				weight[now.to] = now.cost + weight[v];
				pq.push(std::make_pair(weight[now.to], now.to));
			}
		}
	}

	return weight;
}

int main(int argc,char *argv[])
{
	long long int n,m,t;
	std::cin >> n >> m >> t;

	std::vector<long long int> weight(n);
	for(long long int i = 0;i < n;i++) std::cin >> weight[i];

	std::vector<std::vector<edge<long long int>>> array(n), back(n);
	for(long long int i = 0;i < m;i++)
	{
		long long int a,b,c;
		std::cin >> a >> b >> c;

		array[a-1].push_back(edge<long long int>(b-1, c));
		back[b-1].push_back(edge<long long int>(a-1, c));
	}

	std::vector<long long int> costA = dijkstra<long long int>(array);
	std::vector<long long int> costB = dijkstra<long long int>(back);

	long long int cost = 0;
	for(long long int i = 0;i < n;i++)
	{
		if(costA[i] >= MAX_COST || costB[i] >= MAX_COST) continue;
		long long int tmp = (t - costA[i] - costB[i]) * weight[i];
		cost = (cost < tmp) ? tmp : cost;
	}
	std::cout << cost << std::endl;

	return 0;
}
