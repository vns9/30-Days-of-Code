#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

bool helper(vector<int>& stall, ll mindis, ll c){
    int currstart=0; int cnt=1;
    for(int i=0;i<stall.size();i++){
        if(stall[i]-stall[currstart]>=mindis){
            cnt++;
            currstart=i;
        }
    }
    if(cnt>=c) return true;
    return false;
}

int main(){
    ll t; cin>>t;
    while(t--){
        ll n,c; cin>>n>>c;
        vector<int> stall(n);
        for(int i=0;i<n;i++) cin>>stall[i];
        sort(stall.begin(),stall.end());
        ll lo=0; ll hi=stall[n-1]-stall[0];
        ll ans=0;
        while(lo<=hi){
            ll mid=(hi+lo)/2;
            if(helper(stall,mid,c)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        cout<<ans<<"\n";
    }
}