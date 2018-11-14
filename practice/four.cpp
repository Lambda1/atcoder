#include <iostream>
#include <vector>

int main(int argc,char *argv[])
{
	int n,m = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for(int i = 0;i < n;i++) std::cin >> a[i];

	bool loop = true;
	while(loop){
		for(int i = 0;i < a.size();i++)
			if(a[i]%2){
				loop = false;
				break;
			}
		if(!loop) break;
		for(int i = 0;i < a.size();i++) a[i] /= 2;
		m++;
	}

	std::cout << m << std::endl;

	return 0;
}
