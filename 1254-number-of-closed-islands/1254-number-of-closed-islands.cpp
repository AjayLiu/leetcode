class Solution {
public:
    bool connectsToEdge(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) 
            return true;
        if(grid[i][j] == 1 )
            return false;
        
        grid[i][j]=1;
        
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool flag = false;
        for(auto [x, y] : dirs){
            if(connectsToEdge(grid, i+x, j+y)){
                flag = true;
            }
        }
        return flag;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0 && !connectsToEdge(grid,  i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};