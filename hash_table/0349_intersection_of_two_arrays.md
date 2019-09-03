### [349\. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

Difficulty: **Easy**


Given two arrays, write a function to compute their intersection.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```


**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```


**Note:**

*   Each element in the result must be unique.
*   The result can be in any order.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1(nums1.begin(),nums1.end());
        unordered_set<int> us2(nums2.begin(),nums2.end());
        vector<int> res;
        
        for (auto & p: us1)
        {
            if (us2.count(p))
                res.push_back(p);
        }
        
        return res;
    }
};
```
