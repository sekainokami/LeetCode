### [977\. Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

Difficulty: **Easy**


Given an array of integers `A` sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.


**Example 1:**

```
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
```


**Example 2:**

```
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

**<span style="display: inline;">Note:</span>**

1.  `<span style="display: inline;">1 <= A.length <= 10000</span>`
2.  `-10000 <= A[i] <= 10000`
3.  `A` is sorted in non-decreasing order.


#### Solution

Language: **C++**

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        transform(A.begin(),A.end(),A.begin(),[](int& x){return x*x;});
        sort(A.begin(),A.end());
        return A;
    }
};
```
