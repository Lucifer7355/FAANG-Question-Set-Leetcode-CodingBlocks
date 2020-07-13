class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string x;
        for(int i=0;i<num.size();i++){
            char ch = num[i];
            while(!s.empty() && k>0 && ch<s.top()){
                s.pop();
                k--;
            }
            s.push(ch);
        }
        while(!s.empty()){
            x.insert(x.begin(),s.top());
            s.pop();
        }
        string ans = x.substr(0,x.length()-k);
        int i=0;
        while(i<ans.length() && ans[i]=='0'){
            ans = ans.substr(1,ans.length());
        }
        return ans=="" ? "0" : ans;
    }
};
