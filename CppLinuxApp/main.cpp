#include <cstdio>
#include <iostream>
#include "time/date.h"

int main()
{
	auto date = xpl::time::Date(2019, 6, 5);
    //printf("hello from CppLinuxApp!\n");
	std::cout << date << std::endl;
    return 0;
}