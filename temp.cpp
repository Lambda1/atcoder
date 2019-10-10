#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

/* 辺 */
template <class T>
class Edge
{
	T m_to;     /* 行き先 */
	T m_weight; /* 重み */
	public:
	Edge() : m_to(0), m_weight(0){}
	Edge(const T to,const T weight) : m_to(to), m_weight(weight) {}
	~Edge(){}
	inline void Init(const T to,const T weight){ m_to = to, m_weight = weight; }
	inline T GetTo() const { return m_to; }
	inline T GetWeight() const { return m_weight; }
};
/* グラフ */
using Graph = std::vector<std::vector<Edge<int>>>;

int main(int argc,char *argv[])
{
	return 0;
}
