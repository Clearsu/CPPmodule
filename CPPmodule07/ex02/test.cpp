#include <iostream>
int main()
{
	int * a = new int();
	std::cout << sizeof(*a) << std::endl;
	return 0;
}
