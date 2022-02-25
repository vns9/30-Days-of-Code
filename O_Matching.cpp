// https://atcoder.jp/contests/dp/tasks/dp_o
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
ll modn = 1e9+7;

//BINPOW - Optimal Binary exponentiation 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//Fast Odd/Even check
bool isEven(int n){
    return (!(n & 1));
}
/*
int helper(ll male, ll femaleind, ll n, vector<vector<ll>>& comp){
    if(femaleind==n && male==((1<<n)-1)) return 1;
    if(dp.find({male,femaleind})!=dp.end()) return dp[{male,femaleind}];
    int ans=0;
    for(int i=0;i<n;i++){
        if((male&(1<<i))==0){
            if(comp[i][femaleind]==1){
                male=(male)|(1<<i);
                ans+=helper(male,femaleind+1,n,comp);
                ans=ans%modn;
                male=male&(~(1<<i));
            }
        }
    }
    dp[{male,femaleind}] = ans;
    return ans;
}*/
int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> comp(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>comp[i][j];
        }
    }
    vector<vector<ll>> table(1<<n, vector<ll>(n, 0));
	for(int j=0; j<n; j++){
		if(comp[j][0]) table[(1<<j)][0]=1;
    } 
    for(ll female=0;female<n;female++){
        for(ll mask=0;mask<(1<<n);mask++){
                if(__builtin_popcountll(mask)==female){
                    for(int i=0;i<n;i++){
                    if((mask&(1<<i))==0){
                        if(comp[i][female]==1){
                            if(female==0) table[mask][female]+=1;
                            else {
                                ll man = (mask)|(1<<i);
                                table[man][female]+=table[mask][female-1];
                                table[man][female]=table[man][female]%modn;   
                            }
                        }
                    }
                }
            }    
        }
    }   
    cout<<table[(1<<n)-1][n-1];
    return 0;
}
