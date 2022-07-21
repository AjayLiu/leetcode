class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ans = -1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        
        int wave = 1;
        bool visited[grid.size()][grid.size()];
        for(int i = 0; i < grid.size(); i++){
          for(int j = 0; j < grid.size(); j++){
            visited[i][j] = false;
          }
        }
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto [x, y] = q.front();
                q.pop();
                
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || visited[x][y]){
                    continue;
                }
                visited[x][y]=true;
                grid[x][y]=wave;
                ans = max(ans, wave-1);
                
                q.push({x+1, y});
                q.push({x-1, y});
                q.push({x, y+1});
                q.push({x, y-1});
            }
            
            /*
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[i].size(); j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
            
            wave++;
        }
        
        
        if(ans == 0)
            return -1;
        
        return ans;
    }
};