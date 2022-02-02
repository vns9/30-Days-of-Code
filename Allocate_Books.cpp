int Solution::books(vector<int> &A, int B) {
    int lo=INT_MAX,hi=0; 
    for(auto el: A){
        hi+=el;
        lo=min(lo,el);
    }
    int ans= INT_MAX;
    while(lo<=hi){
        if(B>A.size()){
            // students > the total books case impossible
            ans=-1; break;
        }
        int mid=(hi+lo)/2;
        int currpages=0; 
        int cnt=0; 
        bool check = true;
        for(int i=0;i<A.size();i++){
            if(i==A.size()-1){
                // last book case is different
                if(currpages+A[i]>mid){
                    cnt++; 
                    currpages=A[i];
                    if(currpages > mid) check = false;
                    else cnt++; 
                }
                else{
                    cnt++;
                }
            }
            else{
                if(currpages+A[i]>mid){
                    cnt++; 
                    currpages=A[i];
                    // if there is a book with page count more than mid
                    if(currpages > mid) check = false; 
                }
                else{
                    currpages+=A[i];
                }
            }
        }
        if(cnt>B) check=false;
        if(check){
            ans=min(ans, mid);
            hi=mid-1;
        }
        else lo=mid+1;
    }
    // in case nothing is found return -1
    if(ans==INT_MAX) return -1;
    return ans;
}
