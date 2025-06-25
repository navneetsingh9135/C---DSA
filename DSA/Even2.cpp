#include <iostream>
using namespace std;
class Node
{
    int n;
    Node *next;
    friend class Linkedlist;
};

class Linkedlist
{
    Node *head, *list;

public:
    Linkedlist() { head = list = new Node; }
    void input();
    void display();
};
void Linkedlist::input()
{
    for (;;)
    {
        cout << "\nEnter a no. '0 for end' ";
        cin >> list->n;
        if (list->n == 0)
        {
            list->next = 0;
            break;
        }
        list->next = new Node;
        list = list->next;
    }
}
void Linkedlist::display()
{
    int count=0;
    list = head;
    while (list->next != 0)
    {
        if (list->n % 2 == 0)
        {
            count++;
            cout << "\n"<< list->n;}
            list = list->next;      
    }
    cout << "\nNo of even nos=" << count;
}
int main()
{
    Linkedlist l;
    l.input();
    l.display();
    return 0;
}