class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        if(needle.empty()) return 0;
        // KMP Part-1: Construct LPS array of needle
        vector<int> lps(needle.size(),0);
        int prevLPS=0;
        int i=1;
        while(i<needle.size()){
            if(needle[prevLPS]==needle[i]){
                prevLPS++;
                lps[i]+=(prevLPS);
                i++;
            }
            else if(prevLPS==0){
                    lps[i]=0;
                    i++;
            }
            else{
                prevLPS=lps[prevLPS-1];
            }
        }
        // KMP Part-2: Search pattern in string
        int n=0,h=0;
        while(h<haystack.size()){
            if(needle[n]==haystack[h]){
                n++;
                h++;
            }
            else if(n==0){
                h++;
            }
            else{
                n=lps[n-1];
            }
            if(n==needle.length()){
                ans=h-n;
                break;
            }
        }
        return ans;
    }
};
