### [849\. Maximize Distance to Closest Person](https://leetcode.com/problems/maximize-distance-to-closest-person/)

Difficulty: **Easy**


In a row of `seats`, `1` represents a person sitting in that seat, and `0` represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.


**Example 1:**

```
Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
```


**Example 2:**

```
Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
```

**Note:**

1.  `1 <= seats.length <= 20000`
2.  `seats` contains only 0s or 1s, at least one `0`, and at least one `1`.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size(), ret = 0;
        vector<int> left(n,n);
        vector<int> right(n,n);
        
        for (int i = 0; i < n; ++i)
        {
            if (seats[i] == 1)
                left[i] = 0;
            else if (i > 0)
                left[i] = left[i-1]+1;
        }
        
        for (int i = n-1; i >= 0; --i)
        {
            if (seats[i] == 1)
                right[i] = 0;
            else if (i < n - 1)
            {
                right[i] = right[i+1]+1;
            }
        }
​
        for (int i = 0; i < n; ++i)
        {
            if (seats[i] == 0)
                ret = max(ret,min(left[i],right[i]));
        }
        
        return ret;
    }
};
```
