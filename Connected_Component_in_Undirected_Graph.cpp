// https://www.lintcode.com/problem/431/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /**
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    void dfs(UndirectedGraphNode* curr, set<int>& visited, vector<vector<int>>& ans, vector<UndirectedGraphNode*>& nodes){
        visited.insert(curr->label);
        ans[ans.size()-1].push_back(curr->label);
        for(int j=0;j<((curr->neighbors).size());j++){
            if(visited.find(curr->neighbors[j]->label)==visited.end()){
                dfs(curr->neighbors[j], visited, ans, nodes);
            }
        }
    }
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        set<int> visited;
        vector<vector<int>> ans;
        for(int i=0;i<nodes.size();i++){
            if(visited.find(nodes[i]->label)==visited.end()){
                ans.push_back({});
                dfs(nodes[i], visited, ans, nodes);
            }
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
