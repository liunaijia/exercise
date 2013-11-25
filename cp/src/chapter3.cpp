#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>

namespace chapter3 {
void ex341() {
	std::cout << "[3.41]" << std::endl;
	int array[] { 11, 23, 54, 90, 3 };
	std::vector<int> items(std::begin(array), std::end(array));
	for (const auto i : items)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex342() {
	std::cout << "[3.42]" << std::endl;
	const std::vector<int> items { 11, 23, 54, 90, 3 };
	int array[5];
	for (std::vector<int>::size_type i = 0; i < items.size(); i++)
		array[i] = items[i];
	for (const auto i : array)
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
	char c[5 + 6 + 1];
	strcpy(c, a);
	strcat(c, b);
	std::cout << c << std::endl;
}

void ex334() {
	std::cout << "[3.34]" << std::endl;
	int array[] { 0, 10, 20, 30, 40, 50 };
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
	for (auto *p = std::begin(array); p != std::end(array); p++)
		*p = 0;
	for (const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex336() {
	std::cout << "[3.36]" << std::endl;
	int a[] { 1, 2, 3 };
	int b[] { 1, 2, 3 };

	const auto *pa = std::begin(a), *pb = std::begin(b);
	while (pa != std::end(a) && pb != std::end(b)) {
		if (*pa != *pb)
			break;
		pa++;
		pb++;
	}
	if (pa == std::end(a) && pb == std::end(b))
		std::cout << "arrays are equal." << std::endl;
	else
		std::cout << "arrays are NOT equal." << std::endl;

	std::cout << (std::vector<int>(3, 1) == std::vector<int>(3, 1))
			<< std::endl;
	std::cout << (std::vector<int>(2, 1) == std::vector<int>(3, 1))
			<< std::endl;
}

void ex331() {
	std::cout << "[3.31]" << std::endl;
	int array[10];
	for (size_t i = 0; i < 10; i++)
		array[i] = i;
	for (const auto i : array)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex332() {
	std::cout << "[3.32]" << std::endl;
	int array1[10];
	for (size_t i = 0; i < 10; i++)
		array1[i] = i;

	int array2[10];
	for (size_t i = 0; i < 10; i++)
		array2[i] = *(array1 + i);

	for (const auto i : array2)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> v1;
	for (auto i = 0; i < 10; i++)
		v1.push_back(i);
	std::vector<int> v2(v1);
	for (const auto i : v1)
		std::cout << i << " ";
	std::cout << std::endl;
	for (const auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex324() {
	std::cout << "[3.24]" << std::endl;
	std::vector<int> numbers;
	int n;
	while (std::cin >> n)
		numbers.push_back(n);

	for (auto i = numbers.cbegin(); i != numbers.cend() - 1; i++)
		std::cout << *i + *(i + 1) << " ";
	std::cout << std::endl;

	for (auto i = numbers.cbegin(), j = numbers.cend() - 1; i < j; i++, j--)
		std::cout << *i + *j << " ";
	std::cout << std::endl;
}

void ex325() {
	std::cout << "[3.25]" << std::endl;
	std::vector<unsigned> scores(11, 0);
	unsigned grade;
	while (std::cin >> grade) {
		if (grade <= 100)
			++(*(scores.begin() + grade / 10));
	}
	for (auto i = scores.cbegin(); i < scores.cend() - 1; i++) {
		auto base = (i - scores.cbegin()) * 10;
		std::cout << base << " - " << base + 10 << " : " << *i << std::endl;
	}
}

const void show_it(const std::vector<int> v) {
	std::cout << "length = " << v.cend() - v.cbegin() << std::endl;
	for (auto i = v.cbegin(); i != v.cend(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

const void show_it(const std::vector<std::string> v) {
	std::cout << "length = " << v.cend() - v.cbegin() << std::endl;
	for (auto i = v.cbegin(); i != v.cend(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void ex321() {
	std::cout << "[3.21]" << std::endl;
	std::vector<int> v1;	// 0个元素
	std::vector<int> v2(10);	// 10个值为0的元素
	std::vector<int> v3(10, 42);	// 10个值为42的元素
	std::vector<int> v4 { 10 };	// 1个元素，值为10
	std::vector<int> v5 { 10, 42 };	// 2个元素，10和42
	std::vector<std::string> v6 { 10 };	// 10个值为空字符串的元素
	std::vector<std::string> v7 { 10, "hi" };	// 10个值为hi的元素

	show_it(v1);
	show_it(v2);
	show_it(v3);
	show_it(v4);
	show_it(v5);
	show_it(v6);
	show_it(v7);
}

void ex322() {
	std::cout << "[3.22]" << std::endl;
	std::vector<std::string> text;
	std::string line;
	while (getline(std::cin, line))
		text.push_back(line);

	auto first_line = text.begin();
	for (auto c = (*first_line).begin(); c != (*first_line).end(); c++) {
		*c = toupper((*c));
	}
	std::cout << *first_line << std::endl;
}

void ex323() {
	std::cout << "[3.23]" << std::endl;
	std::vector<int> numbers;
	int n;
	while (std::cin >> n)
		numbers.push_back(n);

	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		*it = *it * 2;
	}

	for (const auto i : numbers)
		std::cout << i << " ";
	std::cout << std::endl;
}

const void show_idx(const std::vector<int> v) {
	std::cout << "length = " << v.size() << std::endl;
	for (const auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

const void show_idx(const std::vector<std::string> v) {
	std::cout << "length = " << v.size() << std::endl;
	for (const auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}

void ex316() {
	std::cout << "[3.16]" << std::endl;
	std::vector<int> v1;	// 0个元素
	std::vector<int> v2(10);	// 10个值为0的元素
	std::vector<int> v3(10, 42);	// 10个值为42的元素
	std::vector<int> v4 { 10 };	// 1个元素，值为10
	std::vector<int> v5 { 10, 42 };	// 2个元素，10和42
	std::vector<std::string> v6 { 10 };	// 10个值为空字符串的元素
	std::vector<std::string> v7 { 10, "hi" };	// 10个值为hi的元素

	show_idx(v1);
	show_idx(v2);
	show_idx(v3);
	show_idx(v4);
	show_idx(v5);
	show_idx(v6);
	show_idx(v7);
}

void ex317() {
	std::cout << "[3.17]" << std::endl;
	std::vector<std::string> words;
	std::string word;
	while (std::cin >> word)
		words.push_back(word);
	for (auto &i : words) {
		for (auto &c : i) {
			c = toupper(c);
		}
	}

	for (const auto &i : words)
		std::cout << i << std::endl;
}

void ex320() {
	std::cout << "[3.20]" << std::endl;
	std::vector<int> numbers;
	int n;
	while (std::cin >> n)
		numbers.push_back(n);

	for (decltype(numbers.size()) i = 0; i < numbers.size() - 1; i++)
		std::cout << numbers[i] + numbers[i + 1] << " ";
	std::cout << std::endl;

	for (decltype(numbers.size()) i = 0, j = numbers.size() - 1; i < j;
			i++, j--)
		std::cout << numbers[i] + numbers[j] << " ";
	std::cout << std::endl;
}

void ex314() {
	std::cout << "[3.14]" << std::endl;
	std::vector<int> numbers;
	int n;
	while (std::cin >> n)
		numbers.push_back(n);
}

void ex315() {
	std::cout << "[3.15]" << std::endl;
	std::vector<std::string> words;
	std::string word;
	while (std::cin >> word)
		words.push_back(word);
}

void ex36() {
	std::cout << "[3.6]" << std::endl;
	std::string s("secret!");
	for (auto &c : s)
		c = 'X';
	std::cout << s << std::endl;
}

void ex38() {
	std::cout << "[3.8]" << std::endl;
	std::string s("secret!");
	for (std::string::size_type i = 0; i < s.size(); i++)
		s[i] = 'X';
	std::string::size_type j = 0;
	while (j < s.size())
		s[j++] = 'X';
	std::cout << s << std::endl;
}

void ex310() {
	std::cout << "[3.10]" << std::endl;
	std::string s;
	std::cin >> s;
	std::string trimmed;
	for (const auto &c : s) {
		if (!ispunct(c))
			trimmed += c;
	}
	std::cout << trimmed << std::endl;
}

void ex311() {
	std::cout << "[3.11]" << std::endl;
	const std::string s = "Keep out!";
	for (auto &c : s) {
		std::cout << c;
	}
	std::cout << std::endl;
}

void ex32() {
	std::cout << "[3.2]" << std::endl;
	std::string line;
	while (getline(std::cin, line)) {
		std::cout << line << std::endl;
		if (line.empty())
			break;
	}

	std::string word;
	while (std::cin >> word) {
		std::cout << word << ".";
	}
	std::cout << std::endl;
}

void ex34() {
	std::cout << "[3.4]" << std::endl;
	std::string s1, s2;
	std::cin >> s1 >> s2;

	std::cout << "s1 == s2? " << (s1 == s2) << std::endl;
	if (s1 != s2)
		std::cout << (s1 > s2 ? s1 : s2) << " is bigger." << std::endl;

	std::cout << "length s1 == s2? " << (s1.size() == s2.size()) << std::endl;
	if (s1.size() != s2.size())
		std::cout << (s1.size() > s2.size() ? s1 : s2) << "长度更长." << std::endl;
}

void ex35() {
	std::cout << "[3.5]" << std::endl;
	std::vector<std::string> words;
	std::string word;
	while (std::cin >> word)
		words.push_back(word);

	std::string line1;
	for (const auto i : words)
		line1 += i;

	std::string line2;
	for (const auto i : words) {
		if (!line2.empty())
			line2 += " ";
		line2 += i;
	}

	std::cout << line1 << std::endl;
	std::cout << line2 << std::endl;
}

void run() {
//	ex32();
//	ex34();
//	ex35();
//	ex36();
//	ex38();
//	ex310();
//	ex311();
//	ex314();
//	ex315();
//	ex316();
//	ex317();
//	ex320();
//	ex321();
//	ex322();
//	ex323();
//	ex324();
//	ex325();
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
