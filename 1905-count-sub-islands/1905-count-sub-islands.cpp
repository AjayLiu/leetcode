class Solution {
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j){
        if(i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || grid2[i][j] == 0)
            return true;
        if(grid2[i][j] == 1){
            if(grid1[i][j] == 0)
                return false;
        } 
        grid2[i][j]=0;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool flag = true;
        for(auto [x,y] : dirs){
            if(!dfs(grid1, grid2, i+x, j+y))
                flag = false;
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for(int i = 0; i < grid2.size(); i++){
            for(int j = 0; j < grid2[i].size(); j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1, grid2, i, j)){
                        ans++;
                    }
                }
                    
            }
        }
        return ans;
    }
};