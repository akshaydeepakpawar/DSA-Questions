#include <iostream>
using namespace std;

class twoStack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    twoStack(int capacity)
    {
        arr = new int[capacity];
        size = capacity;
        top1 = -1;
        top2 = size;
    }
    void push1(int val)
    {
        // edge case
        if (top1 + 1 == top2)
        {
            cout << "the stack 1 is overflow" << endl;
            return;
        }
        top1++;
        arr[top1] = val;
    }
    void push2(int val)
    {
        // edge case
        if (top1 + 1 == top2)
        {
            cout << "the stack 2 is overflow" << endl;
            return;
        }
        top2--;
        arr[top2] = val;
    }
    int pop1()
    {
        // edge case
        if (top1 == -1)
        {
            cout << "the stack 1 is underflow" << endl;
            return -1;
        }
        top1--;
        return arr[top1 + 1];
    }
    int pop2()
    {
        // edge case
        if (top2 == size)
        {
            cout << "the stack 2 is underflow" << endl;
            return -1;
        }
        top2++;
        return arr[top2 - 1];
    }

    bool isEmpty1()
    {
        if (top1 == -1)
        {
            cout << "the stack 1 is empty" << endl;
            return true;
        }
        cout << "the stack 1 is not empty" << endl;
        return false;
    }
    bool isEmpty2()
    {
        if (top2 == size)
        {
            cout << "the stack 2 is empty" << endl;
            return true;
        }
        cout << "the stack 2 is not empty" << endl;
        return false;
    }

    int peek1()
    {
        if (isEmpty1())
        {
            return -1;
        }
        return arr[top1];
    }
    int peek2()
    {
        if (isEmpty2())
        {
            return -1;
        }
        return arr[top2];
    }
    bool isFull()
    {
        return top1 + 1 == top2;
    }
    int size1()
    {
        if (isEmpty1())
        {
            return -1;
        }
        return top1 + 1;
    }
    int size2()
    {
        if (isEmpty2())
        {
            return -1;
        }
        return size - top2;
    }
    void printStacks()
    {
        cout << "stack-1 : " << endl;
        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " " << endl;
        }
        cout << "stack-2 : " << endl;
        for (int i = size - 1; i >= top2; i--)
        {
            cout << arr[i] << " " << endl;
        }
    }
};
int main()
{
    int n = 10;
    twoStack ts(n);

    cout << "\n"
         << "Testing push operations..." << endl;
    for (int i = 1; i <= 5; i++)
    {
        ts.push1(i * 10);
        ts.push2(i * 100);
    }

    cout << "\nStack 1 top: " << ts.peek1() << endl;
    cout << "Stack 2 top: " << ts.peek2() << endl;

    cout << "\nPopping two elements from each stack..." << endl;
    cout << "Pop1: " << ts.pop1() << endl;
    cout << "Pop1: " << ts.pop1() << endl;
    cout << "Pop2: " << ts.pop2() << endl;
    cout << "Pop2: " << ts.pop2() << endl;

    cout << "\nAfter pops:" << endl;
    cout << "Stack 1 top: " << ts.peek1() << endl;
    cout << "Stack 2 top: " << ts.peek2() << endl;

    cout << "\nChecking if stacks are empty..." << endl;
    cout << "Stack1 empty? " << (ts.isEmpty1() ? "Yes" : "No") << endl;
    cout << "Stack2 empty? " << (ts.isEmpty2() ? "Yes" : "No") << endl;

    cout << "\nFilling both stacks completely..." << endl;
    int val = 60;
    while (!ts.isFull())
    {
        ts.push1(val++);
        if (!ts.isFull())
            ts.push2(val * 10);
    }

    cout << "Array full? " << (ts.isFull() ? "Yes" : "No") << endl;

    cout << "\nFinal sizes:" << endl;
    cout << "Stack1 size: " << ts.size1() << endl;
    cout << "Stack2 size: " << ts.size2() << endl;

    cout << "\nEmptying both stacks completely..." << endl;
    while (!ts.isEmpty1())
        cout << ts.pop1() << " ";
    cout << endl;
    while (!ts.isEmpty2())
        cout << ts.pop2() << " ";
    cout << endl;

    cout << "\nAll test cases executed successfully!" << endl;

    return 0;
}