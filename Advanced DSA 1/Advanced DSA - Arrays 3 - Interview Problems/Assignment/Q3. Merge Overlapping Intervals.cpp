/*
Problem Description
Given a collection of intervals, merge all overlapping intervals.



Problem Constraints
1 <= Total number of intervals <= 100000.



Input Format
First argument is a list of intervals.



Output Format
Return the sorted list of intervals after merging all the overlapping intervals.



Example Input
Input 1:

[1,3],[2,6],[8,10],[15,18]


Example Output
Output 1:

[1,6],[8,10],[15,18]


Example Explanation
Explanation 1:

Merge intervals [1,3] and [2,6] -> [1,6].
so, the required answer after merging is [1,6],[8,10],[15,18].
No more overlapping intervals present.


*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), 
    [](Interval i1, Interval i2) -> bool 
     {
         return i1.start < i2.start;
     });

    vector<Interval> res;
    Interval newInterval = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (newInterval.end < A[i].start) {
            res.push_back(newInterval);
            newInterval = A[i];
        }
        else if (newInterval.end >= A[i].start || newInterval.start >= A[i].end) {
            newInterval.start = min(newInterval.start, A[i].start);
            newInterval.end = max(newInterval.end, A[i].end);
        }
    }
    res.push_back(newInterval);
    return res;
}
