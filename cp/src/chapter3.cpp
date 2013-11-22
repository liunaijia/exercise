#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>

namespace chapter3 {
void run341() {
	std::cout << "[3.41]" << std::endl;
	int array[]{11, 23, 54, 90, 3};
	std::vector<int> items(std::begin(array), std::end(array));
	for(const auto i : items)
		std::cout << i << " ";
	std::cout << std::endl;
}

void run342() {
	std::cout << "[3.42]" << std::endl;
	const std::vector<int> items{11, 23, 54, 90, 3};
	int array[items.size()];
	for(std::vector<int>::size_type i = 0; i < items.size(); i++)
		array[i] = items[i];
	for(const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void run343() {
	std::cout << "[3.43]" << std::endl;
	int ia[3][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 } };

	std::cout << "范围for方式：" << std::endl;
	for (const int (&row)[4] : ia) {
		for (const int &i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "下标方式：" << std::endl;
	for (size_t row = 0; row < 3; row++) {
		for (size_t i = 0; i < 4; i++) {
			std::cout << ia[row][i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "指针方式：" << std::endl;
	for (int (*row)[4] = std::begin(ia); row != std::end(ia); row++) {
		for (int *i = std::begin(*row); i != std::end(*row); i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
}

void run344() {
	std::cout << "[3.44]" << std::endl;
	int ia[3][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 } };

	std::cout << "范围for方式：" << std::endl;
	typedef int (&row_type_ref)[4];
	for (const row_type_ref row : ia) {
		for (const int &i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "下标方式：" << std::endl;
	using index_type = size_t;
	for (index_type row = 0; row < 3; row++) {
		for (index_type i = 0; i < 4; i++) {
			std::cout << ia[row][i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "指针方式：" << std::endl;
	typedef int (*row_type_ptr)[4];
	for (row_type_ptr row = std::begin(ia); row != std::end(ia); row++) {
		for (int *i = std::begin(*row); i != std::end(*row); i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
}

void run345() {
	std::cout << "[3.45]" << std::endl;
	int ia[3][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 8, 9, 10, 11 } };

	std::cout << "范围for方式：" << std::endl;
	for (const auto &row : ia) {
		for (const auto i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "下标方式：" << std::endl;
	for (auto row = 0; row < 3; row++) {
		for (auto i = 0; i < 4; i++) {
			std::cout << ia[row][i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "指针方式：" << std::endl;
	for (auto *row = std::begin(ia); row != std::end(ia); row++) {
		for (auto *i = std::begin(*row); i != std::end(*row); i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
}

void run339() {
	const std::string a("hello"), b("hello");
	std::cout << (a < b) << (a == b) << (a > b) << std::endl;

	std::cout << strcmp("hello", "hello") << std::endl;
	std::cout << strcmp("smart", "world") << std::endl;
	std::cout << strcmp("java", "c++") << std::endl;
}

void run() {
	run339();
//	run341();
//	run342();
//	run343();
//	run344();
//	run345();
}

}
