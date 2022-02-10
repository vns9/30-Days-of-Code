// https://www.lintcode.com/problem/920/description
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
     * @return: if a person could attend all meetings
     */
    static bool sortFunc( const Interval& p1, const Interval& p2 ) {
        return (p1.start < p2.start || (p1.start == p2.start && p1.end < p2.end));
    }
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), sortFunc);
        int n = intervals.size();
        bool cant=false;
        for(int i=0;i<n-1;i++){
            if((intervals[i].end)>(intervals[i+1].start)){
                cant=true;
                break;
            }
        }
        return !cant;
        // Write your code here
    }
};
