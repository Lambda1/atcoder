#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int n,k;
	std::cin >> n >> k;

	std::vector<int> v(n);
	int *s = new int[n];
	s[0] = 0;
	for(int i = 0;i < n;i++){
		std::cin >> v[i];
		if(i > 0) s[i] = s[i-1] + abs(v[i-1] - v[i]);
	}

	int cost = s[(k-1)] - s[0] + abs(v[0]);
	for(int i = 0;i+(k-1) < n;i++){
		int f = s[i+(k-1)] - s[i] + abs(v[i]);
		if(cost > f) cost = f;
	}
	for(int i = n-1;i-(k-1) > -1;i--){
		int f = s[i] - s[i-(k-1)] + abs(v[i]);
		if(cost > f) cost = f;
	}
	std::cout << cost << std::endl;

	return 0;
}
