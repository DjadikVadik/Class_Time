#include "Time.h"

int main()
{
	system("chcp 1251 > 0");
	
	Time time;
	std::cout << time << "\n";
	time + 3800;
	std::cout << time << "\n";;
}


