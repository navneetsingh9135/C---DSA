#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(preorder);
    return 0;
}