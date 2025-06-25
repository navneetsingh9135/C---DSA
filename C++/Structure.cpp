#include<iostream>
#include<cstdio>
using namespace std;

struct student{
    char n[20];
    int r,m;
};

int main(){
    student stud;
    cout << "\nEnter Roll: ";
    cin >> stud.r;
    cout << "\nEnter name: ";
    cin.ignore(); 
    cin.getline(stud.n, 20); 
    cout << "\nEnter marks: ";
    cin >> stud.m;
    cout << "\nRoll: " << stud.r;
    cout << "\nName: " << stud.n;
    cout << "\nMarks: " << stud.m;
    return 0;
}

