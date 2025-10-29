#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout << "NULL";
}
int length(Node *head)
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition(Node *&head, Node *&tail, int value ,int position,int size)
{
    if(position==1){
        insertAtHead(head,tail,value);
    }
    else if(position==size+1)
    {
        insertAtTail(head,tail,value);
    }
    else if(position>1 && position<size)
    {
        Node *temp=head;
        //initial postion of head / temp is 1 
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        Node *newNode=new Node(value);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    else{
        cout<<"Invalid Position"<<endl;
    }
}
void deleteAtPosition(Node *&head, Node *&tail ,int position,int size)
{
    Node *newnode=head;
    //there is only element
    if(head==tail) {
        delete head;
        head=NULL;
        return ;
    }
    //wanted to delete 1st position element
    else if(position==1){
        head=head->next;
        delete newnode;
        return;
    }
    //in between
    else{
        for(int i=0;i<position-2;i++)
        {
            newnode=newnode->next;
        }
        Node* temp=newnode->next; //targeted node
        newnode->next=temp->next;
        delete temp;
        return ;
    }
}
int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtTail(head,tail,100);
    print(head);
    cout<<"\n"<<"Length: " << length(head) <<endl;
    insertAtPosition(head,tail,50,4,length(head));
    print(head);
    cout<<"\n"<<"Length: " << length(head) <<endl;
    deleteAtPosition(head,tail,4,length(head));
    print(head);
    cout<<"\n"<<"Length: " << length(head) <<endl;

    return 0;
}