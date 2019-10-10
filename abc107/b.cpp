#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int h,w;
	std::cin >> h >> w;

	std::vector<char> a(h*w);
	for(int i = 0;i < h*w;i++) std::cin >> a[i];

	int cnt_w = 0,cnt_h = 0;
	for(int i = 0;i < h;i++){
		bool flag = false;
		for(int j = 0;j < w;j++) if(a[i*w+j] == '#'){ flag = true; break; }
		if(!flag){ cnt_h++; for(int j = 0;j < w;j++) a[i*w+j] = '7'; }
	}
	for(int i = 0;i < w;i++){
		bool flag = false;
		for(int j = 0;j < h;j++) if(a[j*w+i] == '#'){ flag = true; break; }
		if(!flag){ cnt_w++; for(int j = 0;j < h;j++) a[j*w+i] = '7'; }
	}
	for(int i = 0;i < a.size();i++) if(a[i] == '7') a.erase(a.begin()+i--);
	
	for(int i = 0;i < h-cnt_h;i++){
		for(int j = 0;j < w-cnt_w;j++) std::cout << a[i*(w-cnt_w)+j];
		std::cout << std::endl;
	}
	return 0;
}
