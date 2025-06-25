
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout << "\nEnter a number: ";
    cin >> n;
    int sum = 0;
    int originaln = n;
    while(n > 0){
        int lastdigit = n % 10;
        sum += pow(lastdigit, 3); // Corrected here
        n = n / 10;
    }
    if(sum == originaln){
        cout << "\nArmstrong number" << endl;
    } else {
        cout << "\nNot Armstrong number" << endl;
    }
    return 0;
}


