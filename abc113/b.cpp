#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main(int argc,char *argv[])
{
	int n,t,a;
	std::cin >> n >> t >> a;

	std::vector<int> h(n);
	for(int i = 0;i < n;i++) std::cin >> h[i];

	double min = fabs(t - h[0]*(6.0/1000) - a);
	int ans = 1;
	for(int i = 1;i < n;i++){
		if(fabs(t - h[i]*(6.0/1000) - a) < min){
			min = fabs(t - h[i]*(6.0/1000)-a);
			ans = i+1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
