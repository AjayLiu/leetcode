class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_map<char, int> freqS, freqG;
        for(int i = 0; i < secret.length(); i++){
            char &s = secret[i];
            char &g = guess[i];
            if(s == g){
                A++;
            } else {
                freqS[s]++;
                freqG[g]++;
            }
        }
        
        for(auto it = freqG.begin(); it != freqG.end(); it++){
            auto f = freqS.find(it->first);
            if(f != freqS.end()){
                B += min(f->second, it->second);
            }
        }
        
        return to_string(A)+"A"+to_string(B)+"B";
    }
};