https://www.lintcode.com/problem/605/
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        map<int,int> cnt;
        vector<bool> pairs;
        if(org.size()>=2) pairs.resize(org.size()-1, false);
        if(seqs.empty()) if(org.size()>0) return false;
        if(org.size()==1){
            bool found=false;
            for(auto seq: seqs){
                for(auto el:seq){
                    if(el!=org.front()) return false;
                    else found=true;
                }
            }
            return found;
        }
        else if(org.empty()){
            bool found=false;
            for(auto seq: seqs){
                if(!seq.empty()) return false;
                else found=true;
            }
            return found;
        }
        for(int i=0;i<org.size();i++) cnt[org[i]]=i;
        for(auto seq: seqs){
            for(int i=0;i<seq.size();i++){
                if(seq[i]<1 || seq[i]>org.size()) return false;
                if(i<seq.size()-1){
                    if(cnt[seq[i]]>cnt[seq[i+1]]) return false;
                    if(cnt[seq[i]]+1==cnt[seq[i+1]]) pairs[cnt[seq[i]]]=true;
                }
            }
        }
        for(auto pair: pairs) if(!pair) return false;
        return true;
    }
};
