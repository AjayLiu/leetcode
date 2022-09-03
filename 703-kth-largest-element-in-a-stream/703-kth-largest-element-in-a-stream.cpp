class KthLargest {
private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
public:
    
    KthLargest(int k, vector<int>& nums): k(k), pq(nums.begin(), nums.end()) {
            
    }
    
    int add(int val) {
        pq.push(val);
        // pop until k items remaining in pq
        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */