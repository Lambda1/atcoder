#include <iostream>
#include <vector>

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

/* 隣接行列(最深部がゴールver) */
template<class T>
std::vector<T> dijkstra(const std::vector<T> &graph,const int &n)
{
	constexpr int MAX_COST = 99999;
	constexpr int ERR_COST = -1;
	std::vector<T> weight;
	for(int i = 0;i < n;i++) weight.push_back(static_cast<T>(MAX_COST));
	weight[0] = 0;

	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(graph[i*n+j] == static_cast<T>(ERR_COST)) continue;
			
			if((weight[i] + graph[i*n+j]) < weight[j])
			{
				weight[j] = weight[i] + graph[i*n+j];
				if(j < i){ i = j-1; break; }
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
		if(weight[max] < weight[i]) max = i;
	}

	std::vector<int> array,reverse;
	for(int i = 0;i < n*n;i++) array.push_back(-1), reverse.push_back(-1);

	for(int i = 0;i < m;i++)
	{
		int a,b,c;
		std::cin >> a >> b >> c;

		array[(a-1)*n+(b-1)] = c;
		reverse[(b-1)*n+(a-1)] = c;
	}

	//Printer<int>(dijkstra<int>(array,n).data(),n);
	Printer<int>(dijkstra<int>(reverse,n).data(),n);
	/*
	std::vector<int> data_x =
	{
		-1, 10,  5, -1, -1, -1,
		10, -1,  2,  8, -1, -1,
		 5,  2, -1, -1, 10, -1,
		-1,  8, -1, -1, -1,  8,
		-1, -1, 10, -1, -1, 10,
		-1, -1, -1,  8, 10, -1
	};
	Printer<int>(dijkstra<int>(data_x,6).data(),6);
	*/
	return 0;
}
