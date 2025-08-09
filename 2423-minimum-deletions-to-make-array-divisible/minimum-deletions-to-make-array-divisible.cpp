class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int,vector<int>,greater<>> pq;
        for(int n:nums){
            pq.push(n);
        }
        //find hcf of numsDivide
        int res=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            res=gcd(res,numsDivide[i]);
            if(res==1) break;
        }

        
        int count=0;
        
        while(!pq.empty()){
            int curr=pq.top();
            pq.pop();
            if(res%curr==0){
                return count;
            }
            count++;
            //cout<<count<<" ";
        }
        
        return -1;

    }
};