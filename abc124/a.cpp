#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int a,b;
	std::cin >> a >> b;

	int t1 = a + a-1;
	int t2 = b + b-1;
	int t3 = a + b;

	if(t1 > t2){
		if(t1 > t3) std::cout << t1 << std::endl;
		else std::cout << t3 << std::endl;
	}else if(t2 > t3) std::cout << t2 << std::endl;
	else std::cout << t3 << std::endl;

	return 0;
}
