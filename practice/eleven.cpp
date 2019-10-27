#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

struct point
{
	int t,x,y;
};

int main(int argc,char *argv[])
{
	int N;
	std::cin >> N;

	struct point origin = {0,0,0};
	std::vector<struct point> pt(N);
	for(int i = 0;i < N;i++) std::cin >> pt[i].t >> pt[i].x >> pt[i].y;
	
	bool judgeA,judgeB,judgeC;
	for(int i = 0;i < N;i++){
		origin.t = abs(origin.t - pt[i].t);
		origin.x = abs(origin.x - pt[i].x);
		origin.y = abs(origin.y - pt[i].y);
		
		judgeA = ((origin.t)%2 && !((origin.x+origin.y)%2)); // even and odd
		judgeB = (!((origin.t)%2) && (origin.x+origin.y)%2); // odd and even
		judgeC = (origin.x+origin.y) > origin.t;
		if(judgeC || judgeA || judgeB){
			std::cout << "No" << std::endl;
			return 0;
		}
		origin = pt[i];
	}
	
	std::cout << "Yes" << std::endl;

	return 0;
}
