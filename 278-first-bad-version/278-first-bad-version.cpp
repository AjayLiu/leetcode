// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int upper = n;
        int lower = 1;
        int index = 1;
        while(upper-1>lower){
            index = lower + (upper - lower) / 2;
            if(isBadVersion(index)){
                upper = index;
            } else {
                lower = index;
            }
        }
        index++;
        while(isBadVersion(index))
            index--;
        return index + 1;
    }
};