#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	std::string s;
	std::cin >> s;

	int t1 = 0;
	for(int i = 0;i < s.length();i+=2) if('0' != s[i]) t1++;
	int t2 = 0;
	for(int i = 1;i < s.length();i+=2) if('1' != s[i]) t2++;
	int ans1 = t1+t2;
	t1 = t2 = 0;
	for(int i = 0;i < s.length();i+=2) if('1' != s[i]) t1++;
	for(int i = 1;i < s.length();i+=2) if('0' != s[i]) t2++;

	std::cout << ((ans1 < (t1+t2)) ? ans1 : t1+t2) << std::endl;

	return 0;
}
