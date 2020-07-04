class Solution {
public:
    bool canReach(vector<int>& arr, int start){
        if(arr[start]==0){
            return true;
        }
        vector<int> zeroes;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zeroes.push_back(i);
            }
        }
        unordered_map<int,list<int>> m;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                continue;
            }
            if((i+arr[i])<arr.size()){
                m[i].push_back(i + arr[i]);
            }
            if((i - arr[i])>=0){
                m[i].push_back(i - arr[i]);
            }
        }

        unordered_map<int,bool> visited;
        for(int i=0;i<arr.size();i++){
            visited[arr[i]] = false;
        }

        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neighbour : m[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        for(auto node : zeroes){
            if(visited[node]){
                return true;
            }
        }

        return false;
    }
};
