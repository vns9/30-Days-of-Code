// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int helper(int i, int j, vector<pair<int,int>>& matrices, vector<vector<int>>& dp){
        if(dp[i][j]==-1){
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int currop = (matrices[i].first)*(matrices[k].second)*(matrices[j].second);
                dp[i][j]=min(dp[i][j], helper(i,k,matrices,dp)+helper(k+1,j,matrices,dp)+currop);
            }
            
        }
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<pair<int,int>> matrices;
        for(int i=0;i<N-1;i++){
            matrices.push_back(make_pair(arr[i],arr[i+1]));
        }
        vector<vector<int>> dp(N-1, vector<int>(N-1,-1));
        for(int i=0;i<N-1;i++) dp[i][i]=0;
        return helper(0,N-2,matrices,dp);
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends