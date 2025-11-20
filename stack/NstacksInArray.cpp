class kStacks {

    // main array to store elements
    int *arr,*top,*next;
    int freespot;
  public:
    kStacks(int n, int k) {
        // initialize data structures for k stacks
        arr=new int[n];
        top=new int[k];
        next=new int[n];
        freespot=0;
        
        for(int i=0;i<k;i++){
            top[i]=-1;
        }
        for(int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;   // last element points to -1
    }

    void push(int x, int i) {
        // push element x into stack i
        
        if(freespot==-1) return ;
        int index=freespot;
        freespot=next[index];
        arr[index]=x;
        next[index]=top[i];
        top[i]=index;
        return ;
    }

    int pop(int i) {
        // pop element from stack i
        if(top[i]==-1) return -1;
        int index=top[i];
        top[i]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};