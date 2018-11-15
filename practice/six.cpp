#include <iostream>

int sum_digit(int n,int a,int b)
{
	int s = 0,cp = n;
	while(n > 0){
		s += n%10;
		n /= 10;
	}
	return ((s >= a)&&(s <= b))?cp:0;
}

int main(int argc,char *argv[])
{
	int n,a,b;
	int ans = 0;

	std::cin >> n >> a >> b;
	for(int i = 1;i <= n;i++) ans += sum_digit(i,a,b);

	std::cout << ans << std::endl;

	return 0;
}
