### [494\. Target Sum](https://leetcode.com/problems/target-sum/)

Difficulty: **Medium**  

Related Topics: [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)


You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols `+` and `-`. For each integer, you should choose one from `+` and `-` as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

**Example 1:**

```
Input: nums is [1, 1, 1, 1, 1], S is 3\. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
```

**Constraints:**

*   The length of the given array is positive and will not exceed 20.
*   The sum of elements in the given array will not exceed 1000.
*   Your output answer is guaranteed to be fitted in a 32-bit integer.


#### Solution

Language: **C++**

```c++
class Solution {
typedef unordered_map<int,unordered_map<int,int>> Cache;
    
public:
    int solve(int index, int curr, vector<int>& nums, int S, Cache& mem) {
        
        if (mem.count(index) && mem[index].count(curr))
            return mem[index][curr];
        
        if (index == nums.size())
            return curr == S ? 1 : 0;
        
        int positive = solve(index+1,curr+nums[index],nums,S,mem);
        int negative = solve(index+1,curr-nums[index],nums,S,mem);
        int res = positive + negative;
        
        mem[index][curr] = res;
        
        return res;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        Cache mem;
        return solve(0,0,nums,S,mem);
    }
};
```


### Knapsack problem  
Given a list of values and weights, as well as a maximum weight that can be taken, find the maximum value to earn
```c++ 
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef unordered_map<int,unordered_map<int,int>> Cache;


int knapsack(int index, int curr_w, int curr_v, vector<int>& vs, vector<int>& ws, int W, Cache& mem) {
    if (mem.count(index) && mem[index].count(curr_w))
        return mem[index][curr_w];
    if (curr_w > W)
        return -1;
    if (index == vs.size())
        return curr_w <= W ? curr_v : -1;
    int take = knapsack(index+1,curr_w+ws[index],curr_v+vs[index],vs,ws,W,mem);
    int not_take = knapsack(index+1,curr_w,curr_v,vs,ws,W,mem);
    int res = max(take,not_take);
    mem[index][curr_w] = res;
    return res;
}

int main() {
    vector<int> vs = {60,100,120,135};
    vector<int> ws = {10,20,30,5};
    int W = 50;
    Cache mem;
    cout << knapsack(0,0,0,vs,ws,W,mem) << endl;
}
```