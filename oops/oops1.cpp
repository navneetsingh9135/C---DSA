#include<iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    bool gender;

    void printInfo() {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Gender = " << (gender ? "Male" : "Female") << endl; // Assuming true for Male and false for Female
    }
};

int main() {
    Student arr[3];
    for(int i = 0; i < 3; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "Age: ";
        cin >> arr[i].age;
        cout << "Gender (1 for Male, 0 for Female): ";
        cin >> arr[i].gender;
    }
    
    for(int i = 0; i < 3; i++) { // Start from 0 to include all students
        arr[i].printInfo();
    }

    return 0;
}
