// https://www.lintcode.com/problem/178
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool cycle=false;
    vector<int> visited;
    vector<vector<int>> visited_edges;
    bool validTree(int n, vector<vector<int>> &edges) {
        if(edges.size()==0 && n>1) return false;
        vector<vector<int>> adjl;
        int islands=0;
        for(int i=0;i<n;i++){
            vector<int> v;
            adjl.push_back(v);
            visited.push_back(0);
            vector<int> v1(n,0);
            visited_edges.push_back(v1);
        }
        for(auto edge: edges){
            adjl[edge[1]].push_back(edge[0]);
            adjl[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i, adjl);
                islands++;
            }
        }
        if(cycle || islands!=1) return false;
        return true;
    }
    void dfs(int i, vector<vector<int>> adjl){
        visited[i]=1;
        for(auto neib: adjl[i]){
            if(visited[neib]==1 && visited_edges[i][neib]==0) cycle=true;
            if(visited[neib]==0){
                visited_edges[i][neib]=1;
                visited_edges[neib][i]=1;
                dfs(neib, adjl);
            } 
        }
        visited[i]=2;
    }
};
