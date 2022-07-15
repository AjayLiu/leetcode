class Solution {
public:
    void cleanup(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j>= grid[i].size() || grid[i][j] == '0')
            return;
        
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
        }
        
        const vector<pair<int, int>> dirs = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        for(auto [x, y] : dirs){
            cleanup(grid, i+x, j+y);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                int thisGrid = grid[i][j];
                if(thisGrid == '1'){
                    thisGrid = '2';
                    ans++;
                    cleanup(grid, i, j);
                }
            }
        }
        return ans;
    }
};