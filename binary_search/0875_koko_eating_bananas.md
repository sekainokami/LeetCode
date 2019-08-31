### [875\. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

Difficulty: **Medium**


Koko loves to eat bananas.  There are `N` piles of bananas, the `i`-th pile has `piles[i]` bananas.  The guards have gone and will come back in `H` hours.

Koko can decide her bananas-per-hour eating speed of `K`.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than `K` bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer `K` such that she can eat all the bananas within `H` hours.


**Example 1:**

```
Input: piles = [3,6,7,11], H = 8
Output: 4
```


**Example 2:**

```
Input: piles = [30,11,23,4,20], H = 5
Output: 30
```


**Example 3:**

```
Input: piles = [30,11,23,4,20], H = 6
Output: 23
```

**Note:**

*   `1 <= piles.length <= 10^4`
*   `piles.length <= H <= 10^9`
*   `1 <= piles[i] <= 10^9`


#### Solution

Language: **C++**

```c++
class Solution {
public:
    
    int getTime(vector<int>& piles, int r, int H)
    {
        int t = 0;
        for (auto & p : piles)
        {
            // Need to cast int to double before taking the ceil
            t += r >= p ? 1 : ceil(1.0*p/r);
        }
        return t;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int H) {
    
        int left = 1, right = *max_element(piles.begin(),piles.end());
        int res = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int t = getTime(piles,mid,H);
            
            // May eat slower
            if (t <= H)
            {
                res = min(res,mid);
                right = mid - 1;
            }
            // Has to eat faster
            else
                left = mid + 1;
        }
        
        return res;
    }
};
​
​
```
