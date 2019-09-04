### [350\. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

Difficulty: **Easy**


Given two arrays, write a function to compute their intersection.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```


**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
```


**Note:**

*   Each element in the result should appear as many times as it shows in both arrays.
*   The result can be in any order.

**Follow up:**

*   What if the given array is already sorted? How would you optimize your algorithm?
*   What if _nums1_'s size is small compared to _nums2_'s size? Which algorithm is better?
*   What if elements of _nums2_ are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> counter;
        vector<int> res;
        
        for (auto & x : nums1)
            counter[x] ++;
        
        for (int i = 0; i < nums2.size(); ++i)
        {
            // If a key existed before, its count != 0
            // even the value == 0
            if (counter.count(nums2[i]) && counter[nums2[i]] != 0)
            {
                counter[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }

        
        return res;
    }
};
```
