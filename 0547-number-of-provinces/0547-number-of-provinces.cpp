class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node]=true;
         for (int neighbour = 0; neighbour < graph.size(); neighbour++) {
            if (graph[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, graph, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int provinces=0;
        vector<bool> visited(v, false);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};
