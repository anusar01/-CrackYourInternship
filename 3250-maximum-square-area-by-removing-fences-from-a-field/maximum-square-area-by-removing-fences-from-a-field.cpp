class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);
        
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        vector<long long> hGaps;
        for(int i=0;i<hFences.size()-1;i++){
            hGaps.push_back(hFences[i+1]-hFences[i]);
        }

        vector<long long> vGaps;
        for(int i=0;i<vFences.size()-1;i++){
            vGaps.push_back(vFences[i+1]-vFences[i]);
        }

        unordered_set<long long> hpossible;
        for (int i = 0; i < hGaps.size(); i++) {
            long long sum = 0;
            for (int j = i; j < hGaps.size(); j++) {
                sum += hGaps[j];
                hpossible.insert(sum);
            }
        }

        unordered_set<long long> vpossible;
        for (int i = 0; i < vGaps.size(); i++) {
            long long sum = 0;
            for (int j = i; j < vGaps.size(); j++) {
                sum += vGaps[j];
                vpossible.insert(sum);
            }
        }

        long long maxSide = -1;

        for (auto h : hpossible) {
        if (vpossible.count(h)) {
            maxSide = max(maxSide, h);
        }
        }

        if(maxSide==-1) return -1;

        int mod=1e9+7;
        return ((maxSide%mod)*(maxSide%mod))%mod;
    }
};