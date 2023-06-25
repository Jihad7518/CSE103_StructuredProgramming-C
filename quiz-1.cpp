#include<iostream>
#include<climits>
using namespace std;
// Student structure
struct Student {
    int id;
    char *name = new char[100];
    float CGPA;
} typedef Student;
// main function
int main() {
    // read data for n
    int n;
    int max_CGPA = INT_MIN, max_index = 0;
    cout << "Enter no. of students: "; cin >> n;
    // declare Student array
    Student *array = new Student[n];
    // read data for n Student
    for(int i = 0; i < n; i++) {
        cout << "Enter data for student number " << i + 1 << endl;
        cout << "Enter id: "; cin >> array[i].id;
        cout << "Enter name: "; cin >> array[i].name;
        cout << "Enter CGPA: "; cin >> array[i].CGPA;
        if(max_CGPA < array[i].CGPA) {
            max_CGPA = array[i].CGPA;
            max_index = i;
        }
    }

    sort(cgpa, cgpa + n);

    cout << "\nArray after sorting using "
            "default sort is : \n";
    for (int i = 0; i < n; ++i){
        cout << array[i] << " ";
    }

    return 0;
}
