#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_utility.hpp>

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, boost::no_property, boost::property<boost::edge_weight_t,int>> Graph;
typedef std::pair<int,int> Edge;

int main(int argc,char *argv[])
{
	long int n,m,t;
	std::cin >> n >> m >> t;

	std::vector<int> money;
	for(int i = 0;i < n;i++)
	{
		int tmp;
		std::cin >> tmp;
		money.push_back(tmp);
	}
	
	std::string node_name = "";
	std::vector<Edge> edges;
	std::vector<int> weights;
	for(int i = 0;i < m;i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		edges.push_back(std::make_pair(a, b));
		weights.push_back(c);
		node_name += std::to_string(i+1);
	}
	
	Graph g(edges.begin(), edges.end(), weights.begin(), n);
	boost::print_graph(g, node_name.c_str());

	return 0;
}
