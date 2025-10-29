#include<iostream>
using namespace std ;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
    Node(int value){
        prev=NULL;
        data=value;
        next=NULL;
    }
};
void insertAtHead(int value,Node* &head,Node* &tail)
{
    Node* newnode=new Node(value);
    if(head==NULL && tail==NULL) head=tail=newnode;  
    else {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertAtTail(int value,Node* &head,Node* &tail)
{
    Node* newnode=new Node(value);
    if(head==NULL && tail==NULL) head=tail=newnode;  
    else {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

int count (Node* head)
{
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtPosition(Node* &head,Node* &tail,int pos,int size){
   
    Node* temp=head;
    if(pos==1){
        head=head->next;
        delete temp;
    }
    else if(pos==size){
        Node* temp=tail;
        tail=tail->prev;
        delete temp;
    }
    else {
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    Node* targetNode=temp->next;
    temp->next=targetNode->next;
    delete targetNode;
    }
}
void insertAtPosition(Node* &head,Node* &tail,int pos,int size,int value){
    if(pos==1) insertAtHead(value,head,tail);
    else if(pos==size+1) insertAtTail(value,head,tail);
    else {
    Node* newnode=new Node(value);
    Node* temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    Node* nextnode=temp->next;
    temp->next=newnode;
    nextnode->prev=temp;
    newnode->next=nextnode;
}
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(1,head,tail);
    insertAtTail(3,head,tail);
    insertAtTail(4,head,tail);
    insertAtHead(0,head,tail);
    print(head);
    int size=count(head);
    insertAtPosition(head,tail,2,size,2);
    print(head);
    size=count(head);
    deleteAtPosition(head,tail,3,size);
    print(head);
    return 0;
}