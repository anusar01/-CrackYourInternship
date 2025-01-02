class Solution {
public:
    vector<int> runsums;
    int total=0;
    Solution(vector<int>& w) {
        int prefsum=0;
        for(int weight:w){
            prefsum+=weight;
            runsums.push_back(prefsum);
        }
        total=prefsum;
    }
    
    int pickIndex() {
        int target=rand()%total+1;
        int low=0,high=runsums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(target>runsums[mid]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */