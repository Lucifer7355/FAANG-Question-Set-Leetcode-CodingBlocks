#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> killProcess(vector<int>& pid,vector<int>& parent,int k){
    unordered_map<int,list<int>> m;
    vector<int> result;
    for(int i=0;i<pid.size();i++){
        m[parent[i]].push_back(pid[i]);
    }
    queue<int> q;
    result.push_back(k);
    q.push(k);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : m[node]){
            q.push(child);
            result.push_back(child);
        }
    }
    return result;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> pid;
    vector<int> parent;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pid.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        parent.push_back(x);
    }
    vector<int> result = killProcess(pid,parent,k);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}

