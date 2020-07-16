bool compare(string s1,string s2){
    return s1.length()>s2.length();
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        sort(strs.begin(),strs.end(),compare);
        string result = "";
        for(int i=0;i<strs[0].length();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=strs[0][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};
