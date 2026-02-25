class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> count_map;
        for(int a:arr){
            int c=__builtin_popcount(a);
            count_map[c].push_back(a);
        }
        vector<int> result;
        for(auto &p:count_map){
            sort(p.second.begin(), p.second.end());   
            for (int x : p.second) {
                result.push_back(x);
            }
        }
        return result;
    }
};