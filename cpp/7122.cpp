#include <iostream>

using namespace std;

int main() {
	int input(int scores[], int max_length);
	void show_scores(const int scores[], int length);
	double avg(const int scores[], int length);

	int scores[10];
	int length = input(scores, 10);
	show_scores(scores, length);
	cout << endl << avg(scores, length) << endl;

	return 0;
}

int input(int scores[], int max_length) {
	int length = 0;
	while(true) {
		cout << "input scores:";
		if (!(cin >> scores[length]) || scores[length] < 0)
			break;
		length++;

		if (length == max_length)
			break;
	}
	return length;
}

void show_scores(const int scores[], int length) {
	for(int i = 0; i < length; i++) {
		cout << scores[i];
		if (i < length - 1)
			cout << ", ";
	}
}

double avg(const int scores[], int length) {
	double sum = 0;
	for(int i = 0; i < length; i++)
		sum += scores[i];
	return sum / length;
}