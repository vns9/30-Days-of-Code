// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> sched;
    	for(int i=0;i<n;i++){
    	    sched.push_back(make_pair(arr[i],-1));
    	    sched.push_back(make_pair(dep[i],+1));
    	}
    	sort(sched.begin(),sched.end());
    	int ans = INT_MAX; int curr=0;
    	for(auto el: sched){
    	    curr+=el.second;
    	    ans = min(ans,curr);
    	}
    	return -1*ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends