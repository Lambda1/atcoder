#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int x1,y1,x2,y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	std::cout << x2-(y2-y1) << " " << y2+(x2-x1) << " ";
	std::cout << x1-(y2-y1) << " " << y1+(x2-x1) << std::endl;

	return 0;
}
