class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> wordcount;
        vector<string> result;
        stringstream ss(s1+" "+s2);
        string words;
        while(ss>>words){
            wordcount[words]++;
        }
        for(auto& entry:wordcount){
            if(entry.second==1){
                result.push_back(entry.first);
            }
        }
        return result;
        
    }
};