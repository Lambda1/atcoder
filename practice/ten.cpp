#include <iostream>
#include <string>
#include <vector>

std::string t[] = {"dream","dreamer","erase","eraser"};

bool recv(std::string ans,std::string m)
{
	if(ans.length() < m.length()) return false;
	if(ans == m) return true;
	if(recv(ans,m+t[0])) return true;
	if(recv(ans,m+t[1])) return true;
	if(recv(ans,m+t[2])) return true;
	if(recv(ans,m+t[3])) return true;
	return false;
}

int main(int argc,char *argv[])
{
	std::string s;
	std::cin >> s;
	int i;

	if(s[0] == 'd') i = 0;
	else i = 2;

	for(int j = 0;j < 2;j++)
	if(recv(s,t[i+j])){
			std::cout << "YES" << std::endl;
			return 0;
	}
	
	std::cout << "NO" << std::endl;
	return 0;
}
