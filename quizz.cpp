#include <iostream>
#include <iostream>
using namespace std;

struct Student {
	int id;
	char *name;
	float cgpa;
};

int main() {
	int n;

	cout << "Enter n: ";
	cin >> n;

	Student *students = new Student[n];

	for(int i = 0; i < n; i++) {
		int tid;
		char *tname;
		float tcgpa;
		cout << "Enter Id:  ";
		cin >> tid;
		getchar();
		cout << "Enter name: ";
		gets(tname);
		cout << "Enter cgpa: ";
		cin >> tcgpa;

		students[i].id = tid;
		students[i].name = tname;
		students[i].cgpa = tcgpa;
		cout << "Inserted\n";
	}

	Student s = students[0];
	for(int i = 1; i < n; i++) {
		if(students[i].cgpa > s.cgpa) s = students[i];
	}

	cout << "\nHighest cpga holder\n";
	cout << "Id: " << s.id << endl;
	cout << "Name: " << *s.name << endl;
	cout << "Cgpa: " << s.cgpa << endl;

	delete [] students;
}
