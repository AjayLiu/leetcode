class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int ans = INT_MAX;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            
            if(sum >= target){
                ans = min(right - left + 1, ans);   
            }
            
            while(sum >= target && left <= right){
                sum -= nums[left];
                left++;
                if(sum >= target){
                    ans = min(right - left + 1, ans);   
                }
                
                /*
                for(int i = left; i <= right; i++){
                    cout<<nums[i]<<" ";
                }
                cout<<"="<<sum<<endl;
                */
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};