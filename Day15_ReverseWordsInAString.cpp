class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "";
        string word = "";
        while(ss >> word)
        {
            ans = word + ' ' + ans;
        }
        if(!ans.empty()) ans.pop_back();
        return ans;
    }
};
