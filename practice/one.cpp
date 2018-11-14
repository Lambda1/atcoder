#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
	int a,b,c;
	std::string str;

	//std::cin >> a;
	std::cin >> a >> b >> c;
	std::cin >> str;

	std::cout << a+b+c << ' ' << str << std::endl;

	return 0;
}
