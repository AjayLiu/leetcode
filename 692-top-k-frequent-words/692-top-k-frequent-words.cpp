class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<string, vector<string>, greater<string> > buckets[words.size()]; // freq -> list of words
        
        unordered_map<string, int> freq;
        // count freq of each word
        for(string s : words){
            freq[s]++;
        }
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            buckets[it->second].push(it->first);
        }
        
        vector<string> ans;
        int i = words.size()-1;
        while(ans.size() < k){
            while(!buckets[i].empty()){
                string w = buckets[i].top();
                buckets[i].pop();
                ans.push_back(w);
                
                if(ans.size() == k)
                    break;
            }
            i--;
        }
        return ans;
    }
};