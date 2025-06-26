class Solution {
public:
    void dfs(int node,vector<bool> &visited,unordered_map<int,vector<int>> &adj){
        visited[node]=true;
        for(int neigh: adj[node]){
            if(!visited[neigh]){
                dfs(neigh,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(j!=i){
                    if(isConnected[i][j]==1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int prov=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                prov++;
                dfs(i,visited,adj);
            }
        }
        return prov;
    }
};