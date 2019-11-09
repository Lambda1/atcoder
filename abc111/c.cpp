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

	std::vector<int> v(n);
	for(int i = 0;i < n;i++) std::cin >> v[i];

	int ee[2] = {},oo[2] = {1,1};
	std::map<int,int> ev,od;
	for(int i = 0;i < n;i+=2){
		if(ev.find(v[i]) == ev.end()) ev.insert(std::make_pair(v[i],1));
		else ev[v[i]]++;
		if(od.find(v[i+1]) == od.end()) od.insert(std::make_pair(v[i+1],1));
		else od[v[i+1]]++;

		if(ev.at(v[ee[0]]) <= ev.at(v[i])){
			if(v[ee[0]] != v[i]) ee[1] = ee[0];
			ee[0] = i;
		}
		if(od.at(v[oo[0]]) <= od.at(v[i+1])){
			if(v[oo[0]] != v[i+1]) oo[1] = oo[0];
			oo[0] = i+1;
		}
	}
	
	if(ev.size() == 1 && od.size() == 1 && v[ee[0]] == v[oo[0]]) std::cout << n/2 << std::endl;
	else if(v[ee[0]] == v[oo[0]]){
		int d1 = 0,d2 = 0;
		for(int i = 0;i < n;i+=2){
			if(v[ee[0]] != v[i]) d1++;
			if(v[oo[1]] != v[i+1]) d1++;
			
			if(v[ee[1]] != v[i]) d2++;
			if(v[oo[0]] != v[i+1]) d2++;
		}
		std::cout << ((d1 < d2)?d1:d2) << std::endl;
	}else{
		int d = 0;
		for(int i = 0;i < n;i+=2){
			if(v[ee[0]] != v[i]) d++;
			if(v[oo[0]] != v[i+1]) d++;
		}
		std::cout << d << std::endl;
	}
	return 0;
}
