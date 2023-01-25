// Doubley Linked List

#include <bits/stdc++.h>
using namespace std;
class Linked
{
public:
    int data;
    Linked *prev;
    Linked *next;
    Linked *head;
    Linked *tail;
    void insertion(int data);
    void updation(int data, int pos);
    void deletion(int pos);
    void print(char);
};

// Insertion of the data
void Linked::insertion(int data)
{
    Linked *temp = new Linked();
    temp->data = data;
    if (head == 0)
    {
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        tail = head;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
}

// updation of the data
void Linked::updation(int data, int pos)
{
    int cnt = 1;
    Linked *temp = new Linked();
    Linked *cur = new Linked();
    cur = head;
    Linked *pre_pos = new Linked();
    temp->data = data;
    // 1st edge case
    if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    // Normal case
    while (cnt < pos)
    {
        pre_pos = cur;
        cur = cur->next;
        cnt++;
    }
    if(cur->next==NULL)
    {
        cur->next=temp;
        temp->prev=cur;
        temp->next=NULL;
        tail=temp;
        return;
    }
    temp->next = pre_pos->next;
    pre_pos->next = temp;
    temp->prev = pre_pos;
    cur->prev = temp;
}

// deletion
void Linked::deletion(int pos)
{
    int cur = 1;
    Linked *temp = new Linked();
    temp = head;
    while (cur < pos)
    {
        temp = temp->next;
        cur++;
    }
    // 1st edge case
    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        tail = temp->prev;
        temp->prev = NULL;
        delete (temp);
        return;
    }

    // 2nd edge case
    if (temp->prev == NULL)
    {
        head = temp->next;
        temp->next = NULL;
        delete (temp);
        return;
    }

    // normal case
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete (temp);
}

// Print of the data
void Linked::print(char start)
{
    Linked *temp = new Linked();
    (start == 'B') ? temp = head : temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        (start == 'B') ? temp = temp->next : temp = temp->prev;
    }
    cout << endl;
    cout << tail->data;
    cout << "...................................." << endl;
}

int main()
{
    Linked *obj = new Linked();
    obj->insertion(1);
    obj->insertion(2);
    obj->insertion(4);
    obj->insertion(5);
    //  obj->print('B');
    obj->updation(3, 3);
    //  obj->print('E');
    obj->updation(0, 1);
    obj->print('B');
    obj->updation(6, 6);
    obj->print('B');
    obj->deletion(3);
    obj->deletion(6);
    obj->deletion(1);
    obj->print('B');

    return 0;
}