class Solution {
public:
    string reverse_bin(string s){
        int n=s.length();
        string new_s="";
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                new_s+="1";
            }else{
                new_s+="0";
            }
        }
        return new_s;
    }
    char findKthBit(int n, int k) {
        //form the string
        vector<string> bin_list;
        bin_list.push_back("0");
        for(int i=1;i<n;i++){
            string s=bin_list[i-1];
            string r=reverse_bin(s);
            string curr=s+"1"+r;
            bin_list.push_back(curr);
        }
        string res=bin_list[n-1];
        return res[k-1];
    }
};