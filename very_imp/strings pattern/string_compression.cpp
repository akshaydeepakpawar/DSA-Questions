#include <iostream>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0, index = 0, n = chars.size();
    while (i < n)
    {
        char curr_char = chars[i];
        int count = 0;
        while (i < n && chars[i] == curr_char)
        {
            count++;
            i++;
        }
        chars[index++] = curr_char;
        if (count > 1)
        {
            string str = to_string(count);
            for (int i = 0; i < str.size(); i++)
                chars[index++] = str[i];
        }
    }
    return index;
}
int main()
{
    vector<char> chars={'a','a','b','b','c','c','c'};
    cout<<compress(chars);
    return 0;
}