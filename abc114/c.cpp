#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n;
	std::cin >> n;

	int cnt = 0;
	int a,b,c;
	for(int i = 357;i <= n;i+=2){
		std::string f = std::to_string(i);
		a = b = c = 0;
		for(int j = 0;j < f.length();j++){
			if(f[j] == '3') a++;
			else if(f[j] == '5') b++;
			else if(f[j] == '7') c++;
			else break;
			if(a+b+c == f.length() && a > 0 && b > 0 && c > 0) cnt++;
		}
	}

	std::cout << cnt << std::endl;

	return 0;
}
