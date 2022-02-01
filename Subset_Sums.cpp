// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        if(N==1) return {0, arr[0]};
        auto prev = subsetSums(arr, N-1);
        int prev_size = prev.size();
        vector<int> curr(prev.begin(),prev.end());
        for(int i=0;i<prev_size;i++){
            curr.push_back(prev[i]+arr[N-1]);
        }
        sort(curr.begin(),curr.end());
        return curr;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends