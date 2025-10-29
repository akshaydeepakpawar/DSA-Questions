/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  
  void insertAthead(Node* &head,int value)
  {
      Node* newnode=new Node(value);
      if(head==NULL) head=newnode;
      else{
          newnode->next=head;
          head=newnode;
      }
  }
 
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* lastnode=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return lastnode;
    }
 
  
    Node* addTwoLists(Node* head1, Node* head2) {
        Node* head=NULL;
        //step 1: skip zeros;
        while(head1!=nullptr && head1->data==0 )
        {
            head1=head1->next;
        }
         while(head2!=nullptr && head2->data==0)
        {
            head2=head2->next;
        }
        //step 2: reverse both the array
        head1=reverse(head1);
        head2=reverse(head2);
        //step 3:do sum
        int carry=0;
        while(head1!=nullptr || head2!=nullptr || carry!=0)
        {
            int val1=(head1!=nullptr)?head1->data:0;
            int val2=(head2!=nullptr)?head2->data:0;
            int sum=val1+val2+carry;
            int digit=sum%10;
            carry=sum/10;
            
            insertAthead(head,digit);
            
            if(head1!=nullptr) head1=head1->next;
            if(head2!=nullptr) head2=head2->next;
        }
        return head;
    }
};