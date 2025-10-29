/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head)
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        Node* lastNode=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return lastNode;
    }
  
    Node* addOne(Node* head) {
        //step-1 reverse the linked list
       head=reverse(head);
       //step -2 add 1
       Node* temp=head;
       int carry=1;
       while(temp!=NULL)
       {
            int sum=carry+temp->data;
            int digit=sum%10;
            carry=sum/10;
            temp->data=digit;
            if(temp->next==NULL && carry==1)
            {
                Node* newnode=new Node(1);
                temp->next=newnode;
                temp=newnode;
            }
            temp=temp->next;
       }
       //step-3 reverse
      head=reverse(head);
       return head;
    }
};