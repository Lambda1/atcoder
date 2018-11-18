#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <ios>
#include <iomanip>
#include <cstdlib>

int main(int argc,char *argv[])
{
	int n,m;
	std::cin >> n >> m;
	
	std::map <int,int> mp,ans;
	std::vector<int> y(m);
	int p;
	for(int i = 0;i < m;i++){
		std::cin >> p >> y[i];
		mp.insert(std::make_pair(y[i],p));
	}
	std::vector<int> cp = y;
	std::sort(y.begin(),y.end());
	
	int n_ans[n] = {};
	for(int i = 0;i < m;i++)
		ans.insert(std::make_pair(y[i],++n_ans[mp.at(y[i])-1]));

	for(int i = 0;i < m;i++){
		std::cout << std::setfill('0') << std::right << std::setw(6) << mp.at(cp[i]);
		std::cout << std::setfill('0') << std::right << std::setw(6) << ans.at(cp[i]) << std::endl;
	}
	
	return 0;
}
