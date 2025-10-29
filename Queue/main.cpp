#include<iostream>
using namespace std ;

class Queue{
    private:
    int *arr,n,front,back;
    public:
    Queue(int size)
    {
        n=size;
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void push(int val){
        if(front==-1 && back==-1) {
            back++;
            front++;
            arr[back]=val;
        }
        else if(back==n-1) {
            cout<<"the queue is full"<<endl;
            return ;
        }
        else{
            back++;
            arr[back]=val;
        }
    }
    void pop(){
        if(front==-1 && back==-1) {
           cout<<"the queue is empty"<<endl;
           return ;
        }
        else if(front==back) {
            arr[front]=-1;
            front--;
            back--;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    bool empty(){
        if(front==-1 && back==-1) {
            return true;
        }
        return false;
    }
    int size(){
        return back-front+1;
    }
    void print() {
        if (empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int peek(){
        return arr[front];
    }
    int last(){
        return arr[back];
    }
};

int main()
{
    Queue q(5);

    cout << "Adding elements..." << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.print();

    cout << "Front element: " << q.peek() << endl;
    cout << "Back element: " << q.last() << endl;
    cout << "Queue size: " << q.size() << endl;


    cout << "Removing two elements..." << endl;
    q.pop();
    q.pop();
    q.print();

    cout << "Adding more elements..." << endl;
    q.push(40);
    q.push(50);
    q.push(60); // should say full if exceeds size
    q.print();

    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}