class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxType, int truckSize) {
        //arrange the vector in decreasing order boxType.second
        //then while trucksize>unit add those values to res
        sort(boxType.begin(),boxType.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]>b[1];
        });
        int res=0;
        for(int i=0;i<boxType.size();i++){
            if(truckSize>boxType[i][0]){
                truckSize-=boxType[i][0];
                res+=boxType[i][0]*boxType[i][1];
            }else{
                res+=boxType[i][1]*truckSize;
                break;
            }
        }
        return res;
    }
};