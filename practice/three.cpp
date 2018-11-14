#include <iostream>
#include <string>

int main(int argc,char *argv[])
{
	int n = 0;
	std::string str;

	std::cin >> str;
	for(int i = 0;i < str.length();i++) if(str[i] == '1') n++;
	std::cout << n << std::endl;

	return 0;
}
