#include <iostream>
using namespace std;
class student
{
     string name;
     public:
    int age;
    bool gender;

    student(){
        cout<<"Default constructor"<<endl;
    }


    student(string s,int a,int g){
        cout<<"Parameterised constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }
    student(student &a){
        cout<<"Copy consructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }

    ~student(){
        cout<<"Destructor called";
    }
    void setName(string s){
        name=s;

    }
    void getName(){
        cout<<name<<endl;
    }

    void printInfo()
    {
        cout << "Name= ";
        cout << name << endl;
        cout << "Age= ";
        cout << age << endl;
        cout << "Gender= ";
        cout << gender << endl;
    }
    bool operator==(student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }
        return false;

    }
};
int main()
{
    //student arr[3];
    //for (int i = 0; i < 3; i++)
    //{
      //  string s;
        //cout << "Name= ";
        //cin >>s;
        //arr[i].setName(s);
      //  cout << "Age= ";
        //cin >> arr[i].age;
       // cout << "Gender= ";
        //cin >> arr[i].gender;
    //}
    //for (int i = 0; i < 3; i++)
    //{
      //  arr[i].printInfo();
    //}/
    student a("Navneet",19,0);
    //a.printInfo();
    student b("Rahul",21,0);
    student c=a;
    if(b==a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
}