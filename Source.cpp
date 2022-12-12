#include "Set.h"
#include <iostream>

int main() {
	try {
		Set set1;
		Set set2;
		set1 += 6;
		set1 += 7;
		set1 += 8;
		std::cout << "set 1: " << set1 << std::endl;

		set2 = set1 + 55;
		std::cout << "set 2: " << set2 << std::endl;
		set2 -= 55;
		std::cout << "set 2: " << set2 << std::endl;

		set2 = set1 - 6;
		std::cout << "set 2: " << set2 << std::endl;

		/*
		std::cout << "Equality: " << (set1 == set2) << std::endl;
		std::cout << "! Equality: " << (set1 != set2) << std::endl;*/
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

}

/*try {
		Set set1;
		Set set2;

		set1 + 1;
		set1 + 2;
		set1 + 3;
		set1 + 4;
		set1 + 5;
		std::cout << "Set 1: " << set1 << std::endl;

		set2 += 5;
		set2 += 4;
		set2 += 1;
		set2 += 6;
		set2 += 7;
		std::cout << "Set 2: " << set2 << std::endl;

		std::cout << "Set 1 + Set 2: " << set1 + set2 << std::endl;
		std::cout << "Set 1 - Set 2: " << set1 - set2 << std::endl;

		std::cout << "Set 1 [1]: " << set1[1] << std::endl;
		std::cout << "Set 2 [2]: " << set2[2] << std::endl;

		std::cout << "Delete elements" << std::endl;
		set2 - 4;
		set2 -= 1;
		set1 - 4;
		set1 -= 11;
		std::cout << "New Set 1: " << set1 << std::endl;
		std::cout << "New Set 2: " << set2 << std::endl;

		std::cout << "Intersection: " << set1.intersection(set2) << std::endl;
		std::cout << "Task: " << set1.check_count(set2) << std::endl;
		std::cout << "Check set 1: " << set1.check_num(5) << std::endl;
		std::cout << "Check set 2: " << set2.check_num(11) << std::endl;
		
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}*/