#include<iostream>
#include<stack>
using namespace std ;


void print(stack<int> &s)
{
    if(s.empty()) return ;
    int top=s.top();
    cout<<top<<" ";
    s.pop();
    print(s);
    s.push(top);
    return ;
}

void insertAtBottom(stack<int> &s , int &val)
{
    if(s.empty()){ 
        s.push(val);
        return ;
    }
    int top=s.top();
    s.pop();
    insertAtBottom(s,val);
    s.push(top);
}

void reverse(stack<int> &s){
    if(s.empty()) return ;
    int top=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,top);
}


int main()
{
    stack<int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(50);
    s.push(40);
    cout<<"Before Stack reverse : "<<endl;
    print(s);
    reverse(s);
    cout<<"\n After Stack reverse : "<<endl;
    print(s);
    return 0;
}