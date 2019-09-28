#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

int main(int argc,char *argv[])
{
	int N;
	std::cin >> N;
	
	int tmp;
	int *person = new int[N+1];
	for(int i = 0;i < N;i++){
		std::cin >> tmp;
		person[tmp] = i+1;
	}

	for(int i = 1;i < N+1;i++) std::cout << person[i] << " ";
	std::cout << std::endl;

	delete[] person;
	return 0;
}
