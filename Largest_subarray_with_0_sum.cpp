// Even better approach - store only first occurence i.e. map<int,int> is just enough

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int currs=0; map<int,vector<int>> sumi; 
        sumi[0].push_back(-1);
        for(int i=0;i<n;i++){
            currs+=A[i];
            sumi[currs].push_back(i);
        }
        int ans=0;
        for(auto kv: sumi){
            int maxel=*max_element(kv.second.begin(), kv.second.end());
            int minel=*min_element(kv.second.begin(), kv.second.end());
            ans=max(ans, maxel-minel);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends