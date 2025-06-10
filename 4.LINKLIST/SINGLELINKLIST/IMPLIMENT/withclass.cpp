#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *link = nullptr;
    node *head = nullptr;

    void beginsert(int val)
    {
        node *newnode = new node;
        newnode->data = val;
        newnode->link = head;
        head = newnode;

        cout << "Node Inserted";
    }

    void lastinsert(int value)
    {

        node *newNode = new node;
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
        }
        node *temp = head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = nullptr;
    }

    void randominsert(int value, int location)
    {
        node *newnode = new node;
        newnode->data = value;
        node *temp, *temp1;
        temp = head;
        if (head == nullptr)
        {
            head = newnode;
        }

        else
        {
           
                for (int i = 1; i < location; i++)
                {
                   
                    temp = temp->link;
                    if (temp == nullptr)
                    {
                        cout << "\ncant Inserterd\n";
                    }
                }

                newnode->link = temp->link;
                temp->link = newnode;
            }
        
    }
    void begdelete()
    {
        node *temp;

        if (head == nullptr)
        {
            cout << "no nodes are present ";
        }
        else if (head->link == nullptr)
        {
            head = nullptr;
            free(head);
        }
        else
        {
            temp = head;
            head = temp->link;
            free(temp);
        }
    }
    void lastdelete()
    {
        node *temp, *temp1;

        if (head == nullptr)
        {
            cout << "no nodes are present ";
        }
        else
        {
            if (head->link == nullptr)
            {
                head = nullptr;
                free(head);
            }
            else
            {
                while (temp != nullptr)
                {
                    temp1 = temp;
                    temp = temp->link;
                }
                temp1->link = nullptr;
                free(temp);
            }
        }
    }
    void middelete()
    {
        int size = 0, mid = 0;
        node *temp, *temp1;
        temp = head;
        
        while (temp != nullptr)
        {
            temp = temp->link;
            size++;
        }
        if (size % 2 == 0)
        {
            mid = (size / 2);
        }
        else
        {
            mid = (size + 1) / 2;
        }
            temp = head;
            if(mid==1){
                head=temp->link;
                free(temp);

            }
            else{
                for (int i = 0; i < mid-1; i++)
            {
                temp1 = temp;
                temp = temp->link;
            }
            temp1->link = temp->link;
            free(temp);
            }
    
    }
    void deleteafternode(int location){
        node * temp,*temp1;
        temp=head;
        for(int i=0;i<location;i++){
            temp1=temp;
            temp=temp->link;
        }
        temp1->link=temp->link;
        free(temp);

    }
    void display()
    {
        node *temp;
        temp = head;
        cout << "LIST ELEMENT" << "                           ";
        while (temp != nullptr)
        {
            cout << temp->data << "  ";
            temp = temp->link;
        }
    }
};

int main()
{
    node obj;
    char choice = 0;

    while (choice != 5)
    {
        cout << "\n\n 1.Begin Insert \n 2.lastinsert\n3.Randominsert\n4.display\n5.firstdelete\n6.lastdelete\n7.Mid delete\n\n8Specific node";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "\n ENTER NUMBER TO INSERT";
            int value;
            cin >> value;
            obj.beginsert(value);
            break;
        case '2':
            cout << "\n ENTER NUMBER TO INSERT";
            int va;
            cin >> va;
            obj.lastinsert(va);
            break;

        case '3':
            cout << "\nEnter Location To insert";
            int n, loc;
            cin >> loc;
            cout << "\n Enter value";
            cin >> n;
            obj.randominsert(n, loc);
            break;
        case '4':
            obj.display();
            break;
        case '5':
            obj.begdelete();
            break;
        case '6':
            obj.lastdelete();
            break;
        case '7':
            obj.middelete();
            break;
        case '8':
        int a;
        cout<<"Enter Location";
        cin>>a;
            obj.deleteafternode(a);
            break;
        }
    }
    return 0;
}
