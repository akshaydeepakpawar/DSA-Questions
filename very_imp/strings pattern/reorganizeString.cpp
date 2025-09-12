#include<iostream>
using namespace std ;

string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        // counting the frequency of all char
        for (auto ch : s) {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] > ((n + 1) / 2))
                return "";
        }
        // THE EXPLANATION OF MAX HEAP OF PRIORITY QUEUE BCOZ I AM USING THIS
        // FIRST TIME

        // priority queue used bcoz the highest frequency char comes at the top
        // if the freq is same then the elements sorted by the char the largest
        // char comes at the top. this pririty queue also called as the max heap
        // the vector is the by default container no need to define just define
        // the data type here we use the pair  you can also define max heap like
        // this
        // (priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,   char>>pq;)
        // and for min heap
        // (priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>pq;)
        priority_queue<pair<int, char>> pq;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] != 0) {
                pq.push({freq[ch - 'a'], ch});
            }
        }
        //in priority queue the pop function pop outs the top element in the pq.
        string ans = "";
        while (pq.size() > 1) {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            ans.push_back(it1.second);
            ans.push_back(it2.second);
            it1.first--;
            it2.first--;
            if (it1.first > 0)
                pq.push(it1);
            if (it2.first > 0)
                pq.push(it2);
        }
        //well we are adding the 2 char at the time so if one remain for the odd length string so handel that
        if (pq.size() != 0)
            ans.push_back(pq.top().second);
        return ans;
    }
int main()
{
    cout<<reorganizeString("aaab")<<endl;
    cout<<reorganizeString("aab");
    return 0;
}