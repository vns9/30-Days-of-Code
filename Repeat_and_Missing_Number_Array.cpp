// Alternative math approach - take sum and and take sum of squares (n*n+1*2n+1)/6 and compute
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> B(A.size(),0);
    for(int i=0;i<A.size();i++){
        B[A[i]-1]+=1;
    }
    vector<int> ans(2,-1);
    for(int i=0;i<B.size();i++){
        if(B[i]==2) ans[0]=i+1;
        if(B[i]==0) ans[1]=i+1;
    }
    return ans;
}

