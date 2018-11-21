#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n,s;
	std::cin >> n >> s;

	int d = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++){
				if(!((i+j)%s) && !((j+k)%s) && !((k+i)%s)){
					std::cout << i << " " << j << " " << k << std::endl;
					d++;
				}
			}

	std::cout << d << std::endl;

	return 0;
}
