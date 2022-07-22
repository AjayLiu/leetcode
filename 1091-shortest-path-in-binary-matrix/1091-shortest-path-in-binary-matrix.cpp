class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) return -1;
        
        int wave = 1;
        queue<pair<int, int>> q;
        q.push({0,0});
        
        vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1}, 
                                      {0,-1},        {0,1},
                                      {1,-1}, {1,0}, {1,1}};
        while(!q.empty()){
            int n = q.size();
            bool trapped = true;
            for(int i = 0; i < n; i++){
                auto [x,y] = q.front();
                q.pop();
                
                // out of bounds
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid.size()){
                    continue;
                }
                
                // wall or explored
                if(grid[x][y] == 1)
                    continue;
                
                // mark explored
                grid[x][y] = 1;
                trapped = false;
                
                // reached goal
                if(x == grid.size()-1 && y == grid.size()-1)
                    return wave;
                
                // next wave
                for(auto [dx, dy] : dirs){
                    q.push({x+dx, y+dy});
                }
            }
            if(trapped){
                return -1;
            }
            
            wave++;
        }
        
        return wave;
    }
};