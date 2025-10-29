#include<iostream>
using namespace std ;

void insertatlast(stack<int> &st,int n){
    if(st.empty()){ 
        st.push(n);
        return ;
    }
    int temp=st.top();
    st.pop();
    insertatlast(st,n);
    st.push(temp);
}

void deleteatmid(stack<int> &st,int &mid ,int count) {
    if(count==mid) {
        st.pop();
        return ;
    }
    int temp=st.top();
    st.pop();
    count++;
    deleteatmid(st,mid,count);
    st.push(temp);
}

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    // //want to delete last element
    // insertatlast(st,8);
    int size=st.size();
    int mid=size/2;
    deleteatmid(st,mid,0);
    size=st.size();
    for(int i=0;i<size;i++)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}