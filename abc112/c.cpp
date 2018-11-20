#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX(x,y) ((x < y)?y:x)

struct point
{
  int x,y,h;
};

int main(int argc,char *argv[])
{
  int n;
  std::cin >> n;

  std::vector<struct point> v(n);
  for(int i = 0;i < n;i++) std::cin >> v[i].x >> v[i].y >> v[i].h;

  std::vector<struct point> ans_c;

  int num;
  for(int i = 0;i <= 100;i++)
    for(int j = 0;j <= 100;j++){
      bool flg = true;
      for(int s = 0;s < n;s++)
        if(v[s].h) num = v[s].h + abs(v[s].x - j) + abs(v[s].y - i);
      for(int s = 0;s < n;s++)
        if(MAX(num-abs(v[s].x - j) - abs(v[s].y - i),0) != v[s].h) flg = false;
      if(flg){
        std::cout << j << " " << i << " " << num << std::endl;
        return 0;
      }
    }

  return 0;
}
