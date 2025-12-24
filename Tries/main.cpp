#include <iostream>
using namespace std;

class TrieNode{
    public:
    char ch;
    unordered_map<int,TrieNode*> children;
    bool isTerminal;
    TrieNode(char data):ch(data){}
};

void insertNode(TrieNode* root,string s){
    //base condition
    if(s.size()==0){
        root->isTerminal=true;
        return ;
    }
    TrieNode* child;
    char ch=s[0];
    //agar node present hoga tab
    if(root->children[ch]){
        //child ko aage badado
        child=root->children[ch];
    }
    //agar absent he toh
    else{
        child =new TrieNode(ch);
        //iss child ko root se connect karo
        root->children[ch]=child; //iss line me map me entry bhi ho rahi he
    }
    //baki recc sambhal lega
    insertNode(child,s.substr(1));
}

bool search(TrieNode* root,string s){
    if(s.size()==0 && root->isTerminal){
        return true;
    }
    char ch=s[0];
    //agar node nahi hoga toh
    if(!root->children[ch]) return false;
    else{
        root=root->children[ch];
        search(root,s.substr(1));
    }
    return false;
}

void deleteNode(TrieNode* root,string s){
    if(s.size()==0 && root->isTerminal){
        root->isTerminal=false;
    }
    char ch=s[0];
    //agar node nahi hoga toh
    if(!root->children[ch]) return ;
    else{
        root=root->children[ch];
        deleteNode(root,s.substr(1));
    }
}

void print(TrieNode* root,string s,string &ans){
    if(s.size()==0 && root->isTerminal){
        cout<<"world is present : "<<ans<<endl;
        return ;
    }
     char ch=s[0];
    //agar node nahi hoga toh
    if(!root->children[ch]) cout<<"word is not present"<<endl;
    else{
        ans+=ch;
        root=root->children[ch];
        print(root,s.substr(1),ans);
    }
}

int main()
{
    TrieNode* root=new TrieNode('_');
    vector<string> words = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "kiwi",
    "mango"
};
    //insert nodes
    for(int i=0;i<words.size();i++){
        insertNode(root,words[i]);
    }
    cout<<"printing all nodes: "<<endl;
    for(int i=0;i<words.size();i++){
        string str="";
        print(root,words[i],str);
    }
    //deleting nodes
    for(int i=words.size()/2;i<words.size();i++){
        deleteNode(root,words[i]);
    }
    cout<<"after deleting nodes"<<endl;
    for(int i=0;i<words.size()/2;i++){
        string str="";
        print(root,words[i],str);
    }
    

    return 0;
}