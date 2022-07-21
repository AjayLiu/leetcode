class Solution {
public:
    vector<vector<int>> ans;
    
    void bfs(vector<vector<int>> &meta, vector<vector<int>> &heights, bool isPacific){
        queue<pair<int, int>> q;
        
        if(isPacific){
            // pacific
            // left row
            for(int i = 0; i < heights.size(); i++){
                q.push({i, 0});
            }
            // top row
            for(int i = 0; i < heights[0].size(); i++){
                q.push({0, i});
            }
        } else {
            // atlantic
            // right row
            for(int i = 0; i < heights.size(); i++){
                q.push({i, heights[i].size()-1});
            }
            // bottom row
            for(int i = 0; i < heights[0].size(); i++){
                q.push({heights.size()-1, i});
            }
        }
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto [x, y] = q.front();
                q.pop();
                
                if(x < 0 || y < 0 || x >= meta.size() || y >= meta[0].size())
                    continue;
                if(isPacific){
                    if(meta[x][y] == 1){
                        continue; // visited
                    }
                    meta[x][y] = 1;
                } else {
                    if(meta[x][y] == 2){
                        continue; // visited
                    }
                    if(meta[x][y] == 1){
                        ans.push_back({x, y});
                        meta[x][y] = 3;
                    } else {
                        meta[x][y] = 2;
                    }
                }
                
                // up
                if(x>0 && heights[x-1][y] >= heights[x][y]){
                    q.push({x-1,y});
                }
                // down
                if(x<heights.size()-1 && heights[x+1][y] >= heights[x][y]){
                    q.push({x+1,y});
                }
                // left
                if(y>0 && heights[x][y-1] >= heights[x][y]){
                    q.push({x,y-1});
                }
                // down
                if(y<heights[0].size()-1 && heights[x][y+1] >= heights[x][y]){
                    q.push({x,y+1});
                }
                
            }
            
            /*
            for(int i = 0; i < meta.size(); i++){
                for(int j = 0; j < meta[i].size(); j++){
                    cout<<meta[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            */
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 0 = unexplored / untouched
        // 1 = pacific visited
        // 2 = atlantic visited
        // 3 = both
        
        
        vector<vector<int> > meta{ heights.size(), vector<int>(heights[0].size()) }; 
 
        bfs(meta, heights, true);
        bfs(meta, heights, false);
        
        return ans;
    }
};