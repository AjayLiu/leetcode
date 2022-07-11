class Solution {
public:
    
    void reduce(vector<vector<char>>& grid, int r, int c, bool ignoreThis){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
        char thisGrid = grid[r][c];
        if(thisGrid == '1'){
            if(!ignoreThis){
                grid[r][c] = '0';
            } else {
                grid[r][c] = '2';
            }
            reduce(grid, r-1, c, false);
            reduce(grid, r+1, c, false);
            reduce(grid, r, c-1, false);
            reduce(grid, r, c+1, false);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                reduce(grid, i, j, true);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '2'){
                    ans++;
                }
            }
        }
        return ans;
    }
};