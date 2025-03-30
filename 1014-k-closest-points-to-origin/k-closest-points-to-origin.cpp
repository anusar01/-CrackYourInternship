class Solution {
public:
    int eucliddist(vector<int>& p){
        return p[0] * p[0] + p[1] * p[1];;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<vector<int>,int>> dist; 
        for(int i=0;i<points.size();i++){
            int d=eucliddist(points[i]);
            dist.push_back({points[i],d});
        }
        //arrange in asc order
        sort(dist.begin(),dist.end(),[](const pair<vector<int>,int>& a,const pair<vector<int>,int>& b){
            return a.second<b.second;
        });
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(dist[i].first);
        }
        return res;
    }
};