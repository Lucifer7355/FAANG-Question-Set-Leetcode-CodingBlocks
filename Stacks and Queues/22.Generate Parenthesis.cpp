class Solution {
public:
    void generateParenthesisHelper(string s,vector<string>& result,int open,int close,int n){
        if(open==n && close==n){
            result.push_back(s);
            return;
        }
        
        if(open>close){
            generateParenthesisHelper(s+')',result,open,close+1,n);
        }
        if(open<n){
            generateParenthesisHelper(s+'(',result,open+1,close,n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        if(n==1) return {"()"};
        vector<string> result;
        generateParenthesisHelper("",result,0,0,n);
        return result;
    }
};
