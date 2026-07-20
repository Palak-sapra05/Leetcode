class Solution {
private:
    void markLandCells(int x, int y, vector<vector<int>> & grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return;
        grid[x][y]=2;
        markLandCells(x,y+1,grid);
        markLandCells(x+1,y,grid);
        markLandCells(x,y-1,grid);
        markLandCells(x-1,y,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        //step 1: go through boundary cell
        // Left boundary
    for(int i=0;i<n;i++){
        if(grid[i][0]==1)
            markLandCells(i,0,grid);
    }

        // Top boundary 
    for(int j=0;j<m;j++){
        if(grid[0][j]==1)
            markLandCells(0,j,grid);
    }

    // Right boundary
    for(int i=0;i<n;i++){
        if(grid[i][m-1]==1)
            markLandCells(i,m-1,grid);
    }

    // Bottom boundary
    for(int j=0;j<m;j++){
        if(grid[n-1][j]==1)
            markLandCells(n-1,j,grid);
    }
        //Step 2: count unvisited cell of matrix
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
                }
            }
        return count;
    }
};