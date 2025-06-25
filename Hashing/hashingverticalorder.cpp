#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)

struct node {
    int key;
    node* left;
    node* right;
};

node* newnode(int key) {
    node* newNode = new node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void getVerticalOrder(node* root, int hdis, map<int,vector<int>> &m) {
    if (root == NULL) {
        return;
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

signed main() {
    node* root = newnode(10);
    root->left = newnode(7);
    root->right = newnode(4);
    root->left->left = newnode(3);
    root->left->right = newnode(11);
    root->right->left = newnode(14);
    root->right->right = newnode(6);

    map<int,vector<int>> m;
    int hdis = 0;
    getVerticalOrder(root, hdis, m);

    map<int,vi>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < (it->ss).size(); i++) {
            cout << (it->ss)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
