#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

template <class T>
class Edge
{
	T m_to;
	T m_weight;
	public:
	Edge() : m_to(0), m_weight(0){}
	Edge(const T to,const T weight) : m_to(to), m_weight(weight) {}
	~Edge(){}
	inline void Init(const T to,const T weight){ m_to = to, m_weight = weight; }
	inline T GetTo() const { return m_to; }
	inline T GetWeight() const { return m_weight; }
};
using Graph = std::vector<std::vector<Edge<int>>>;

int main(int argc,char *argv[])
{
	int n,m,t;
	std::cin >> n >> m >> t;

	std::vector<int> money;
	for(int i = 0;i < n;i++)
	{
		int tmp;
		std::cin >> tmp;
		money.push_back(tmp);
	}

	Graph g(n);
	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		std::cin >> a >> b >> c;
		g[a-1].push_back(Edge<int>(b,c));
	}

	for(int i = 0;i < n;i++)
	{
		std::cout << i << " -->";
		for(auto first = g[i].begin();first != g[i].end();first++)
		{
			std::cout << " " << first->GetTo();
		}
		std::cout << std::endl;
	}

	return 0;
}
