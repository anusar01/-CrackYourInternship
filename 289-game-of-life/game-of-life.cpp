class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> copy(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count1=0;
                if((i-1)>=0){
                    if((j-1)>=0){
                        if(board[i-1][j-1]==1){
                            count1++;
                        }
                    }
                    if(board[i-1][j]==1){
                        count1++;
                    }
                    if((j+1)<m){
                        if(board[i-1][j+1]==1){
                            count1++;
                        }
                    }
                }
                if((j-1)>=0){
                    if(board[i][j-1]==1){
                        count1++;
                    }
                }
                if((j+1)<m){
                    if(board[i][j+1]==1){
                        count1++;
                    }
                }
                if((i+1)<n){
                    if((j-1)>=0){
                        if(board[i+1][j-1]==1){
                            count1++;
                        }
                    }
                    if(board[i+1][j]==1){
                        count1++;
                    }
                    if((j+1)<m){
                        if(board[i+1][j+1]==1){
                            count1++;
                        }
                    }
                }
                if(board[i][j]==0){
                    if(count1==3){
                        copy[i][j]=1;
                    }else{
                        copy[i][j]=0;
                    }
                }
                if(board[i][j]==1){
                    if(count1==3 || count1==2){
                        copy[i][j]=1;
                    }else{
                        copy[i][j]=0;
                    }
                }

            }
        }
        //now board==copy
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=copy[i][j];
            }
        }
    }
};