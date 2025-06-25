#include <iostream>
using namespace std;
class Balance{

    public:

    int total;

    Balance(){
        total = 0;
    }

    void deposit(int amount){
        total += amount;
    }
    void withdraw(int amount){
        total -= amount;
    }

    void display(){
        cout<<total<<endl;
    }

};
int main() {

    Balance b1;
    b1.deposit(100);
    b1.display();
    b1.withdraw(50);
    b1.display();
    return 0;
}