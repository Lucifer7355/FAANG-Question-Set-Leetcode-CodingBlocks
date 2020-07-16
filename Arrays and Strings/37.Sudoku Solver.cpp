class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int r,int c,char value){
        for(int i=0;i<9;i++){
            if(board[r][i]==value || board[i][c]==value){
                return false;
            }
        }
        int sx = r - r%3;
        int sy = c - c%3;
        for(int i=sx;i<sx+3;i++){
            for(int j=sy;j<sy+3;j++){
                if(board[i][j]==value){
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudokuHelper(vector<vector<char>>& board,int r,int c){
        if(r==9){
            return true;
        }
        if(c==9){
            return solveSudokuHelper(board,r+1,0);
        }
        if(board[r][c]!='.'){
            return solveSudokuHelper(board,r,c+1);
        }
        for(int i=1;i<=9;i++){
            if(isSafe(board,r,c,i+'0')){
                board[r][c] = i+'0';
                bool success = solveSudokuHelper(board,r,c);
                if(success){
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board,0,0);    
    }
};
