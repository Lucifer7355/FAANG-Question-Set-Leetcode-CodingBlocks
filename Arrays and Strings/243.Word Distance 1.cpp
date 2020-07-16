#include<bits/stdc++.h>
using namespace std;

int shortestDistance(vector<string>& v,string word1,string word2){
    int n = v.size();
    int w1 = -1;
    int w2 = -1;
    int m = n;
    for(int i=0;i<n;i++){
        if(v[i]==word1){
            w1 = i;
        }
        if(v[i]==word2){
            w2 = i;
        }
        if(w1!=-1 && w2!=-1){
            m = min(m,abs(w1-w2));
        }
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v.push_back(x);
    }
    string word1,word2;
    cin>>word1>>word2;
    cout<<shortestDistance(v,word1,word2);
    return 0;
}

