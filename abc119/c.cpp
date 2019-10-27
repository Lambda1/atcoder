#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int n,a[3];
std::vector<int> l;

int ret(int index,int c_a,int c_b,int c_c)
{
	if(index == n) return 0;
	ret(index+1);
}

int main(int argc,char *argv[])
{
	std::cin >> n >> a[0] >> a[1] >> a[2];
	l.size(n);
	for(int i = 0;i < n;i++) std::cin >> l[i];

	return 0;
}
