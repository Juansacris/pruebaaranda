#include <iostream>
#include <stdlib.h>
#include "Nodo.h"
#include <vector>


int main()
{
	std::vector<int> a({ 1,2,3,3,4 });
	a.push_back(2);
	
	for (int x : a)
	{
		std::cout << x << std::endl;
	}
}