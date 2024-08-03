class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(depthfirstsearch(board,word,row,col,0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool depthfirstsearch(vector<vector<char>>& board,const string& word, int row,int col,int index){
        if(index==word.size()){
            return true;
        }
        if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col]!=word[index]){
            return false;
        }
        char temp=board[row][col];
        board[row][col]='*';

        //top down right left
        vector<pair<int,int>> offsets={{-1,0},{1,0},{0,1},{0,-1}};
        for(auto offset:offsets){
            int newrow=row+offset.first;
            int newcol=col+offset.second;
            if(depthfirstsearch(board,word,newrow,newcol,index+1)){
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
};