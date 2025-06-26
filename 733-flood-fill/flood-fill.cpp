class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> colorpos;
        int orgCol=image[sr][sc];
        if (orgCol == color) return image;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        colorpos.push({sr,sc});
        image[sr][sc] = color; 
        while(!colorpos.empty()){
            int x=colorpos.front().first,y=colorpos.front().second;
            colorpos.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||ny<0||nx>=image.size()||ny>=image[0].size()||image[nx][ny]!=orgCol){continue;}
                colorpos.push({nx,ny});
                image[nx][ny]=color;
            }
        }
        return image;
    }
};