#include <iostream>

int main(int argc,char *argv[])
{
	int a,b,c,x;
	int m,cnt = 0;

	std::cin >> a >> b >> c >> x;

	for(int i = 0;i <= a;i++)
		for(int j = 0;j <= b;j++){
			for(int k = 0;k <= c;k++){
				m = (500*i + 100*j + 50*k);
				if(m > x) break;
				if(m == x){
					cnt++;
					break;
				}
			}
		}

	std::cout << cnt << std::endl;

	return 0;
}
