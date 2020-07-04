class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid){
        int r = grid.size();
        if(r==0){
            return 0;
        }
        int c = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
