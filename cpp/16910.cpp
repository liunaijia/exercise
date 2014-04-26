#include <iostream>
#include <ctime>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct Review {
	string title;
	int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worse_than(const Review& r1, const Review& r2);
bool random(const Review& r1, const Review& r2);
// bool fill_review(Review& r);
void show_review(const Review& r);

int main() {
	list<Review> books;
	books.push_back(Review{"google", 5});
	books.push_back(Review{"zoo", 1});
	books.push_back(Review{"alibaba", 3});
	books.push_back(Review{"oracle", 4});
	books.push_back(Review{"ibm", 4});
	//Review temp;
	//while(fill_review(temp))
	//	books.push_back(temp);
	cout << "Thank you. You entered the following " << books.size()
		<< " ratings: " << endl
		<< "Rating \t Book" << endl;
	for_each(books.begin(), books.end(), show_review);
	
	books.sort();
	cout << "Sorted by title:\nRating\tBook\n";
	for_each(books.begin(), books.end(), show_review);

	books.sort(worse_than);
	cout << "Sorted by rating:\nRating\tBook\n";
	for_each(books.begin(), books.end(), show_review);

	srand(time(0));
	books.sort(random);
	cout << "After shuffling:\nRating\tBook\n";
	for_each(books.begin(), books.end(), show_review);	

	cout << "Bye.\n";
	return 0;
}

bool operator<(const Review& r1, const Review& r2) {
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worse_than(const Review& r1, const Review& r2) {
	return r1.rating < r2.rating;
}

bool random(const Review& r1, const Review& r2) {
	return rand() * 2 / RAND_MAX < 1;
}

void show_review(const Review& r) {
	cout << r.rating << "\t" << r.title << endl;
}