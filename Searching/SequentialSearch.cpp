#include<iostream>
using namespace std;

int main(){
    int list[10], i, s, pos = -1;
    cout << "\nEnter 10 numbers: ";
    for(i = 0; i < 10; i++) 
        cin >> list[i];
    cout << "\nEnter a number to search: ";
    cin >> s;
    for(i = 0; i < 10; i++)
        if(list[i] == s){
            pos = i + 1; 
            break;
        }
    if(pos == -1)
        cout << "\nNumber is not found";
    else
        cout << "\nPosition = " << pos;
    return 0;
}
