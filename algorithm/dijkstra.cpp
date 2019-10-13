#include <iostream>
#include <vector>

const int table[] =
{
	-1, 7, 3, -1, -1, -1,
	7,-1, 3,  8,  5, -1,
	3, 3,-1,  1,  4, -1,
	-1, 8, 1, -1,  1,  3,
	-1, 5, 4,  1, -1,  9,
	-1,-1,-1,  3,  9, -1
};

	template<class T>
inline void PrintGraph(T *Graph,const int &n,const int &m)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
			std::cout << Graph[i*n+j] << " ";
		std::cout << std::endl;
	}
}
	template<class T>
inline void PrintGraph(const T &Graph,const int &n,const int &m)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
			std::cout << Graph[i*n+j] << " ";
		std::cout << std::endl;
	}
}

int DFS(int *Graph,std::vector<bool> &seen,const int &i,const int &num)
{
	int total = 0;
	for(int j = i;j < num;j++)
	{
		if(Graph[i*num+j] == -1 || i == j || seen[i*num+j]) continue;
		seen[i*num+j] = seen[j*num+i] = true;
		total = Graph[i*num+j];
		PrintGraph<std::vector<bool>>(seen, num, num);
		std::cout << std::endl;
		int right = DFS(Graph,seen,j,num) + total;
		int left  = DFS(Graph,seen,j+1,num) + total;
		if(right < left) total = right;
		else total = left;
		std::cout << (char)('a' + i) << std::endl;
		std::cout << "R " << right << std::endl;
		std::cout << "L " << left << std::endl;
		break;
	}
	return total;
}

int main(int argc,char *argv[])
{
	int num;
	std::cout << "INPUT VERTEX: ";
	std::cin >> num;

	int *Graph = new int[num*num];

	std::vector<bool> seen(num*num);
	for(int i = 0;i < num*num;i++)
	{
		Graph[i] = table[i];
		seen[i] = false;
	}

	PrintGraph<int>(Graph,num,num);
	std::cout << DFS(Graph,seen,0,num) << std::endl;
	PrintGraph<std::vector<bool>>(seen, num, num);

	delete[] Graph;

	return 0;
}
