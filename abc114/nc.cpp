#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int check(std::string num,int n)
{
	if(std::stol(num) > n) return 0;
	int cnt = 0;
	cnt += check(num+"7",n);
	cnt += check(num+"5",n);
	cnt	+= check(num+"3",n);
	if((num.find("3") != std::string::npos) && (num.find("5") != std::string::npos) && (num.find("7") != std::string::npos)) cnt++;
	return cnt;
}

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	std::cout << check("3",n) + check("5",n) + check("7",n) << std::endl;

	return 0;
}
