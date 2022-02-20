// https://www.lintcode.com/problem/779/
class Solution {
public:
    /**
     * @param word: the given word
     * @return: the generalized abbreviations of a word
     */
    void helper(string prev, string next, set<string>& ans){
        if(next.empty()){
            ans.insert(prev);
            return;
        }
        if(prev.size()>0){
            if(prev.back()>='0' && prev.back()<='9'){
                helper(prev+next[0],next.substr(1,next.size()-1), ans);
                return;
            }
        }
        if(next.size()>=1){
            helper(prev+next[0],next.substr(1,next.size()-1), ans);
        }
        for(int i=0;i<next.size();i++){
            ans.insert(prev+to_string(i+1)+next.substr(i+1,next.size()-i));
            helper(prev+to_string(i+1), next.substr(i+1,next.size()-i), ans);
        }
    }
    vector<string> generateAbbreviations(string &word) {
        set<string> ans;
        helper("",word,ans);
        vector<string> retans(ans.begin(),ans.end());
        return retans;
    }
};
