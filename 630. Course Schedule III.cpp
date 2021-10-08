/*

There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.

You will start on the 1st day and you cannot take two or more courses simultaneously.

Return the maximum number of courses that you can take.

 

Example 1:

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
Example 2:

Input: courses = [[1,2]]
Output: 1
Example 3:

Input: courses = [[3,2],[4,3]]
Output: 0
 

Constraints:

1 <= courses.length <= 104
1 <= duration_i, lastDayi <= 104

*/
/*----------------------------------------------------------------
First, sort the courses by their end time d.
For example,

100 200
1000 1250
250 1300
2000 3200
Then, for 1<=k<=n, try to find how many courses with index no larger than k can we take:

k=1: 100
k=2: 100/1000, the total time cost is 1100
k=3: 100/1000/250, the total time cost is 1350, which is larger than 1300, so we must remove a course from them to make it valid. We can remove any one, but remove 1000 would be better. Because the total time cost (350) would be smaller after this remove.
k=4: 100/250/2000, so the answer is 3.
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& p, auto& q) {return p[1] < q[1];});
        priority_queue<int> q;
        int sum = 0;
        for (auto& c : courses) {
            q.push(c[0]);
            sum += c[0];
            if (sum > c[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};
