class Solution {
public:
    string reorganizeString(string s){
        int freq[26] = {};
        for(int i=0;i<s.length();i++){
            freq[(int)(s[i]-'a')]++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(make_pair(freq[i],(char)('a'+i)));
            }
        }
        string ans = "";
        while(!pq.empty()){
            if(pq.size()>1){
                pair<int,char> p1;
                pair<int,char> p2;
                p1 = pq.top();
                pq.pop();
                p2 = pq.top();
                pq.pop();
                ans = ans + p1.second;
                ans = ans + p2.second;
                p1.first--;
                p2.first--;
                if(p1.first!=0){
                    pq.push(p1);
                }
                if(p2.first!=0){
                    pq.push(p2);
                }
            }else if(pq.size()==1){
                if(pq.top().first>1){
                    return "";
                }else{
                    ans = ans + pq.top().second;
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
