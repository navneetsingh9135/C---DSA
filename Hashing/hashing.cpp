#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // include this for find
using namespace std;

class Hashing {
    vector<list<int>> hashtable;
    int buckets;

public:
    Hashing(int size) {
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key) {
        return key % buckets;
    }

    void addKey(int key) {
        int index = hashvalue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator searchKey(int key) {
        int index = hashvalue(key);
        return find(hashtable[index].begin(), hashtable[index].end(), key);
    }

    void deleteKey(int key) {
        int index = hashvalue(key);
        auto it = searchKey(key);  // Store the result of searchKey to avoid duplicate calls
        if (it != hashtable[index].end()) {
            hashtable[index].erase(it);
            cout << key << " is deleted" << endl;
        } else {
            cout << "Key is not present inside the hashtable" << endl;
        }
    }
};

int main() {
    Hashing h(10);
    h.addKey(5);
    h.addKey(9);
    h.addKey(3);
    h.deleteKey(3);
    h.deleteKey(3);
    h.deleteKey(3);
}
