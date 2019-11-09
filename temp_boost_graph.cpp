#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_utility.hpp>

using Graph = boost::adjacency_list<boost::listS, boost::vecS, boost::directedS>;
using Edge = std::pair<int,int>;

enum class NODE : int
{
	A,
	B,
	C,
	D,
	E,
	SIZE
};

const std::string node_name = "ABCDE";

int main(int argc,char *argv[])
{
	Graph g;

	std::map<int, Graph::vertex_descriptor> desc;
	for(int i = 0;i < static_cast<int>(NODE::SIZE);i++)
	{
		desc[i] = boost::add_vertex(g);
	}
	
	boost::add_edge(desc[static_cast<int>(NODE::A)], desc[static_cast<int>(NODE::B)], g);

	boost::print_graph(g, node_name.c_str());

	return 0;
}
