/*
Proof a XOR b = c, then a XOR c = b

a xor b = c
(a xor b) xor a = c xor a
(a xor a) xor b = c xor a
0 xor b = c xor a
b = c xor a

XOR operator ⊕ is both commutative and associative.
*/
int Solution::solve(vector<int> &A, int B) {
    int ans=0; int currxor=0; unordered_map<int,int> hashmap;
    for(int i=0;i<A.size();i++){
        currxor = currxor ^ A[i];
        if(currxor==B) ans++;
        ans+=hashmap[B ^ currxor];
        hashmap[currxor]+=1;
    }
    return ans;
}