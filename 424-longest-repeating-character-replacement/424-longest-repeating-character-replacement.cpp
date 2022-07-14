class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> dict;
        int ans = 0;
        while(right < s.size()){
            char c = s[right];
            dict[c]++;
            right++;
            auto most = max_element(dict.begin(), dict.end(), 
                [] (const pair<char, int> &a, const pair<char, int> &b){
                    return a.second < b.second;
                }
            );
            int needsReplace = (right - left) - most->second;
            /*
            cout<<"MOST "<<most->first<<":"<<most->second<<endl;
            cout<<s.substr(left, right-left)<<endl;
            cout<<needsReplace<<endl;
            cout<<"========\n";
            */
            
            if(needsReplace > k){
                dict[s[left]]--;
                left++;
            } else {
                ans = max(ans, right - left);
            }
        }
        return ans;
    }
};