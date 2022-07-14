class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length() > s.length())
            return ans;
        
        unordered_map<char, int> pMap;
        for(char c : p){
            pMap[c]++;
        }
        
        unordered_map<char, int> sMap;
        int sEntries = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(sEntries >= p.length()){
                char toForget = s[i-p.length()];
                auto f = sMap.find(toForget);
                if(f->second==1){
                    sMap.erase(toForget);
                } else {
                    f->second--;
                }
            } 
            
            sMap[c]++;
            sEntries++;
            
            /*
            for(auto it = sMap.begin(); it != sMap.end(); it++){
                cout<<it->first<<": "<<it->second<<", ";
            }
            cout<<endl;
            */
            
            if(sMap == pMap)
                ans.push_back(i-p.length()+1);
        }
        return ans;
    }
};