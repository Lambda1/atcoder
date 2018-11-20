#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX(x,y) ((x < y)?y:x)

struct point
{
	int x,y,h;
};

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	std::vector<struct point> v(n);
	for(int i = 0;i < n;i++) std::cin >> v[i].x >> v[i].y >> v[i].h;

	std::vector<int> num(n);
	int all;

	for(int i = 0;i <= 100;i++)
		for(int j = 0;j <= 100;j++){
			all = 0;
			for(int s = 0;s < n;s++){
			 num[s] = v[s].h + abs(v[s].x - j) + abs(v[s].y - i);
			 all += num[s];
			}
			if(all == num[0]*n){
				std::cout << j << " " << i << " " << num[0] << std::endl;
		 		return 0;
			}
		}

	return 0;
}
