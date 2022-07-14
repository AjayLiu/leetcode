class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                int val = triangle[i][j];
                int upLeft = 10*10*10*10;
                int upRight = 10*10*10*10;
                if(j > 0){
                    upLeft = triangle[i-1][j-1];
                }
                if(j < triangle[i].size() - 1){
                    upRight = triangle[i-1][j];
                }
                
                triangle[i][j] = min(val + upLeft, val + upRight);
            }
        }
        
        vector<int> lastRow = triangle[triangle.size()-1];
        return *min_element(lastRow.begin(), lastRow.end());
    }
};