// https://www.lintcode.com/problem/919/
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n=intervals.size();
        if(n==0 || n==1) return n;
        int minstart, maxend;
        minstart=intervals[0].start;
        maxend=intervals[0].end;
        for(int i=1;i<n;i++){
            minstart=min(minstart, intervals[i].start);
            maxend=max(maxend, intervals[i].end);
        }
        vector<int> v(maxend-minstart+1,0);
        for(int i=0;i<n;i++){
            for(int j=(intervals[i].start);j<=(intervals[i].end);j++){
                v[j-minstart]+=1;
            }
        }
        return *max_element(v.begin(),v.end());
    }
};
