class Solution {
public:
    int binaryGap(int n) {
        string binary=bitset<32>(n).to_string();
        int gap=0;
        int start=binary.find('1');
        int prev=-1;
        for(int i=start;i<binary.length();i++){
            if(binary[i]=='1'){
                if(prev!=-1){
                    gap=max(gap,i-prev);
                }            
                prev=i;
            }
        }
        return gap;
    }
};