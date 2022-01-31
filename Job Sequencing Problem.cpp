// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>> sched;
        int maxdeadline=-1;
        for(int i=0;i<n;i++){
            sched.push_back(make_pair(arr[i].profit,arr[i].dead));
            maxdeadline=max(maxdeadline, arr[i].dead);
        }
        vector<int> ans(maxdeadline, -1);
        sort(sched.begin(),sched.end());
        reverse(sched.begin(),sched.end());
        for(int i=0;i<n;i++){
            int start = sched[i].second;
            for(int j=start-1;j>=0;j--){
                if(ans[j]<sched[i].first){
                    ans[j]=sched[i].first;
                    break;
                }
            }
        }
        int jobcnt=0, maxprof=0;
        for(auto el: ans){
            if(el!=-1){
                jobcnt++; maxprof+=el;
            }
        }
        return {jobcnt,maxprof};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends