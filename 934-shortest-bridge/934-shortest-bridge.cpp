class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    bool findAndMarkIsland(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> &q){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1)
            return false;
        
        q.push({i, j});
        
        grid[i][j] = 2;
        
        for(auto [x,y] : dirs){
            findAndMarkIsland(grid, i+x, j+y, q);
        }
        
        return true;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        bool foundIsland = false;
        for(int i = 0; i < grid.size() && !foundIsland; i++){
            for(int j = 0; j < grid.size(); j++){
                if(findAndMarkIsland(grid, i, j, q) ){
                    foundIsland = true;
                    break;
                }
            }
        }
        
        
        
        
        // do a bfs from island marked with '2' to any '1'(the other island)
        int wave = -1;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto [x, y] = q.front();
                q.pop();
                
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid.size() || grid[x][y] == 3){
                    continue;
                }
                
                // found other island
                if(grid[x][y] == 1)
                    return wave;
                
                grid[x][y] = 3; // explored
                
                for(auto [dx,dy] : dirs){
                    q.push({x+dx, y+dy});
                }
                
            }
            wave++;
            
            
            /*
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid.size(); j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
        }
        
        
        
        return 9999;
    }
};