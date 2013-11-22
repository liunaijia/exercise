#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>

namespace chapter3 {
void ex341() {
	std::cout << "[3.41]" << std::endl;
	int array[]{11, 23, 54, 90, 3};
	std::vector<int> items(std::begin(array), std::end(array));
	for(const auto i : items)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex342() {
	std::cout << "[3.42]" << std::endl;
	const std::vector<int> items{11, 23, 54, 90, 3};
	int array[items.size()];
	for(std::vector<int>::size_type i = 0; i < items.size(); i++)
		array[i] = items[i];
	for(const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex343() {
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

void ex344() {
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

void ex345() {
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

void ex339() {
	std::cout << "[3.39]" << std::endl;
	const std::string a("hello"), b("hello");
	std::cout << (a < b) << (a == b) << (a > b) << std::endl;

	std::cout << strcmp("hello", "hello") << std::endl;
	std::cout << strcmp("smart", "world") << std::endl;
	std::cout << strcmp("java", "c++") << std::endl;
}

void ex340() {
	std::cout << "[3.40]" << std::endl;
	char a[] = "hello";
	char b[] = " world";
	char c[strlen(a) + strlen(b) + 1];
	strcpy(c, a);
	strcat(c, b);
	std::cout << c << std::endl;
}

void ex334() {
	std::cout << "[3.34]" << std::endl;
	int array[]{0, 10, 20, 30, 40, 50};
	auto *p1 = array + 1;
	auto *p2 = std::end(array);
	std::cout << "p1:" << *p1 << ", p2:" << *p2 << std::endl;
	p1 += p2 - p1;
	std::cout << "p1:" << *p1 << ", p2:" << *p2 << std::endl;
	std::cout << std::endl;
}

void ex335() {
	std::cout << "[3.35]" << std::endl;
	int array[10];
	for(auto *p = std::begin(array); p != std::end(array);p++)
		*p = 0;
	for(const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex336() {
	std::cout << "[3.36]" << std::endl;
	int a[]{1, 2, 3};
	int b[]{1, 2, 3};

	const auto *pa = std::begin(a), *pb = std::begin(b);
	while(pa != std::end(a) && pb != std::end(b)){
		if (*pa != *pb)
			break;
		pa++;
		pb++;
	}
	if (pa == std::end(a) && pb == std::end(b))
		std::cout << "arrays are equal." << std::endl;
	else
		std::cout << "arrays are NOT equal." << std::endl;

	std::cout << (std::vector<int>(3, 1) == std::vector<int>(3, 1)) << std::endl;
	std::cout << (std::vector<int>(2, 1) == std::vector<int>(3, 1)) << std::endl;
}

void ex331() {
	std::cout << "[3.31]" << std::endl;
	int array[10];
	for(size_t i = 0; i < 10; i++)
		array[i] = i;
	for(const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex332() {
	std::cout << "[3.32]" << std::endl;
	int array1[10];
	for(size_t i = 0; i < 10; i++)
		array1[i] = i;

	size_t size = std::end(array1) - std::begin(array1);
	int array2[size];
	for(size_t i = 0; i < size; i++)
		array2[i] = *(array1 + i);

	for(const auto i : array2)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> v1;
	for(auto i = 0; i < 10; i++)
		v1.push_back(i);
	std::vector<int> v2(v1);
	for(const auto i : v1)
		std::cout << i << " ";
	std::cout << std::endl;
	for(const auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;
}

void run() {
//	ex331();
//	ex332();
//	ex334();
//	ex335();
//	ex336();
//	ex339();
//	ex340();
//	ex341();
//	ex342();
//	ex343();
//	ex344();
//	ex345();
}

}
