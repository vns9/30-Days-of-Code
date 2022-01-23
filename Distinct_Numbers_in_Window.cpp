vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int>cnt;
    vector<int> ans;
    for(int i=0;i<B;i++) cnt[A[i]]++;
    ans.push_back(cnt.size());
    for(int i=1;i<=A.size()-B;i++){
        cnt[A[i+B-1]]++;
        cnt[A[i-1]]--;
        if(cnt[A[i-1]]==0) cnt.erase(A[i-1]);
        ans.push_back(cnt.size());
    }
    return ans;
}
