#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;
        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main() {
    LRUCache cache(2); // Cache capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl; // returns 1
    
    cache.put(3, 3); // evicts key 2
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)
    
    cache.put(4, 4); // evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 3
    cout << "Get 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
