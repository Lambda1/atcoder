#include <iostream>
#include <vector>
#include <list>
#include <queue>

template<class T>
struct edge
{
	int to;
	T cost;
	edge() : to(0), cost(static_cast<T>(0)) {}
	edge(const int &n_v, const T &val) : to(n_v), cost(val) {}
	~edge() {}
};

template<class T>
void Printer(const T *data,const int &n,const int &m)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++) std::cout << data[i*n+j] << " ";
		std::cout << std::endl;
	}
}
template<class T>
void Printer(const T *data,const int &n)
{
	for(int i = 0;i < n;i++) std::cout << data[i] << " ";
	std::cout << std::endl;
}

/* 隣接行列 */
template<class T>
std::vector<T> dijkstra(const std::vector<T> &graph,const int &n)
{
	constexpr int MAX_COST = 99999;
	constexpr int ERR_COST = -1;
	std::vector<T> weight;
	for(int i = 0;i < n;i++) weight.push_back(static_cast<T>(MAX_COST));
	weight[0] = 0;

	std::queue<int> que;
	que.push(0);

	while(!que.empty())
	{
		int index = que.front();
		que.pop();
		for(int i = 0;i < n;i++)
		{
			if(graph[index*n+i] == static_cast<T>(ERR_COST)) continue;
			T cost = weight[index] + graph[index*n+i];
			if(cost < weight[i])
			{
				weight[i] = cost;
				que.push(i);
			}
		}
	}

	return weight;
}

template<class T>
std::vector<int> dijkstra(std::vector<std::vector<edge<int>>> graph)
{
	const int n = graph.size();
	constexpr int MAX_COST = 99999;
	constexpr int ERR_COST = -1;
	std::vector<T> weight;
	for(int i = 0;i < n;i++) weight.push_back(static_cast<T>(MAX_COST));
	weight[0] = 0;

	std::queue<int> que;
	que.push(0);
	
	while(!que.empty())
	{
		int index = que.front();
		que.pop();
		for(int i = 0;i < static_cast<int>(graph[index].size());i++)
		{
			edge<T> now = graph[index][i];
			if(now.cost + weight[index] < weight[now.to])
			{
				weight[now.to] = now.cost + weight[index];
				que.push(now.to);
			}
		}
	}

	return weight;
}

int main(int argc,char *argv[])
{
	int n,m,t;
	std::cin >> n >> m >> t;

	int max = 0;
	std::vector<int> weight(n);
	for(int i = 0;i < n;i++)
	{
		std::cin >> weight[i];
		if(weight[max] < weight[i] && weight[i] != t) max = i;
	}

	/* 隣接行列ver */
	/*
	std::vector<int> array,reverse;
	for(int i = 0;i < n*n;i++) array.push_back(-1), reverse.push_back(-1);
	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		std::cin >> a >> b >> c;

		array[(a-1)*n+(b-1)] = c;
		reverse[(b-1)*n+(a-1)] = c;
	}
	std::cout << (t - (dijkstra<int>(array,n)[max] + dijkstra<int>(reverse,n)[max])) * weight[max] << std::endl;
	*/

	std::vector<std::vector<edge<int>>> array(n), back(n);
	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		std::cin >> a >> b >> c;
		
		array[a-1].push_back(edge<int>(b-1, c));
		back[b-1].push_back(edge<int>(a-1, c));
	}

	int cost = (t - (dijkstra<int>(array)[max] + dijkstra<int>(back)[max])) * weight[max];

	std::cout << cost << std::endl;

	return 0;
}
