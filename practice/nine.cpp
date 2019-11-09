#include <iostream>

int main(int argc,char *argv[])
{
	long long int n,y;
	std::cin >> n >> y;

	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n-i;j++)
			for(int k = 0;k <= n-i-j;k++)
				if((10000*k+5000*j+1000*i)==y){
					std::cout << i << " " << j << " " << k << std::endl;
					std::cout << k << " " << j << " " << i << std::endl;
					return 0;
				}
/*
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n-i;j++)
			if((10000*i+5000*j+1000*(n-i-j)) == y){
				std::cout << i << " " << j << " " << (n-i-j) << std::endl;
				return 0;
			}
*/
	std::cout << -1 << ' ' << -1 << ' ' << -1 << std::endl;

	return 0;
}
