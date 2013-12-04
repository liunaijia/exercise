/*
 * chapter4.cpp
 *
 *  Created on: 2013年12月3日
 *      Author: liunaijia
 */
#include <iostream>
#include <vector>

namespace chapter4{

void ex41(){
	std::cout << "[4.1]" << std::endl;
	std::cout << 5 + 10 * 20 / 2 << std::endl;
}

void ex44(){
	std::cout << "[4.4]" << std::endl;
	std::cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << std::endl;
}

void ex45(){
	std::cout << "[4.5]" << std::endl;
	std::cout << -30 * 3 + 21 / 5 << std::endl;
	std::cout << -30 + 3 * 21 / 5 << std::endl;
	std::cout << -30 / 3 * 21 % 5 << std::endl;
	std::cout << -30 / 3 * 21 % 4 << std::endl;
}

void ex46(){
	std::cout << "[4.6]" << std::endl;
	auto x = 3;
	std::cout << x << (x % 2 == 0 ? "偶数" : "奇数") << std::endl;
	auto y = 78;
	std::cout << y << (y % 2 == 0 ? "偶数" : "奇数") << std::endl;
}

void ex49() {
	std::cout << "[4.9]" << std::endl;
	const char *cp = "Hello World";
	if (cp && *cp) {
		std::cout << "非空指针且非空字符串" << std::endl;
	}
}

void ex410() {
	std::cout << "[4.10]" << std::endl;
	int x;
	do {
		std::cin >> x;
	}while(x != 42);
}

void ex411() {
	std::cout << "[4.11]" << std::endl;
	int a, b, c, d;
	a = b = c = d = 0;
	auto result = a > b && b > c && c > d;
	std::cout << result << std::endl;
}

void ex412() {
	std::cout << "[4.12]" << std::endl;
	int i, j, k;
	j = 1;
	k = 2;
	i = 1;
	// 原题代码是 i != j < k
	std::cout << (i != (j < k)) << std::endl;	// j < k的结果与i进行比较
}

void ex413() {
	std::cout << "[4.13]" << std::endl;
	int i;
	double d;
	d = i = 3.5;
	std::cout << d << " " << i << std::endl;	// 3 3
	i = d = 3.5;
	std::cout << d << " " << i << std::endl;	// 3.5 3
}

void ex421() {
	std::cout << "[4.21]" << std::endl;
	std::vector<int> v{1,2,3,4,5};
	for(auto &i : v) {
		if (i % 2 == 1)
			i *= 2;
	}
	for(const auto i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void ex422() {
	std::cout << "[4.22]" << std::endl;
	unsigned score = 51;
	std::string grade;
	if (score > 90)
		grade = "high pass";
	else if (score > 75)
		grade = "pass";
	else if (score > 60)
		grade = "low pass";
	else
		grade = "fail";
	std::cout << score << " " << grade << std::endl;

	grade = score > 90 ? "high pass"
			: score > 75 ? "pass"
					: score > 60 ? "low pass"
							: "fail";
	std::cout << score << " " << grade << std::endl;
}

void run() {
//	ex41();
//	ex44();
//	ex45();
//	ex46();
//	ex49();
//	ex410();
//	ex411();
//	ex412();
//	ex413();
//	ex421();
	ex422();
}
}


