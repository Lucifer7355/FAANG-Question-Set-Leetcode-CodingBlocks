class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<string> color(vertices,"white");    

        for(int i=0;i<vertices;i++){
            if(color[i]=="white"){
                queue<int> q;
                q.push(i);
                color[i] = "blue";
                while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    int no_of_children = graph[parent].size();
                    for(int j=0;j<no_of_children;j++){
                        int child = graph[parent][j];
                        if(color[child]=="white"){
                            if(color[parent]=="red"){
                                color[child] = "blue";
                            }else{
                                color[child] = "red";
                            }
                            q.push(child);
                        }else{
                            if(color[child]==color[parent]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
