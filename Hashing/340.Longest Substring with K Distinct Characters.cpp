#include<bits/stdc++.h>
using namespace std;

int length(string s,int k){
    int n = s.size();
    unordered_map<char,int> m;
    int start = 0;
    int maxLength = 0;
    for(int i=0;i<n;i++){
        char ch = s[i];
        m[ch] = i;
        if(m.size()>k){
            char c;
            int minIndex = INT_MAX;
            for(auto key : m){
                if(key.second<minIndex){
                    c = key.first;
                    minIndex = key.second;
                }
            }
            start = minIndex + 1;
            m.erase(c);
        }
        maxLength = max(maxLength,i-start+1);
    }
    return maxLength;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int k;
        cin>>k;
        cout<<length(s,k)<<endl;
    }
    return 0;
}
