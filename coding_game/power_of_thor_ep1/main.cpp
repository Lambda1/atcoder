#include <iostream>
#include <cmath>
#include <string>

int main(int argc,char *argv[])
{
	constexpr int max_w = 40;
	constexpr int max_h = 18;

	float tx, ty;
	float vx, vy;
	std::cin >> tx >> ty >> vx >> vy;
	std::cin.ignore();
	
	std::cerr << vx << " " << vy << std::endl;
	std::cerr << tx << " " << ty << std::endl;

	while(true)
	{
		int remain_turn;
		std::cin >> remain_turn;
		
		float x_dist = tx-vx;
		float y_dist = ty-vy;
		float angle = std::atan2(y_dist,x_dist);
		float deg = (angle*180.0f)/3.14f;
		std::cerr << angle << " " << deg << std::endl;
		
		deg = static_cast<int>(deg);

		std::string ans;
		if(deg > -180 && deg <= -135)
		{
			ans = "SW";
			if(vx > 0) --vx;
			if(vy < max_h) ++vy;
		}
		else if(deg > -135 && deg <= -90)
		{
			ans = "S";
			if(vy < max_h) ++vy;
		}
		else if(deg > -90 && deg <= -45)
		{
			ans = "SE";
			if(vx < max_w) ++vx;
			if(vy < max_h) ++vy;
		}
		else if(deg > -45 && deg <= 0)
		{
			ans = "E";
			if(vx < max_w) ++vx;
		}
		else if(deg > 0 && deg <= 45)
		{
			ans = "NE";
			if(vx < max_w) ++vx;
			if(vy > 0) --vy;
		}
		else if(deg > 45 && deg <= 90)
		{
			ans = "N";
			if(vy > 0) --vy;
		}
		else if(deg > 90 && deg <= 135)
		{
			ans = "NW";
			if(vx > 0) --vx;
			if(vy > 0) --vy;
		}
		else
		{
			ans = "W";
			if(vx > 0) --vx;
		}

		std::cerr << vx << " " << vy << std::endl;
		std::cout << ans << std::endl;
	}

	return 0;
}
