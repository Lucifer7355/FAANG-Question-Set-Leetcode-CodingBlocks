class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid){
        vector<int> rows = {0,0,-1,1};
        vector<int> columns = {1,-1,0,0};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> x = q.front();
            q.pop();
            int row = x.first.first;
            int col = x.first.second;
            int depth = x.second;
            ans = max(ans,depth);
            for(int i=0;i<4;i++){
                int nr = row + rows[i];
                int nc = col + columns[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push(make_pair(make_pair(nr,nc),depth + 1));
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;    
    }
};
