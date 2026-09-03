/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        // Sort meetings by start time
        sort(intervals.begin(), intervals.end(),
             [](Interval& a, Interval& b) {
                 return a.start < b.start;
             });

        // Min heap: stores when each room becomes free
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& meeting : intervals) {

            // If the earliest available room is free,
            // reuse that room
            if (!pq.empty() && pq.top() <= meeting.start) {
                pq.pop();
            }

            // Allocate room for current meeting
            pq.push(meeting.end);
        }

        return pq.size();
    }
};
