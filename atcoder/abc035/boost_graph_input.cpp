#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_utility.hpp>

using Graph = boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, boost::property<boost::edge_weight_t, int> >;
using Edge = std::pair<int,int>;

int main(int argc,char *argv[])
{
	long int n,m,t;
	std::cin >> n >> m >> t;

	std::string node_name = "";
	std::vector<int> money;
	for(int i = 0;i < n;i++)
	{
		int tmp;
		std::cin >> tmp;
		money.push_back(tmp);
		node_name += (static_cast<char>('a'+i));
	}

	Graph g;
	std::map<int,Graph::vertex_descriptor> desc;
	for(int i = 0;i < n;i++) desc[i] = add_vertex(g);

	for(int i = 0;i < m;i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		add_edge(desc[a-1],desc[b-1],c,g);
	}

	return 0;
}
