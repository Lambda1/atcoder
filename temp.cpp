#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/graph_utility.hpp>

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS> Graph;
typedef std::pair<int,int> Edge;

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
	const std::vector<Edge> edges =
	{
		{static_cast<int>(NODE::A), static_cast<int>(NODE::B)}, {static_cast<int>(NODE::A), static_cast<int>(NODE::C)}, {static_cast<int>(NODE::A), static_cast<int>(NODE::D)}
	};
	const Graph g(edges.begin(), edges.end(), static_cast<int>(NODE::SIZE));

	boost::print_graph(g, node_name.c_str());

	return 0;
}
