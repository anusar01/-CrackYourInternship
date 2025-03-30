class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> alphcount;
        for(char l:s){
            if(alphcount.find(l)==alphcount.end()){
                alphcount[l]=1;
            }
            else{
                alphcount[l]++;
            }
        }
        priority_queue<pair<int,char>> pq;
        string res="";
        for(auto m:alphcount){
            pq.push(make_pair(m.second,m.first));
        }
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res+=top1.second;
            res+=top2.second;
            top1.first--;
            top2.first--;
            if(top2.first>0){pq.push(top2);}
            if(top1.first>0){pq.push(top1);}
        }
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }else{
                res+=pq.top().second;
            }
        }
        return res;
    }
};