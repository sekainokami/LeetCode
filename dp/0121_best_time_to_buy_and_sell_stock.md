### [121\. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

Difficulty: **Easy**


Say you have an array for which the _i_<sup>th</sup> element is the price of a given stock on day _i_.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

**Example 1:**

```
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
```

**Example 2:**

```
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```


#### Solution

Language: **C++**

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Max profit can make
        int max_prof = 0;
        // Lowest price seen so far
        int lowest = 1<<30;
        
        for (auto & p : prices)
        {
            lowest = min(lowest,p);
            max_prof = max(max_prof,p-lowest);
        }
        return max_prof;
    }
};
```