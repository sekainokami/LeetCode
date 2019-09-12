### [253\. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

Difficulty: **Medium**


Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (s<sub style="display: inline;">i</sub> < e<sub style="display: inline;">i</sub>), find the minimum number of conference rooms required.

**Example 1:**

```
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
```

**Example 2:**

```
Input: [[7,10],[2,4]]
Output: 1
```

**NOTE:** input types have been changed on April 15, 2019\. Please reset to default code definition to get new method signature.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        // Sort by starting time
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        
        struct Cmp
        {
          bool operator()(vector<int>& a, vector<int>& b)
          {
              return a[1] > b[1];
          }
        };
        
        // Prioritize the finish time
        priority_queue<vector<int>,vector<vector<int>>,Cmp> pq;
        
        for (auto & interval : intervals)
        {
            if (pq.empty())
            {
                pq.push(interval);
            }
            else
            {
                vector<int> top = pq.top();
                if (top[1] <= interval[0])
                    pq.pop();
                pq.push(interval);  
            }
        }
        
        return pq.size();
        
    }
};
```
