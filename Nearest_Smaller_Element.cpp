// Optimal solution in O(n) space and time
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> sta;
    vector<int> ans(A.size());
    for(int i=0;i<A.size();i++){
        while(1){
            if(sta.empty()){
                ans[i]=-1;
                sta.push(A[i]);
                break;
            }
            else if(sta.top()<A[i]){
                ans[i]=sta.top(); 
                sta.push(A[i]);
                break;
            }
            else if(sta.top()>=A[i]){
                sta.pop();
            }
        }
    }
    return ans;
}
