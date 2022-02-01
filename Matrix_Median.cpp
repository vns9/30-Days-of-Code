int Solution::findMedian(vector<vector<int> > &A) {
    int lo=INT_MAX; int hi=INT_MIN;
    int rows = A.size(); int cols = A[0].size();
    for(int i=0;i<rows;i++){
        lo=min(lo,A[i][0]);
        hi=max(hi,A[i][cols-1]);
    }
    int mid;
    while(lo<hi){
        mid = lo + (hi-lo)/2;
        int lesscnt=0;
        for(int i=0;i<rows;i++){
            lesscnt+=(upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(lesscnt<(((rows*cols)+1)/2)){
            lo=mid+1;
        }
        else hi=mid;
    }
    return lo;
}
