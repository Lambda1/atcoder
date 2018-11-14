#include <iostream>

int main(int argc,char *argv[])
{
	int a,b;

	std::cin >> a >> b;
	
	std::cout << ((a*b)%2?"Odd":"Even") << std::endl;

	return 0;
}
