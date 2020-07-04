class Solution {
public:
    void dfsHelper(unordered_map<int,list<int>>& m,unordered_map<int,bool>& visited,int src){
        visited[src] = true;
        for(auto child : m[src]){
            if(!visited[child]){
                dfsHelper(m,visited,child);
            }
        }
    }

    int dfs(unordered_map<int,list<int>>& m,int n){
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsHelper(m,visited,i);
                components++;
            }
        }
        return components;
    }

    int findCircleNum(vector<vector<int>>& M) {
        unordered_map<int,list<int>> m;
        int n = M.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]){
                    m[i].push_back(j);
                }
            }
        }
        return dfs(m,n);
    }
};
