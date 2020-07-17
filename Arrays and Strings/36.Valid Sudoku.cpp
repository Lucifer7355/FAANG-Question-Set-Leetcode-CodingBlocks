class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                for(int k=j+1;k<n;k++){
                    if(board[i][j]==board[i][k] && j!=k){
                        cout<<board[i][j]<<endl;
                        return false;
                    }
                }
                for(int k=i+1;k<n;k++){
                    if(board[i][j]==board[k][j] && i!=k){
                        return false;
                    }
                }
                int sx = i - i%3;
                int sy = j - j%3;
                for(int r=sx;r<sx+3;r++){
                    for(int c=sy;c<sy+3;c++){
                        if(board[i][j]==board[r][c] && i!=r && j!=c){
                            
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
