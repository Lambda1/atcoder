#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int N,K;
	std::cin >> N >> K;
	
	int tmp, cnt = 0;
	for(int i = 0;i < N;i++)
	{
		std::cin >> tmp;
		if(tmp >= K) cnt++;
	}

	std::cout << cnt << std::endl;

	return 0;
}
