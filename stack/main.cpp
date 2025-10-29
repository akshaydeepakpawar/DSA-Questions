#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;
    // constructor
    Stack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top = -1;
    }
    // functions
    void push(int val)
    {
        if (top == size - 1)
            cout << "Stack OverFlow"<<endl;
        else
        {
            top++;
            arr[top] = val;
        }
    }
    void pop()
    {
        if (top == -1)
            cout << "the stack is underflow"<<endl;
        else
        {
            arr[top] = -1; //optional step
            top--;
        }
    }
    int getSize()
    {
        return top+1;
    }
    int getTop()
    {
        return arr[top];
    }
    bool isempty()
    {
        if(top==-1) return true;
        else return false;
    }
};

int main()
{
    Stack st(5);
    st.pop();
    st.push(6);
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    cout<<"the size of stack is "<<st.getSize()<<endl;
    st.pop();
    cout<<"the size of stack is "<<st.getSize()<<endl;
    cout<<"the top element of the stack is "<< st.getTop()<<endl;
    cout<<"the stack is empty? "<<st.isempty()<<endl;
    return 0;
}