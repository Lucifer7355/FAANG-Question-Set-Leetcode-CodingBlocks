class Solution {
public:
    
    bool isdigits(char c){
        return (c>='0' && c<='9');
    }
    
    bool isalpha(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    
    string decodeString(string s){
        string ans = "";
        string temp = "";
        stack<pair<string,int>> st;
        for(int i=0;i<s.size();i++){
            if(isdigits(s[i])){
                int num = 0;
                while(isdigits(s[i])){
                    int tempnum = s[i] - '0';
                    num = num*10 + tempnum;
                    i++;
                }
                st.push(make_pair(temp,num));
                temp = "";
            }else if(isalpha(s[i])){
                temp = temp + s[i];
            }else if(s[i]==']'){
                pair<string,int> p = st.top();
                st.pop();
                string current = p.first;
                for(int j=0;j<p.second;j++){
                    current = current + temp;
                }
                if(s.empty()){
                    ans = ans + temp;
                    temp = "";
                }else{
                    temp = current;
                }
            }
        }
        ans = ans + temp;
        return ans;
    }
};
