class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        
        
        unordered_map<char, int> freq1;
        for(int i = 0; i < s1.length(); i++){
            char c = s1[i];
            freq1[c]++;
        }
        
        unordered_map<char, int> freq2;
        for(int i = 0; i < s2.length(); i++){
            char c = s2[i];
            freq2[c]++;
            
            bool good = true;
            for(auto it = freq1.begin(); it != freq1.end(); it++){
                char key = it->first;
                auto findIter = freq2.find(key);
                if(findIter == freq2.end() || findIter->second < it->second){
                    good = false;
                    break;
                }
            }
            if(good)
                return true;
            
            if(i >= s1.length()-1){
                char toForget = s2[i-s1.length()+1];
                freq2[toForget]--;
            }
        }
        
        
        /*
        for(auto it = freq1.begin(); it != freq1.end(); it++){
            cout<<it->first<<it->second<<" ";
        }
        */
        
        
        return false;
    }
};