class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        vector<int> row;
        vector<int> col;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                c+=mat[i][j];
            }
            row.push_back(c);
        }
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c+=mat[j][i];
            }
            col.push_back(c);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};