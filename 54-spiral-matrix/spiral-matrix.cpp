class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int rownum=matrix.size();
        int colnum=matrix[0].size();//null case badme consider kriyo
        int row=0;
        int col=-1;
        int direction=1;

        while(rownum>0 & colnum>0){
            for(int i=0;i<colnum;i++){
                col+=direction;
                output.push_back(matrix[row][col]);
            }
            rownum--;
            for(int i=0;i<rownum;i++){
                row+=direction;
                output.push_back(matrix[row][col]);
            }
            colnum--;

            direction*=-1;
        }
        return output;    
    }
};