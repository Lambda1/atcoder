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
	int h,cx,cy;
	std::cin >> cx >> cy >> h;
	int s,n = 0;

	for(int i = 0;i <= 100;i++)
		for(int j = 0;j <= 100;j++)
			if((s = MAX(h - abs(cx - j) - abs(cy - i),0)) || true){
				std::cout << j << " " << i << " " << s << std::endl;
				n++;
			}
	return 0;
}
