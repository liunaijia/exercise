#include <iostream>
using namespace std;

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int opplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int main() {
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	 for(int i = 0; i < entered; i++) {
	 	display1(ptr_stu[i]);
	 	display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done";

	return 0;
}

int getinfo(student pa[], int n) {
	int i = 0;
	while(i < n) {
		cout << "student #" << i + 1 << endl;
		cout << "\tfullname: ";
		cin.getline(pa[i].fullname, SLEN);
		if (pa[i].fullname[0] == '\0')
			break;
		
		cout << "\thobby: ";
		cin.getline(pa[i].hobby, SLEN);
		
		cout << "\topplevel: ";
		cin >> pa[i].opplevel;
		cin.get();

		i++;
	}

	return i;
}

void display1(student st) {
	cout << st.fullname << "\t" << st.hobby << "\t" << st.opplevel << endl;
}

void display2(const student* ps) {
	cout << ps->fullname << "\t" << ps->hobby << "\t" << ps->opplevel << endl;	
}

void display3(const student pa[], int n) {
	for(int i = 0; i < n; i++)
		cout << "#" << i + 1 << "\t" << pa[i].fullname << "\t" << pa[i].hobby << "\t" << pa[i].opplevel << endl;	
}