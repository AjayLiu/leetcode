class Solution {
public:
    
    bool hasFresh(vector<vector<int>> &grid){
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) return true;
            }
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if(q.empty()){
            if(!hasFresh(grid)){
                return 0;
            } else {
                return -1;
            }
        }
        int ans = -1;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                pair<int, int> thisRot = q.front();
                grid[thisRot.first][thisRot.second] = 2;
                q.pop();
                
                //cout<<thisRot.first<<","<<thisRot.second<<endl;

                if(thisRot.first > 0){
                    if(grid[thisRot.first-1][thisRot.second] == 1){
                        q.push({thisRot.first - 1, thisRot.second});
                        grid[thisRot.first -1][thisRot.second] = 3;
                    }
                }
                if(thisRot.first < grid.size() - 1){
                    if(grid[thisRot.first+1][thisRot.second] == 1){
                        q.push({thisRot.first + 1, thisRot.second});
                        grid[thisRot.first + 1][thisRot.second] = 3;
                    }
                }
                if(thisRot.second > 0){
                    if(grid[thisRot.first][thisRot.second-1] == 1){
                        q.push({thisRot.first, thisRot.second-1});
                        grid[thisRot.first][thisRot.second-1] = 3;
                    }
                }
                if(thisRot.second < grid[0].size() - 1){
                    if(grid[thisRot.first][thisRot.second+1] == 1){
                        q.push({thisRot.first, thisRot.second+1});
                        grid[thisRot.first][thisRot.second+1] = 3;
                    }
                }
            }
            ans++;
            //cout<<ans<<endl;
        }
        if(hasFresh(grid)){
            return -1;
        }
        return ans;
    }
};