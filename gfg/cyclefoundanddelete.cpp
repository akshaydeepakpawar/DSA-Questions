/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(fast==nullptr || fast->next==nullptr) return; //no loop
        slow=head;
        //if loop start a start from head;
        
        if(slow==fast){
            
            while(fast->next!=slow)
                fast=fast->next;
            fast->next=nullptr;
            return ;
        }
        
        //cycle on other node
        while(fast->next!=slow->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        fast->next=nullptr;
    }
};