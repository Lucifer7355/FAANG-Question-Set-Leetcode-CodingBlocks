class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int& count){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        count++;
        dfs(grid,i,j-1,n,m,count);
        dfs(grid,i,j+1,n,m,count);
        dfs(grid,i-1,j,n,m,count);
        dfs(grid,i+1,j,n,m,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0){
            return 0;
        }
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(grid,i,j,n,m,count);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};
