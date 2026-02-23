class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        unordered_set<string> h;
        for(int i=0;i<=s.size()-k;i++){
            string v=s.substr(i,k);
            h.insert(v);
            
        }
        return (h.size()==(1<<k));
    }
};