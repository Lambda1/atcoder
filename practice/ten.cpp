#include <iostream>
#include <string>
#include <algorithm>

void EraseAll(std::string *origin,std::string str)
{
	int pos;
	while((pos = origin->find(str)) != std::string::npos)
		origin->replace(pos,str.length(),"");
}

int main(int argc,char *argv[])
{
	std::string s;
	std::cin >> s;
	
	EraseAll(&s,"eraser");
	EraseAll(&s,"erase");
	EraseAll(&s,"dreamer");
	EraseAll(&s,"dream");

	if(s.length()) std::cout << "NO" << std::endl;
	else std::cout << "YES" << std::endl;
	
	return 0;
}
