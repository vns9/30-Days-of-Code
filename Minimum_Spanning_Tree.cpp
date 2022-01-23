//KRUSKAL
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //cout<<adj->size();
        vector<int>treeno(V,0); int ans=0; int compcnt=0;
        vector<pair<int,int>>edgeends; priority_queue<pair<int,int>>pq;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                edgeends.push_back(make_pair(i,adj[i][j][0]));
                pq.push(make_pair(-1*adj[i][j][1],edgeends.size()-1));
            }
        }
        //cout<<pq.size()<<endl;
        while(!pq.empty()){
            auto var = pq.top(); pq.pop();
            int curredge = -1*var.first;
            int v1 = edgeends[var.second].first;
            int v2 = edgeends[var.second].second;
            if(treeno[v1]==0&&treeno[v2]==0){
                compcnt+=1;
                treeno[v1]=compcnt; treeno[v2]=compcnt; ans+=curredge;
            }
            else if(treeno[v1]==0&&treeno[v2]!=0){
                treeno[v1]=treeno[v2]; ans+=curredge;
            }
            else if(treeno[v1]!=0&&treeno[v2]==0){
                treeno[v2]=treeno[v1]; ans+=curredge;
            }
            else if(treeno[v1]!=0&&treeno[v2]!=0&&treeno[v2]!=treeno[v1]){
                int frcmp=treeno[v1]; int tocmp=treeno[v2];
                for(int i=0;i<V;i++){
                    if(treeno[i]==frcmp) treeno[i]=tocmp;
                }
                ans+=curredge;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends