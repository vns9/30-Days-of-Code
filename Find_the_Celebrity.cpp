// https://www.youtube.com/watch?v=LZJBZEnoYLQ (Optimal approach)

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        // Write your code here
        vector<int> celeb(n,-1);
        for(int i=0;i<n;i++){
            bool check=false;
            for(int j=0;j<n;j++){
                if(j!=i){
                    if(knows(i,j)){
                        celeb[i]=0; break; check=true;
                    }
                }
            }
            if(!check) celeb[i]=1;
        }
        for(int i=0;i<n;i++){
            if(celeb[i]==1){
                for(int j=0;j<n;j++){
                    if(j!=i){
                        if(!knows(j,i)||knows(i,j)){
                            celeb[i]=0; break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(celeb[i]==1) return i;
        }
        return -1;
    }
};