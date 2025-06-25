#include<iostream>
using namespace std;
int main(){
    int rows;
    cout<<"\nEnter the no of rows";
    cin>>rows;
    cout<<endl;
    for(int i=0;i<=rows;i++){
        int value=1;
        for(int j=1;j<=rows-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<"  "<<value;
            value=value*(i-k)/(k+1);
        }
        cout<<endl<<endl;
   }
   cout<<endl;
   return 0;
}