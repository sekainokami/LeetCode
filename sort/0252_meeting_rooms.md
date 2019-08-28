### [252\. Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)

Difficulty: **Easy**


Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (s<sub style="display: inline;">i</sub> < e<sub style="display: inline;">i</sub>), determine if a person could attend all meetings.

**Example 1:**

```
Input: [[0,30],[5,10],[15,20]]
Output: false
```

**Example 2:**

```
Input: [[7,10],[2,4]]
Output: true
```

**NOTE:** input types have been changed on April 15, 2019\. Please reset to default code definition to get new method signature.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
             [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < intervals[i-1][1])
                return false;
        }
        
        return true;
    }
};
```
