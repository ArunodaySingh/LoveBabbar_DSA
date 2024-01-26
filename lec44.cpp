#include <bits/stdc++.h>
using namespace std;
class Linked
{
public:
    int data;
    Linked *Next;
    Linked *Head = 0;
    void Insert_data(int data)
    {
        Linked *temp = new Linked();
        temp->data = data;
        if (Head == 0)
        {
            Head = temp;
            Next = Head;
            temp->Next = NULL;
        }
        else
        {
            Next->Next = temp;
            Next = temp;
            temp->Next = NULL;
        }
    }
    void print()
    {
        Linked *temp = new Linked();
        temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->Next;
        }
        // cout << "Head address " << Head << endl;
        // cout << "Next address " << Next;
    }

    void man_insertion(int data, int pos)
    {
        Linked *temp2 = new Linked();
        if(pos==1)
        {
            temp2->data=data;
            temp2->Next=Head;
            Head=temp2;
            return;
        }
        
        Linked *temp = new Linked();
        int cnt = 1;
        temp = Head;
        while (cnt < pos - 1)
        {
            temp=temp->Next;
            cnt++;
        }
        temp2->data=data;
        temp2->Next=temp->Next;
        temp->Next=temp2;

    }

    void deletion(int pos)
    {
        Linked *cur=new Linked();
        Linked *pos_back=new Linked();
        cur=Head;
        if(pos==1)
        {
            Head=Head->Next;
            cur->Next=NULL;
            delete cur;
            return;
        }
        int cnt=1;
        
        while(cnt<pos)
        {
            pos_back=cur;
            cur=cur->Next;
            cnt++;
        }
        pos_back->Next=cur->Next;
        cur->Next=NULL;
        delete cur;


    }
};

int main()
{
    Linked *Obj ;
    Obj->Insert_data(1);
    Obj->Insert_data(2);
    Obj->Insert_data(3);
    Obj->Insert_data(4);
    Obj->print();
    cout<<"After updation"<<endl;
    Obj->man_insertion(5,3);
    Obj->print();
    cout<<"After deletion"<<endl;
    Obj->deletion(1);
    Obj->print();

    return 0;
}