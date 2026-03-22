class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //90degree  rotation means that make row as column
        //maximum we can do it 3 times only coz at the 4th time it again becomes the original matrix
        vector<vector<int>> rotated_mat(mat.size(),vector<int>(mat.size(),0));
        int c=0;
        while(c<4){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                rotated_mat[j][mat.size()-1-i]=mat[i][j];
            }
        }
        if(rotated_mat==target){
            return true;
        }
        mat=rotated_mat;
        c++;
        }
        return false;
    }

};