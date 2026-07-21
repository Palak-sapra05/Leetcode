class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }
        if(board[i][j]!='O'){
            return;
        }
        board[i][j]='#';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            dfs(i,0,board);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,board);
        }
        for(int i=0;i<n;i++){
            dfs(i,m-1,board);
        }
        for(int j=0;j<m;j++){
            dfs(n-1,j,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};