// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> ratio; 
        double ans=0.0;
        for(int i=0;i<n;i++){
            double rate = (double) arr[i].value/(double) arr[i].weight;
            ratio.push_back(make_pair(rate,arr[i].weight));
        }
        sort(ratio.begin(),ratio.end()); 
        reverse(ratio.begin(),ratio.end());
        int currw=W;
        for(int i=0;i<n;i++){
            if(currw==0) break;
            if(currw>ratio[i].second){
                currw-=ratio[i].second;
                ans+=(ratio[i].first*ratio[i].second);
            }
            else{
                ans+=(ratio[i].first*currw);
                currw=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends