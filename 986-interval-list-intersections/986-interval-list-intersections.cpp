class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int a = 0, b = 0;
        vector<vector<int>> ans;
        while(a < firstList.size() && b < secondList.size()){
            int aStart = firstList[a][0];
            int aEnd = firstList[a][1];
            int bStart = secondList[b][0];
            int bEnd = secondList[b][1];
            
            int crossA = aEnd - bStart;
            int crossB = bEnd - aStart;
            
            if(bStart > aEnd){
                a++;
                continue;
            }
            if(aStart > bEnd){
                b++;
                continue;
            }

            if(aStart >= bStart && aEnd <= bEnd){
                ans.push_back({aStart, aEnd});
                a++;
                continue;
            }
            if(bStart >= aStart && bEnd <= aEnd){
                ans.push_back({bStart, bEnd});
                b++;
                continue;
            }
            
            if(crossA < crossB){
                ans.push_back({bStart, aEnd});
                a++;
            } else {
                ans.push_back({aStart, bEnd});
                b++;
            }
        }
        return ans;
    }
};