class Solution {
public:
    int max_consequitive(vector<int>& bar){
        sort(bar.begin(),bar.end());
        int curr=1;
        int maxval=1;
        for(int i=0;i<bar.size()-1;i++){
            if(bar[i]+1==bar[i+1]){
                curr++;
            }else{
                curr=1;
            }
            maxval=max(curr,maxval);
        }
        return maxval;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h_max=max_consequitive(hBars);
        int v_max=max_consequitive(vBars);
        int min_l=min(h_max,v_max);
        return (min_l+1)*(min_l+1);
    }
};