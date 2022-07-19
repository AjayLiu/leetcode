class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() * matrix[0].size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            
            int num = matrix[row][col];
            
            if(num == target)
                return true;
            if(num > target){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(matrix[left / matrix[0].size()][left % matrix[0].size()] == target)
            return true;
        return false;
    }
};