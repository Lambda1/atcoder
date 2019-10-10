#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	long n,k;
	std::cin >> n >> k;

	long d = 0,f = 0;
	for(int i = 1;i <= n;i++){
		if(!(i%k)) f++;
		if(!(k%2) && (i%k) == (k/2)) d++;
	}

	std::cout << d*d*d + f*f*f << std::endl;
/*
	int s = k;
	d = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++){
				if(!((i+j)%s) && !((j+k)%s) && !((k+i)%s)){
					std::cout << i << " " << j << " " << k << std::endl;
					d++;
				}
			}

	std::cout << d << std::endl;
*/
	return 0;
}
